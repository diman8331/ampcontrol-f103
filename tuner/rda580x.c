#include "rda580x.h"

#include "rda580x_regs.h"
#include "../i2c.h"
#include "../pins.h"

#define RDA5807M_I2C_SEQ_ADDR       0x20
#define RDA5807M_I2C_RAND_ADDR      0x22

#define RDA5807_WRBUF_SIZE          14
#define RDA5807_RDBUF_SIZE          12

static uint8_t wrBuf[RDA5807_WRBUF_SIZE];
static uint8_t rdBuf[RDA5807_RDBUF_SIZE];

static TunerParam *tPar;

static void rda580xWriteReg(uint8_t reg)
{
    uint8_t *wrAddr = &wrBuf[2 * reg - 4];

    i2cBegin(I2C_AMP, RDA5807M_I2C_RAND_ADDR);
    i2cSend(I2C_AMP, reg);
    i2cSend(I2C_AMP, *wrAddr++);
    i2cSend(I2C_AMP, *wrAddr++);
    i2cTransmit(I2C_AMP, true);
}

static void rda580xSetBit(uint8_t idx, uint8_t bit, uint8_t cond)
{
    if (cond) {
        wrBuf[idx] |= bit;
    } else {
        wrBuf[idx] &= ~bit;
    }

    rda580xWriteReg(idx / 2 + 2);
}

static void rda580xInitRegs(void)
{
    wrBuf[0] = RDA580X_DHIZ;
    if (tPar->flags & TUNER_FLAG_BASS)
        wrBuf[0] |= RDA5807_BASS;
    if (tPar->flags & TUNER_FLAG_MONO)
        wrBuf[0] |= RDA580X_MONO;
    wrBuf[1] = RDA580X_SKMODE | RDA580X_CLK_MODE_32768;
    if (tPar->flags & TUNER_FLAG_RDS)
        wrBuf[1] |= RDA5807_RDS_EN;
    rda580xWriteReg(0x02);

    wrBuf[2] = 0x00;
    wrBuf[3] = 0x00;
    switch (tPar->band) {
    case TUNER_BAND_FM_JAPAN:
        wrBuf[3] |= RDA580X_BAND_JAPAN;
        tPar->fMin = 7600;
        tPar->fMax = 9100;
        break;
    case TUNER_BAND_FM_WORLDWIDE:
        wrBuf[3] |= RDA580X_BAND_WORLDWIDE;
        tPar->fMin = 7600;
        tPar->fMax = 10800;
        break;
    case TUNER_BAND_FM_EASTEUROPE:
        wrBuf[3] |= RDA580X_BAND_EASTEUROPE;
        tPar->fMin = 6500;
        tPar->fMax = 7600;
        break;
    default:
        wrBuf[3] |= RDA580X_BAND_US_EUROPE;
        tPar->fMin = 8700;
        tPar->fMax = 10800;
        break;
    }
    switch (tPar->step) {
    case TUNER_STEP_50K:
        wrBuf[3] |= RDA580X_SPACE_50;
        tPar->fStep = 5;
        break;
    case TUNER_STEP_200K:
        wrBuf[3] |= RDA580X_SPACE_200;
        tPar->fStep = 20;
        break;
    default:
        wrBuf[3] |= RDA580X_SPACE_100;
        tPar->fStep = 10;
        break;
    }
    rda580xWriteReg(0x03);

    wrBuf[4] = RDA580X_SOFTMUTE_EN;
    if (tPar->deemph != TUNER_DEEMPH_75u)
        wrBuf[4] |= RDA580X_DE;
    wrBuf[5] |= RDA580X_GPIO3_ST_IND;
    rda580xWriteReg(0x04);

    wrBuf[6] = 0x08; // TODO: handle seek threshold
    wrBuf[7] = RDA580X_LNA_PORT_SEL_LNAP;
    wrBuf[7] |= tPar->volume;
    rda580xWriteReg(0x05);

    // Nothing do with register 06 for now

    wrBuf[10] = RDA5807_TH_SOFRBLEND_DEF | RDA5807_65M_50M_MODE;
    wrBuf[11] = RDA5807_SEEK_TH_OLD_DEF | RDA5807_SOFTBLEND_EN; // TODO: handle softblend
    rda580xWriteReg(0x07);
}

void rda580xInit(TunerParam *param)
{
    tPar = param;

    rda580xInitRegs();
}

void rda580xSetFreq(uint16_t value)
{
    uint16_t chan = (value - tPar->fMin) / tPar->fStep;

    wrBuf[2] = (chan >> 2) & RDA580X_CHAN_9_2;
    wrBuf[3] &= ~RDA580X_CHAN_1_0;
    wrBuf[3] |= (chan << 6) & RDA580X_CHAN_1_0;

    wrBuf[3] |= RDA580X_TUNE;
    rda580xWriteReg(0x03);
    wrBuf[3] &= ~RDA580X_TUNE;
}

void rda580xSeek(int8_t direction)
{
    wrBuf[0] |= RDA580X_SEEK;
    rda580xSetBit(0, RDA580X_SEEKUP, direction > 0);
    wrBuf[0] &= ~RDA580X_SEEK;
}

void rda580xSetVolume(int8_t value)
{
    if (value < RDA580X_VOL_MIN)
        value = RDA580X_VOL_MIN;
    if (value > RDA580X_VOL_MAX)
        value = RDA580X_VOL_MAX;

    wrBuf[7] &= ~RDA580X_VOLUME;
    wrBuf[7] |= value;

    rda580xWriteReg(0x05);
}

void rda580xSetMute(bool value)
{
    rda580xSetBit(0, RDA580X_DMUTE, !value);
}

void rda580xSetBassBoost(bool value)
{
    rda580xSetBit(0, RDA5807_BASS, value);
}

void rda580xSetForcedMono(bool value)
{
    rda580xSetBit(0, RDA580X_MONO, value);
}

void rda580xSetRds(bool value)
{
    rda580xSetBit(1, RDA5807_RDS_EN, value);
}

void rda580xSetPower(bool value)
{
    rda580xSetBit(1, RDA580X_ENABLE, value);
}

void rda580xUpdateStatus()
{
    i2cBegin(I2C_AMP, RDA5807M_I2C_SEQ_ADDR);
    i2cReceive(I2C_AMP, rdBuf, RDA5807_RDBUF_SIZE);
}

uint16_t rda580xGetFreq(void)
{
    uint16_t chan = rdBuf[0] & RDA580X_READCHAN_9_8;
    chan <<= 8;
    chan |= rdBuf[1];

    return chan * tPar->fStep + tPar->fMin;
}
