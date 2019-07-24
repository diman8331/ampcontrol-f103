EESchema Schematic File Version 4
LIBS:karadio-red-cache
EELAYER 29 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L RF_Module:ESP-12E U2
U 1 1 5D32FC74
P 5800 3900
F 0 "U2" H 5400 4650 50  0000 C CNN
F 1 "ESP-12E" H 5800 4050 50  0000 C CNN
F 2 "RF_Module:ESP-12E" H 5800 3900 50  0001 C CNN
F 3 "http://wiki.ai-thinker.com/_media/esp8266/esp8266_series_modules_user_manual_v1.1.pdf" H 5450 4000 50  0001 C CNN
	1    5800 3900
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x10 J5
U 1 1 5D3315AE
P 7900 4500
F 0 "J5" H 7850 5000 50  0000 L CNN
F 1 "VS1053_RED" V 8000 4250 50  0000 L CNN
F 2 "Connector_PinSocket_2.54mm:PinSocket_1x10_P2.54mm_Vertical" H 7900 4500 50  0001 C CNN
F 3 "~" H 7900 4500 50  0001 C CNN
	1    7900 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	7700 4100 7250 4100
Wire Wire Line
	7250 4200 7700 4200
Wire Wire Line
	7250 4300 7700 4300
Wire Wire Line
	7250 4400 7700 4400
Wire Wire Line
	7250 4500 7700 4500
Wire Wire Line
	7250 4600 7700 4600
Wire Wire Line
	7250 4700 7700 4700
Wire Wire Line
	7250 4800 7700 4800
Text Label 7250 4100 0    50   ~ 0
DREQ
Text Label 7250 4200 0    50   ~ 0
XDCS
Text Label 7250 4300 0    50   ~ 0
XRESET
Text Label 7250 4400 0    50   ~ 0
XCS
Text Label 7250 4500 0    50   ~ 0
SCK
Text Label 7250 4600 0    50   ~ 0
SI
Text Label 7250 4700 0    50   ~ 0
MISO
Text Label 7250 4800 0    50   ~ 0
CS
Text Label 7400 5000 0    50   ~ 0
5V
$Comp
L Regulator_Linear:AMS1117-3.3 U1
U 1 1 5D3359EF
P 4300 4600
F 0 "U1" H 4300 4842 50  0000 C CNN
F 1 "AMS1117-3.3" H 4300 4751 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 4300 4800 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 4400 4350 50  0001 C CNN
	1    4300 4600
	1    0    0    -1  
$EndComp
$Comp
L Connector_Generic:Conn_01x03 J3
U 1 1 5D337F2D
P 7900 3400
F 0 "J3" H 7850 3600 50  0000 L CNN
F 1 "UART" V 8000 3300 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 7900 3400 50  0001 C CNN
F 3 "~" H 7900 3400 50  0001 C CNN
	1    7900 3400
	1    0    0    -1  
$EndComp
Text Label 6700 3400 2    50   ~ 0
TX
Text Label 6700 3600 2    50   ~ 0
RX
Wire Wire Line
	7400 3300 7700 3300
Wire Wire Line
	7600 3500 7700 3500
$Comp
L power:GNDD #PWR0101
U 1 1 5D33E60A
P 7600 5100
F 0 "#PWR0101" H 7600 4850 50  0001 C CNN
F 1 "GNDD" H 7604 4945 50  0000 C CNN
F 2 "" H 7600 5100 50  0001 C CNN
F 3 "" H 7600 5100 50  0001 C CNN
	1    7600 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	7600 5100 7600 4900
Wire Wire Line
	7600 4900 7700 4900
Wire Wire Line
	6700 3800 6400 3800
Text Label 6700 3800 2    50   ~ 0
XDCS
Text Label 6700 3700 2    50   ~ 0
DREQ
Wire Wire Line
	6700 3700 6400 3700
Text Label 6700 3300 2    50   ~ 0
XRESET
Text Label 6700 4200 2    50   ~ 0
XCS
Wire Wire Line
	6400 4100 6700 4100
Text Label 6700 4100 2    50   ~ 0
SCK
Text Label 6700 3900 2    50   ~ 0
MISO
Wire Wire Line
	6700 3900 6400 3900
Wire Wire Line
	6400 4000 6700 4000
