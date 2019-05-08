#include "labels.h"

const char *const labels_tr[LABEL_END] = {
    [LABEL_SUNDAY]          = "PAZAR",
    [LABEL_MONDAY]          = "PAZARTESİ",
    [LABEL_TUESDAY]         = "SALI",
    [LABEL_WEDNESDAY]       = "ÇARŞAMBA",
    [LABEL_THURSDAY]        = "PERŞEMBE",
    [LABEL_FRIDAY]          = "CUMA",
    [LABEL_SATURDAY]        = "CUMARTESİ",

    [LABEL_VOLUME]          = "Volum",
    [LABEL_BASS]            = "Bass",
    [LABEL_MIDDLE]          = "Orta Ses",
    [LABEL_TREBLE]          = "Tiz",
    [LABEL_FRONTREAR]       = "Ön/Arka Denge",
    [LABEL_BALANCE]         = "Sağ/Sol Denge",
    [LABEL_CENTER]          = "Merkez",
//    [LABEL_SUBWOOFER]       = "Subwoofer",
    [LABEL_PREAMP]          = "Kazanç",

    [LABEL_IN_TUNER]        = "Radio",
    [LABEL_IN_PC]           = "Bilgisayar",
    [LABEL_IN_TV]           = "TV Seti",
//    [LABEL_IN_BLUETOOTH]    = "Bluetooth",
    [LABEL_IN_DVD]          = "DVD Seti",
//    [LABEL_IN_USB]          = "USB",
    [LABEL_IN_MICROPHONE]   = "Mikrofon",
    [LABEL_IN_GUITAR]       = "Gitar",
    [LABEL_IN_TURNTABLES]   = "Plak Çalar",
    [LABEL_IN_CASSETTE]     = "Kaset Çalar",
    [LABEL_IN_PROJECTOR]    = "Projeksiyon",
    [LABEL_IN_SATELLITE]    = "Uydu Alıcısı",
    [LABEL_IN_MIXER]        = "Mikser",

    [LABEL_BOOL_OFF]        = "Kapalı",
    [LABEL_BOOL_ON]         = "Açık",

    [LABEL_TUNER_FM_STATION_NAME]   = "FM Radyo İsimleri:",

    [LABEL_TUNER_IC + TUNER_IC_NO]      = "Yok",
//    [LABEL_TUNER_IC + TUNER_IC_RDA5807] = "RDA5807",
//    [LABEL_TUNER_IC + TUNER_IC_SI4703]  = "Si4703",
//    [LABEL_TUNER_IC + TUNER_IC_TEA5767] = "TEA5767",
//    [LABEL_TUNER_IC + TUNER_IC_TEST]    = "TEST",

    [LABEL_TUNER_BAND + TUNER_BAND_FM_US_EUROPE]    = "ABD/Avrupa FM",
//    [LABEL_TUNER_BAND + TUNER_BAND_FM_JAPAN]        = "Japan FM",
    [LABEL_TUNER_BAND + TUNER_BAND_FM_WORLDWIDE]    = "Dünya Çapında FM",
    [LABEL_TUNER_BAND + TUNER_BAND_FM_EASTEUROPE]   = "Doğu Avrupa FM",

//    [LABEL_TUNER_STEP + TUNER_STEP_50K]     = "50kHz",
//    [LABEL_TUNER_STEP + TUNER_STEP_100K]    = "100kHz",
//    [LABEL_TUNER_STEP + TUNER_STEP_200K]    = "200kHz",

//    [LABEL_TUNER_DEEMPH + TUNER_DEEMPH_50u] = "50us",
//    [LABEL_TUNER_DEEMPH + TUNER_DEEMPH_75u] = "75us",

    [LABEL_TUNER_MODE + TUNER_MODE_GRID]        = "Izgara",
    [LABEL_TUNER_MODE + TUNER_MODE_STATIONS]    = "İstasyonlar",
    [LABEL_TUNER_MODE + TUNER_MODE_SCAN]        = "Tarama",

    [LABEL_SPECTRUM_MODE + SP_MODE_STEREO]      = "Stereo",
    [LABEL_SPECTRUM_MODE + SP_MODE_MIXED]       = "Karışık",
    [LABEL_SPECTRUM_MODE + SP_MODE_WATERFALL]   = "Şelale",

    [LABEL_AUDIO_IC + AUDIO_IC_NO]      = "Yok",
//    [LABEL_AUDIO_IC + AUDIO_IC_TDA7439] = "TDA7439",
//    [LABEL_AUDIO_IC + AUDIO_IC_TDA7313] = "TDA7313",
//    [LABEL_AUDIO_IC + AUDIO_IC_PT232X]  = "PT232x",
//    [LABEL_AUDIO_IC + AUDIO_IC_TDA7418] = "TDA7418",
//    [LABEL_AUDIO_IC + AUDIO_IC_TEST]    = "TEST",

//    [LABEL_LANG + LANG_DEFAULT]         = "English",
//    [LABEL_LANG + LANG_BY]              = "Беларуская",
//    [LABEL_LANG + LANG_RU]              = "Русский",
//    [LABEL_LANG + LANG_TR]              = "Türkçe",
//    [LABEL_LANG + LANG_UA]              = "Українська",

//    [LABEL_ALARM_DAY + ALARM_DAY_OFF]       = "Off",
//    [LABEL_ALARM_DAY + ALARM_DAY_WEEKDAYS]  = "Weekdays",
//    [LABEL_ALARM_DAY + ALARM_DAY_ALL_DAYS]  = "ALl days",

    // NOTE: Keep in sync with MenuIdx in menu.h
    [LABEL_MENU + MENU_NULL]            = "Bir Önceki Menü",

    [LABEL_MENU + MENU_SETUP]           = "Menü Ayarları",

    [LABEL_MENU + MENU_SETUP_SYSTEM]    = "Sistem",
    [LABEL_MENU + MENU_SETUP_AUDIO]     = "Ses İşlemcisi",
    [LABEL_MENU + MENU_SETUP_TUNER]     = "Radyo İşlemcisi",
    [LABEL_MENU + MENU_SETUP_SPECTRUM]  = "Spectrum Ayarı",
    [LABEL_MENU + MENU_SETUP_DISPLAY]   = "Ekran Ayarı",
//    [LABEL_MENU + MENU_SETUP_ALARM]     = "Alarm",
    [LABEL_MENU + MENU_SETUP_RC]        = "Kumanda Ayarı",

    [LABEL_MENU + MENU_SYSTEM_LANG]     = "Dil Seçeneği",
    [LABEL_MENU + MENU_SYSTEM_MUTESTBY] = "Mute/Bekletme Pini",
    [LABEL_MENU + MENU_SYSTEM_ENC_RES]  = "Enkoder Çözünürlüğü",
    [LABEL_MENU + MENU_SYSTEM_SIL_TIM]  = "Sessizlik Zamanlayıcısı",
//    [LABEL_MENU + MENU_SYSTEM_RTC_CORR] = "Time correction",

    [LABEL_MENU + MENU_AUDIO_IC]        = "Ses İşlemci Modeli",
    [LABEL_MENU + MENU_AUDIO_IN_0]      = "Ses Giriş 0",
    [LABEL_MENU + MENU_AUDIO_IN_1]      = "Ses Giriş 1",
    [LABEL_MENU + MENU_AUDIO_IN_2]      = "Ses Giriş 2",
    [LABEL_MENU + MENU_AUDIO_IN_3]      = "Ses Giriş 3",
    [LABEL_MENU + MENU_AUDIO_IN_4]      = "Ses Giriş 4",
    [LABEL_MENU + MENU_AUDIO_IN_5]      = "Ses Giriş 5",
    [LABEL_MENU + MENU_AUDIO_IN_6]      = "Ses Giriş 6",
    [LABEL_MENU + MENU_AUDIO_IN_7]      = "Ses Giriş 7",

    [LABEL_MENU + MENU_TUNER_IC]        = "Tuner İşlemci Modeli",
    [LABEL_MENU + MENU_TUNER_BAND]      = "Bant Modeli",
    [LABEL_MENU + MENU_TUNER_STEP]      = "Tarama Adımı",
    [LABEL_MENU + MENU_TUNER_DEEMPH]    = "Vurgulama",
    [LABEL_MENU + MENU_TUNER_MODE]      = "Kontrol modu",
    [LABEL_MENU + MENU_TUNER_FMONO]     = "Mono Ses",
    [LABEL_MENU + MENU_TUNER_RDS]       = "Rds Bilgi Gösterimi",
    [LABEL_MENU + MENU_TUNER_BASS]      = "Bass Kuvetlendirme",
    [LABEL_MENU + MENU_TUNER_VOLUME]    = "Tuner Ses Ayarı",

//    [LABEL_MENU + MENU_ALARM_HOUR]      = "Hour",
//    [LABEL_MENU + MENU_ALARM_MINUTE]    = "Minute",
//    [LABEL_MENU + MENU_ALARM_DAYS]      = "Days",

    [LABEL_MENU + MENU_SPECTURM_MODE]   = "Spectrum Tipi",

    [LABEL_MENU + MENU_DISPLAY_BR_STBY] = "Bekleme Parlaklığı",
    [LABEL_MENU + MENU_DISPLAY_BR_WORK] = "Parlaklık",
    [LABEL_MENU + MENU_DISPLAY_ROTATE]  = "Döndürme",

    // NOTE: Keep in sync with cmd.h define list
    [LABEL_MENU + MENU_RC_STBY_SWITCH]  = "Bekleme Butonu",
    [LABEL_MENU + MENU_RC_MUTE]         = "Mute",
    [LABEL_MENU + MENU_RC_VOL_UP]       = "Volum Artı",
    [LABEL_MENU + MENU_RC_VOL_DOWN]     = "Volum Eksi",
    [LABEL_MENU + MENU_RC_MENU]         = "Menü",
    [LABEL_MENU + MENU_RC_CHAN_NEXT]    = "Sornaki Kanal",
    [LABEL_MENU + MENU_RC_CHAN_PREV]    = "Önceki Kanal",
    [LABEL_MENU + MENU_RC_DIG_0]        = "Buton 0",
    [LABEL_MENU + MENU_RC_DIG_1]        = "Buton 1",
    [LABEL_MENU + MENU_RC_DIG_2]        = "Buton 2",
    [LABEL_MENU + MENU_RC_DIG_3]        = "Buton 3",
    [LABEL_MENU + MENU_RC_DIG_4]        = "Buton 4",
    [LABEL_MENU + MENU_RC_DIG_5]        = "Buton 5",
    [LABEL_MENU + MENU_RC_DIG_6]        = "Buton 6",
    [LABEL_MENU + MENU_RC_DIG_7]        = "Buton 7",
    [LABEL_MENU + MENU_RC_DIG_8]        = "Buton 8",
    [LABEL_MENU + MENU_RC_DIG_9]        = "Buton 9",
    [LABEL_MENU + MENU_RC_IN_NEXT]      = "Sonraki Giriş",
    [LABEL_MENU + MENU_RC_NAV_OK]       = "Tamam",
    [LABEL_MENU + MENU_RC_NAV_BACK]     = "Geri",
    [LABEL_MENU + MENU_RC_NAV_RIGHT]    = "Sağ",
    [LABEL_MENU + MENU_RC_NAV_UP]       = "Yukarı",
    [LABEL_MENU + MENU_RC_NAV_LEFT]     = "Sol",
    [LABEL_MENU + MENU_RC_NAV_DOWN]     = "Aşağı",
    [LABEL_MENU + MENU_RC_BASS_UP]      = "Bass Artı",
    [LABEL_MENU + MENU_RC_BASS_DOWN]    = "Bass Eksi",
    [LABEL_MENU + MENU_RC_MIDDLE_UP]    = "Orta Ses Artı",
    [LABEL_MENU + MENU_RC_MIDDLE_DOWN]  = "Orta Ses Eksi",
    [LABEL_MENU + MENU_RC_TREBLE_UP]    = "Tiz Artı",
    [LABEL_MENU + MENU_RC_TREBLE_DOWN]  = "Tiz Eksi",
    [LABEL_MENU + MENU_RC_LOUDNESS]     = "Ses Yükseltme",
    [LABEL_MENU + MENU_RC_SURROUND]     = "Kuşatma",
    [LABEL_MENU + MENU_RC_EFFECT_3D]    = "3D-Efekt",
    [LABEL_MENU + MENU_RC_TONE_BYPASS]  = "Ton Baypas",
    [LABEL_MENU + MENU_RC_TIME]         = "Zaman",
//    [LABEL_MENU + MENU_RC_STOP]         = "Stop",
//    [LABEL_MENU + MENU_RC_PLAY]         = "Play",
//    [LABEL_MENU + MENU_RC_PAUSE]        = "Pause",
//    [LABEL_MENU + MENU_RC_REW]          = "Rewind",
//    [LABEL_MENU + MENU_RC_FWD]          = "Flash forward",
//    [LABEL_MENU + MENU_RC_TIMER]        = "Timer",
};