Text Label 6700 4000 2    50   ~ 0
SI
$Comp
L power:GNDD #PWR0102
U 1 1 5D34206D
P 5800 5100
F 0 "#PWR0102" H 5800 4850 50  0001 C CNN
F 1 "GNDD" H 5804 4945 50  0000 C CNN
F 2 "" H 5800 5100 50  0001 C CNN
F 3 "" H 5800 5100 50  0001 C CNN
	1    5800 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	5800 5100 5800 4950
NoConn ~ 5200 3900
NoConn ~ 5200 4000
NoConn ~ 5200 4100
NoConn ~ 5200 4200
NoConn ~ 5200 4300
NoConn ~ 5200 4400
$Comp
L Device:R R3
U 1 1 5D3470CD
P 5100 2950
F 0 "R3" H 5170 2996 50  0000 L CNN
F 1 "10k" H 5170 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 5030 2950 50  0001 C CNN
F 3 "~" H 5100 2950 50  0001 C CNN
	1    5100 2950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0103
U 1 1 5D3482D4
P 5100 2700
F 0 "#PWR0103" H 5100 2550 50  0001 C CNN
F 1 "+3V3" H 5115 2873 50  0000 C CNN
F 2 "" H 5100 2700 50  0001 C CNN
F 3 "" H 5100 2700 50  0001 C CNN
	1    5100 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	5100 2800 5100 2700
Wire Wire Line
	5100 3300 5100 3100
Wire Wire Line
	4800 3500 4800 3100
Wire Wire Line
	5200 3500 4800 3500
Wire Wire Line
	4800 2800 4800 2700
$Comp
L power:+3V3 #PWR0104
U 1 1 5D3519C2
P 4800 2700
F 0 "#PWR0104" H 4800 2550 50  0001 C CNN
F 1 "+3V3" H 4815 2873 50  0000 C CNN
F 2 "" H 4800 2700 50  0001 C CNN
F 3 "" H 4800 2700 50  0001 C CNN
	1    4800 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R2
U 1 1 5D3519BC
P 4800 2950
F 0 "R2" H 4870 2996 50  0000 L CNN
F 1 "10k" H 4870 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4730 2950 50  0001 C CNN
F 3 "~" H 4800 2950 50  0001 C CNN
	1    4800 2950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0105
U 1 1 5D3608D7
P 5800 2700
F 0 "#PWR0105" H 5800 2550 50  0001 C CNN
F 1 "+3V3" H 5815 2873 50  0000 C CNN
F 2 "" H 5800 2700 50  0001 C CNN
F 3 "" H 5800 2700 50  0001 C CNN
	1    5800 2700
	1    0    0    -1  
$EndComp
$Comp
L Device:R R4
U 1 1 5D361A1B
P 6800 4500
F 0 "R4" H 6870 4546 50  0000 L CNN
F 1 "10k" H 6870 4455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 6730 4500 50  0001 C CNN
F 3 "~" H 6800 4500 50  0001 C CNN
	1    6800 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 4350 6800 4200
Wire Wire Line
	6400 4200 6800 4200
$Comp
L power:GNDD #PWR0106
U 1 1 5D362BD8
P 6800 5100
F 0 "#PWR0106" H 6800 4850 50  0001 C CNN
F 1 "GNDD" H 6804 4945 50  0000 C CNN
F 2 "" H 6800 5100 50  0001 C CNN
F 3 "" H 6800 5100 50  0001 C CNN
	1    6800 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	6800 5100 6800 4650
$Comp
L Device:R R5
U 1 1 5D363BC1
P 6900 2950
F 0 "R5" H 6970 2996 50  0000 L CNN
F 1 "10k" H 6970 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 6830 2950 50  0001 C CNN
F 3 "~" H 6900 2950 50  0001 C CNN
	1    6900 2950
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0107
U 1 1 5D36557F
P 6900 2700
F 0 "#PWR0107" H 6900 2550 50  0001 C CNN
F 1 "+3V3" H 6915 2873 50  0000 C CNN
F 2 "" H 6900 2700 50  0001 C CNN
F 3 "" H 6900 2700 50  0001 C CNN
	1    6900 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 2700 6900 2800
$Comp
L Device:R R6
U 1 1 5D366861
P 7200 2950
F 0 "R6" H 7270 2996 50  0000 L CNN
F 1 "10k" H 7270 2905 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 7130 2950 50  0001 C CNN
F 3 "~" H 7200 2950 50  0001 C CNN
	1    7200 2950
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 3300 6900 3300
$Comp
L power:+3V3 #PWR0108
U 1 1 5D367B0F
P 7200 2700
F 0 "#PWR0108" H 7200 2550 50  0001 C CNN
F 1 "+3V3" H 7215 2873 50  0000 C CNN
F 2 "" H 7200 2700 50  0001 C CNN
F 3 "" H 7200 2700 50  0001 C CNN
	1    7200 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	7200 2700 7200 2800
$Comp
L Connector_Generic:Conn_01x02 J4
U 1 1 5D369038
P 7900 3750
F 0 "J4" H 7850 3850 50  0000 L CNN
F 1 "FW" V 8000 3650 50  0000 L CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 7900 3750 50  0001 C CNN
F 3 "~" H 7900 3750 50  0001 C CNN
	1    7900 3750
	1    0    0    -1  
$EndComp
Wire Wire Line
	6900 3100 6900 3300
Wire Wire Line
	7200 3100 7200 3500
Wire Wire Line
	6400 3500 7200 3500
Wire Wire Line
	7700 3750 6900 3750
Wire Wire Line
	6900 3750 6900 3300
Connection ~ 6900 3300
Wire Wire Line
	7700 3850 7600 3850
Wire Wire Line
	7600 3500 7600 3850
Wire Wire Line
	6400 3400 7700 3400
Wire Wire Line
	7400 3600 7400 3300
Wire Wire Line
	6400 3600 7400 3600
Text Label 7450 3300 0    50   ~ 0
RX
Text Label 7450 3400 0    50   ~ 0
TX
Wire Wire Line
	7600 4900 7600 3850
Connection ~ 7600 4900
Connection ~ 7600 3850
$Comp
L power:GNDD #PWR0109
U 1 1 5D39A71A
P 4300 5100
F 0 "#PWR0109" H 4300 4850 50  0001 C CNN
F 1 "GNDD" H 4304 4945 50  0000 C CNN
F 2 "" H 4300 5100 50  0001 C CNN
F 3 "" H 4300 5100 50  0001 C CNN
	1    4300 5100
	1    0    0    -1  
$EndComp
$Comp
L Device:CP C3
U 1 1 5D39AB4F
P 4700 4850
F 0 "C3" H 4818 4896 50  0000 L CNN
F 1 "100.0" H 4818 4805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 4738 4700 50  0001 C CNN
F 3 "~" H 4700 4850 50  0001 C CNN
	1    4700 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C4
U 1 1 5D39B1E9
P 5200 4850
F 0 "C4" H 5315 4896 50  0000 L CNN
F 1 "0.1" H 5315 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 5238 4700 50  0001 C CNN
F 3 "~" H 5200 4850 50  0001 C CNN
	1    5200 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	4600 4600 4700 4600
Wire Wire Line
	5200 4600 5200 4700
Wire Wire Line
	4700 4700 4700 4600
Connection ~ 4700 4600
$Comp
L power:GNDD #PWR0110
U 1 1 5D39EA3F
P 4700 5100
F 0 "#PWR0110" H 4700 4850 50  0001 C CNN
F 1 "GNDD" H 4704 4945 50  0000 C CNN
F 2 "" H 4700 5100 50  0001 C CNN
F 3 "" H 4700 5100 50  0001 C CNN
	1    4700 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0111
U 1 1 5D39EBB4
P 5200 5100
F 0 "#PWR0111" H 5200 4850 50  0001 C CNN
F 1 "GNDD" H 5204 4945 50  0000 C CNN
F 2 "" H 5200 5100 50  0001 C CNN
F 3 "" H 5200 5100 50  0001 C CNN
	1    5200 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4300 5100 4300 4900
Wire Wire Line
	4700 5100 4700 5000
Wire Wire Line
	5200 5100 5200 5000
Wire Wire Line
	3800 5100 3800 5000
Wire Wire Line
	3350 5100 3350 5000
$Comp
L power:GNDD #PWR0112
U 1 1 5D39A444
P 3800 5100
F 0 "#PWR0112" H 3800 4850 50  0001 C CNN
F 1 "GNDD" H 3804 4945 50  0000 C CNN
F 2 "" H 3800 5100 50  0001 C CNN
F 3 "" H 3800 5100 50  0001 C CNN
	1    3800 5100
	1    0    0    -1  
$EndComp
$Comp
L power:GNDD #PWR0113
U 1 1 5D399F62
P 3350 5100
F 0 "#PWR0113" H 3350 4850 50  0001 C CNN
F 1 "GNDD" H 3354 4945 50  0000 C CNN
F 2 "" H 3350 5100 50  0001 C CNN
F 3 "" H 3350 5100 50  0001 C CNN
	1    3350 5100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3800 4600 3350 4600
Connection ~ 3800 4600
Wire Wire Line
	3800 4700 3800 4600
Wire Wire Line
	3350 4600 3350 4700
$Comp
L Device:CP C1
U 1 1 5D38C207
P 3350 4850
F 0 "C1" H 3468 4896 50  0000 L CNN
F 1 "100.0" H 3468 4805 50  0000 L CNN
F 2 "Capacitor_THT:CP_Radial_D6.3mm_P2.50mm" H 3388 4700 50  0001 C CNN
F 3 "~" H 3350 4850 50  0001 C CNN
	1    3350 4850
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5D38AF8C
P 3800 4850
F 0 "C2" H 3915 4896 50  0000 L CNN
F 1 "0.1" H 3915 4805 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 3838 4700 50  0001 C CNN
F 3 "~" H 3800 4850 50  0001 C CNN
	1    3800 4850
	1    0    0    -1  
$EndComp
$Comp
L Connector:Screw_Terminal_01x02 J2
U 1 1 5D37DE2D
P 3350 4000
F 0 "J2" H 3350 3750 50  0000 C CNN
F 1 "PWR" V 3450 3950 50  0000 C CNN
F 2 "TerminalBlock:TerminalBlock_bornier-2_P5.08mm" H 3350 4000 50  0001 C CNN
F 3 "~" H 3350 4000 50  0001 C CNN
	1    3350 4000
	-1   0    0    1   
$EndComp
Wire Wire Line
	3550 3900 3800 3900
$Comp
L power:GNDD #PWR0114
U 1 1 5D3C4735
P 3650 4100
F 0 "#PWR0114" H 3650 3850 50  0001 C CNN
F 1 "GNDD" H 3654 3945 50  0000 C CNN
F 2 "" H 3650 4100 50  0001 C CNN
F 3 "" H 3650 4100 50  0001 C CNN
	1    3650 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	3650 4100 3650 4000
Wire Wire Line
	3650 4000 3550 4000
Text Label 3700 3900 0    50   ~ 0
5V
$Comp
L power:+5V #PWR0115
U 1 1 5D3C8C5C
P 7050 4850
F 0 "#PWR0115" H 7050 4700 50  0001 C CNN
F 1 "+5V" H 7065 5023 50  0000 C CNN
F 2 "" H 7050 4850 50  0001 C CNN
F 3 "" H 7050 4850 50  0001 C CNN
	1    7050 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	7050 5000 7050 4850
Wire Wire Line
	7050 5000 7700 5000
$Comp
L power:+3V3 #PWR0116
U 1 1 5D3CB48A
P 4700 4350
F 0 "#PWR0116" H 4700 4200 50  0001 C CNN
F 1 "+3V3" H 4715 4523 50  0000 C CNN
F 2 "" H 4700 4350 50  0001 C CNN
F 3 "" H 4700 4350 50  0001 C CNN
	1    4700 4350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4700 4350 4700 4600
Text Label 6700 4300 2    50   ~ 0
CS
Wire Wire Line
	4600 3750 4600 3800
$Comp
L power:GNDD #PWR0117
U 1 1 5D34DD85
P 4600 3800
F 0 "#PWR0117" H 4600 3550 50  0001 C CNN
F 1 "GNDD" H 4604 3645 50  0000 C CNN
F 2 "" H 4600 3800 50  0001 C CNN
F 3 "" H 4600 3800 50  0001 C CNN
	1    4600 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6400 4300 6700 4300
$Comp
L Connector_Generic:Conn_01x04 J1
U 1 1 5D42EE6D
P 3350 3000
F 0 "J1" H 3350 3250 50  0000 C CNN
F 1 "CTRL" V 3450 2950 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 3350 3000 50  0001 C CNN
F 3 "~" H 3350 3000 50  0001 C CNN
	1    3350 3000
	-1   0    0    -1  
$EndComp
Text Label 3850 2900 2    50   ~ 0
ADC
Text Label 6700 3500 2    50   ~ 0
LED
Text Label 3850 3000 2    50   ~ 0
LED
Wire Wire Line
	3850 3000 3550 3000
$Comp
L power:+3V3 #PWR0118
U 1 1 5D43AAF7
P 4250 2700
F 0 "#PWR0118" H 4250 2550 50  0001 C CNN
F 1 "+3V3" H 4265 2873 50  0000 C CNN
F 2 "" H 4250 2700 50  0001 C CNN
F 3 "" H 4250 2700 50  0001 C CNN
	1    4250 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	3550 3100 4250 3100
Wire Wire Line
	4250 3100 4250 2700
Wire Wire Line
	4600 3300 4600 3350
Wire Wire Line
	5100 3300 4600 3300
Wire Wire Line
	5200 3300 5100 3300
Connection ~ 5100 3300
Wire Wire Line
	4900 3700 5200 3700
Text Label 4900 3700 0    50   ~ 0
ADC
Wire Wire Line
	3650 4000 3650 3200
Wire Wire Line
	3650 3200 3550 3200
Connection ~ 3650 4000
Connection ~ 3800 3900
Wire Wire Line
	3800 3650 3800 3900
$Comp
L power:+5V #PWR0119
U 1 1 5D3C6BC7
P 3800 3650
F 0 "#PWR0119" H 3800 3500 50  0001 C CNN
F 1 "+5V" H 3815 3823 50  0000 C CNN
F 2 "" H 3800 3650 50  0001 C CNN
F 3 "" H 3800 3650 50  0001 C CNN
	1    3800 3650
	1    0    0    -1  
$EndComp
$Comp
L Device:R R1
U 1 1 5D45AFA6
P 4050 3350
F 0 "R1" H 4120 3396 50  0000 L CNN
F 1 "10k" H 4120 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 3980 3350 50  0001 C CNN
F 3 "~" H 4050 3350 50  0001 C CNN
	1    4050 3350
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3200 4050 2900
Wire Wire Line
	3550 2900 4050 2900
$Comp
L power:GNDD #PWR01
U 1 1 5D46048B
P 4050 3800
F 0 "#PWR01" H 4050 3550 50  0001 C CNN
F 1 "GNDD" H 4054 3645 50  0000 C CNN
F 2 "" H 4050 3800 50  0001 C CNN
F 3 "" H 4050 3800 50  0001 C CNN
	1    4050 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	4050 3800 4050 3500
$Comp
L Switch:SW_Push SW1
U 1 1 5D34AE32
P 4600 3550
F 0 "SW1" V 4650 3700 50  0000 C CNN
F 1 "RESET" H 4600 3450 50  0000 C CNN
F 2 "Button_Switch_THT:SW_PUSH_6mm" H 4600 3750 50  0001 C CNN
F 3 "~" H 4600 3750 50  0001 C CNN
	1    4600 3550
	0    -1   -1   0   
$EndComp
Wire Wire Line
	4700 4600 5200 4600
Wire Wire Line
	3800 3900 3800 4600
Wire Wire Line
	3800 4600 4000 4600
$Comp
L power:PWR_FLAG #FLG0101
U 1 1 5D473C84
P 3350 4500
F 0 "#FLG0101" H 3350 4575 50  0001 C CNN
F 1 "PWR_FLAG" H 3350 4673 50  0001 C CNN
F 2 "" H 3350 4500 50  0001 C CNN
F 3 "~" H 3350 4500 50  0001 C CNN
	1    3350 4500
	1    0    0    -1  
$EndComp
Wire Wire Line
	3350 4500 3350 4600
Connection ~ 3350 4600
$Comp
L power:PWR_FLAG #FLG0102
U 1 1 5D476CE1
P 5900 4850
F 0 "#FLG0102" H 5900 4925 50  0001 C CNN
F 1 "PWR_FLAG" H 5900 5023 50  0001 C CNN
F 2 "" H 5900 4850 50  0001 C CNN
F 3 "~" H 5900 4850 50  0001 C CNN
	1    5900 4850
	1    0    0    -1  
$EndComp
Wire Wire Line
	5900 4850 5900 4950
Wire Wire Line
	5900 4950 5800 4950
Connection ~ 5800 4950
Wire Wire Line
	5800 4950 5800 4600
Wire Wire Line
	5800 2700 5800 3100
Text Label 4850 3300 0    50   ~ 0
~RST
$Comp
L Memory_EEPROM:25LCxxx U3
U 1 1 5D361D11
P 9300 3250
F 0 "U3" H 9050 3500 50  0000 C CNN
F 1 "23LCV1024" H 9550 3500 50  0000 C CNN
F 2 "Package_SO:SO-8_3.9x4.9mm_P1.27mm" H 9300 3250 50  0001 C CNN
F 3 "http://ww1.microchip.com/downloads/en/DeviceDoc/21832H.pdf" H 9300 3250 50  0001 C CNN
	1    9300 3250
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR0120
U 1 1 5D3667F3
P 9300 2900
F 0 "#PWR0120" H 9300 2750 50  0001 C CNN
F 1 "+3V3" H 9315 3073 50  0000 C CNN
F 2 "" H 9300 2900 50  0001 C CNN
F 3 "" H 9300 2900 50  0001 C CNN
	1    9300 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 2900 9300 2950
$Comp
L power:GNDD #PWR0121
U 1 1 5D369461
P 9300 3700
F 0 "#PWR0121" H 9300 3450 50  0001 C CNN
F 1 "GNDD" H 9304 3545 50  0000 C CNN
F 2 "" H 9300 3700 50  0001 C CNN
F 3 "" H 9300 3700 50  0001 C CNN
	1    9300 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	9300 3700 9300 3550
Text Label 9950 3350 2    50   ~ 0
MISO
Wire Wire Line
	9950 3350 9700 3350
Wire Wire Line
	9700 3250 9950 3250
Text Label 9950 3250 2    50   ~ 0
SI
Wire Wire Line
	9700 3150 9950 3150
Text Label 9950 3150 2    50   ~ 0
SCK
$Comp
L power:GNDD #PWR0122
U 1 1 5D382FBD
P 8450 3700
F 0 "#PWR0122" H 8450 3450 50  0001 C CNN
F 1 "GNDD" H 8454 3545 50  0000 C CNN
F 2 "" H 8450 3700 50  0001 C CNN
F 3 "" H 8450 3700 50  0001 C CNN
	1    8450 3700
	1    0    0    -1  
$EndComp
Text Notes 8350 4750 0    50   ~ 0
R1 - install if control board not used\n\nU3 - install for better caching\n\nR7, R9 - install if 23LC1024 is used\n\nR8 - install if 23LCV1024 is used\n\n
Wire Wire Line
	8450 3050 8450 3250
$Comp
L Device:R R8
U 1 1 5D387CD5
P 8450 3500
F 0 "R8" H 8520 3546 50  0000 L CNN
F 1 "10k" H 8520 3455 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8380 3500 50  0001 C CNN
F 3 "~" H 8450 3500 50  0001 C CNN
	1    8450 3500
	1    0    0    -1  
$EndComp
$Comp
L Device:R R7
U 1 1 5D3871DC
P 8450 2900
F 0 "R7" H 8520 2946 50  0000 L CNN
F 1 "10k" H 8520 2855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8380 2900 50  0001 C CNN
F 3 "~" H 8450 2900 50  0001 C CNN
	1    8450 2900
	1    0    0    -1  
$EndComp
Wire Wire Line
	8900 3350 8700 3350
Text Label 8700 3350 0    50   ~ 0
CS
Wire Wire Line
	8450 3250 8900 3250
Connection ~ 8450 3250
Wire Wire Line
	8450 3250 8450 3350
$Comp
L power:+3V3 #PWR02
U 1 1 5D399E65
P 8450 2700
F 0 "#PWR02" H 8450 2550 50  0001 C CNN
F 1 "+3V3" H 8465 2873 50  0000 C CNN
F 2 "" H 8450 2700 50  0001 C CNN
F 3 "" H 8450 2700 50  0001 C CNN
	1    8450 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8450 2700 8450 2750
$Comp
L Device:R R9
U 1 1 5D3A2230
P 8750 2900
F 0 "R9" H 8820 2946 50  0000 L CNN
F 1 "10k" H 8820 2855 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 8680 2900 50  0001 C CNN
F 3 "~" H 8750 2900 50  0001 C CNN
	1    8750 2900
	1    0    0    -1  
$EndComp
$Comp
L power:+3V3 #PWR03
U 1 1 5D3A389D
P 8750 2700
F 0 "#PWR03" H 8750 2550 50  0001 C CNN
F 1 "+3V3" H 8765 2873 50  0000 C CNN
F 2 "" H 8750 2700 50  0001 C CNN
F 3 "" H 8750 2700 50  0001 C CNN
	1    8750 2700
	1    0    0    -1  
$EndComp
Wire Wire Line
	8750 2700 8750 2750
Wire Wire Line
	8750 3050 8750 3150
Wire Wire Line
	8750 3150 8900 3150
Wire Wire Line
	8450 3650 8450 3700
$EndSCHEMATC
