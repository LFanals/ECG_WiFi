EESchema Schematic File Version 4
LIBS:base-cache
EELAYER 30 0
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
L MCU_Module:Arduino_Nano_v3.x A1
U 1 1 5E0A8D51
P 3900 4150
F 0 "A1" H 3900 3061 50  0000 C CNN
F 1 "Arduino_Nano_v3.x" H 3900 2970 50  0000 C CNN
F 2 "Module:Arduino_Nano" H 4050 3200 50  0001 L CNN
F 3 "http://www.mouser.com/pdfdocs/Gravitech_Arduino_Nano3_0.pdf" H 3900 3150 50  0001 C CNN
	1    3900 4150
	1    0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x06_Male J3
U 1 1 5E0A9D41
P 7400 2950
F 0 "J3" H 7508 3331 50  0000 C CNN
F 1 "Conn_01x06_Male" H 7508 3240 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x06_P2.54mm_Vertical" H 7400 2950 50  0001 C CNN
F 3 "~" H 7400 2950 50  0001 C CNN
	1    7400 2950
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J4
U 1 1 5E0AA816
P 6700 1450
F 0 "J4" H 6808 1731 50  0000 C CNN
F 1 "Conn_01x04_Male" H 6808 1640 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 6700 1450 50  0001 C CNN
F 3 "~" H 6700 1450 50  0001 C CNN
	1    6700 1450
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J5
U 1 1 5E0ACC56
P 7950 4100
F 0 "J5" H 8058 4381 50  0000 C CNN
F 1 "Conn_01x04_Male" H 8058 4290 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 7950 4100 50  0001 C CNN
F 3 "~" H 7950 4100 50  0001 C CNN
	1    7950 4100
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x04_Male J7
U 1 1 5E0AE533
P 9100 4100
F 0 "J7" H 9208 4381 50  0000 C CNN
F 1 "Conn_01x04_Male" H 9208 4290 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x04_P2.54mm_Vertical" H 9100 4100 50  0001 C CNN
F 3 "~" H 9100 4100 50  0001 C CNN
	1    9100 4100
	-1   0    0    -1  
$EndComp
Text GLabel 6800 2750 0    50   Input ~ 0
GND
Text GLabel 6800 2950 0    50   Input ~ 0
OUTPUT
Text GLabel 6800 3050 0    50   Input ~ 0
LO-
Text GLabel 6800 3150 0    50   Input ~ 0
LO+
Text GLabel 6800 3250 0    50   Input ~ 0
-SON
Text GLabel 6150 1350 0    50   Input ~ 0
GND
Text GLabel 6150 1450 0    50   Input ~ 0
D+
Text GLabel 6800 2850 0    50   Input ~ 0
3V3
Text GLabel 6150 1550 0    50   Input ~ 0
D-
Text GLabel 6150 1650 0    50   Input ~ 0
5V
Text GLabel 5000 1450 0    50   Input ~ 0
1,2+
Text GLabel 5000 1550 0    50   Input ~ 0
1,2-
Text GLabel 7400 4000 0    50   Input ~ 0
TX
Text GLabel 6650 4050 0    50   Input ~ 0
CHPD
Text GLabel 7400 4200 0    50   Input ~ 0
RESET
Text GLabel 6650 4350 0    50   Input ~ 0
3V3
Text GLabel 8600 4000 0    50   Input ~ 0
GND
Text GLabel 8600 4100 0    50   Input ~ 0
GPIO2
Text GLabel 8600 4200 0    50   Input ~ 0
GPIO0
Text GLabel 8600 4300 0    50   Input ~ 0
RX
$Comp
L Regulator_Linear:AMS1117-3.3 U1
U 1 1 5E0B32C6
P 8050 1050
F 0 "U1" H 8050 1292 50  0000 C CNN
F 1 "AMS1117-3.3" H 8050 1201 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-223-3_TabPin2" H 8050 1250 50  0001 C CNN
F 3 "http://www.advanced-monolithic.com/pdf/ds1117.pdf" H 8150 800 50  0001 C CNN
	1    8050 1050
	1    0    0    -1  
$EndComp
Text GLabel 7950 1700 0    50   Input ~ 0
GND
Text GLabel 7500 1050 0    50   Input ~ 0
5V
Text GLabel 8850 1050 2    50   Input ~ 0
3V3
Text GLabel 4200 1550 2    50   Input ~ 0
1,2+
Text GLabel 4200 1650 2    50   Input ~ 0
1,2-
$Comp
L Connector:Conn_01x02_Male J1
U 1 1 5E0BF387
P 2850 1550
F 0 "J1" H 2958 1731 50  0000 C CNN
F 1 "Conn_01x02_Male" H 2958 1640 50  0000 C CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x02_P2.54mm_Vertical" H 2850 1550 50  0001 C CNN
F 3 "~" H 2850 1550 50  0001 C CNN
	1    2850 1550
	1    0    0    -1  
$EndComp
Text GLabel 4950 4150 2    50   Input ~ 0
OUTPUT
Text GLabel 3850 5450 0    50   Input ~ 0
GND
Text GLabel 3700 2850 0    50   Input ~ 0
5V
$Comp
L Device:R R1
U 1 1 5E0C2AB5
P 6900 4200
F 0 "R1" H 6970 4246 50  0000 L CNN
F 1 "220" H 6970 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 6830 4200 50  0001 C CNN
F 3 "~" H 6900 4200 50  0001 C CNN
	1    6900 4200
	1    0    0    -1  
$EndComp
Text GLabel 5050 4650 2    50   Input ~ 0
GPIO2
Text Notes 2350 -850 0    50   ~ 0
Falta l'anell
Text Notes 2650 -250 0    50   ~ 0
Falten els interruptors, en posaria un per: \n- alimentació pila\n- alimentació LEDs\n\nalgun més?
$Comp
L Connector:Conn_01x03_Male J6
U 1 1 5E0CDB1B
P 8200 5600
F 0 "J6" H 8172 5624 50  0000 R CNN
F 1 "Conn_01x03_Male" H 8172 5533 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x03_P2.54mm_Vertical" H 8200 5600 50  0001 C CNN
F 3 "~" H 8200 5600 50  0001 C CNN
	1    8200 5600
	-1   0    0    -1  
$EndComp
Text GLabel 6750 5500 0    50   Input ~ 0
5V
Text GLabel 6750 5600 0    50   Input ~ 0
GND
Text GLabel 6750 5700 0    50   Input ~ 0
DATA_IN
$Comp
L Switch:SW_DIP_x01 SW2
U 1 1 5E0D12A0
P 7300 5400
F 0 "SW2" H 7300 5667 50  0000 C CNN
F 1 "SW_DIP_x01" H 7300 5576 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" H 7300 5400 50  0001 C CNN
F 3 "~" H 7300 5400 50  0001 C CNN
	1    7300 5400
	1    0    0    -1  
$EndComp
Wire Wire Line
	4200 1550 3950 1550
Wire Wire Line
	3950 1550 3950 1450
Wire Wire Line
	3050 1450 3050 1550
Wire Wire Line
	4200 1650 3050 1650
Wire Wire Line
	7000 5400 6750 5400
Wire Wire Line
	6750 5400 6750 5500
Wire Wire Line
	7600 5400 8000 5400
Wire Wire Line
	8000 5400 8000 5500
Wire Wire Line
	8000 5700 6750 5700
Wire Wire Line
	6750 5600 8000 5600
Wire Wire Line
	5000 1450 5300 1450
Wire Wire Line
	5300 1550 5000 1550
Wire Wire Line
	6150 1350 6500 1350
Wire Wire Line
	6150 1450 6500 1450
Wire Wire Line
	6150 1550 6500 1550
Wire Wire Line
	6150 1650 6500 1650
Wire Wire Line
	7500 1050 7650 1050
Wire Wire Line
	8350 1050 8450 1050
Wire Wire Line
	3850 5450 3900 5450
Wire Wire Line
	6800 2750 7200 2750
Wire Wire Line
	7200 2850 6800 2850
Wire Wire Line
	6800 2950 7200 2950
Wire Wire Line
	6800 3250 7200 3250
Wire Wire Line
	6800 3150 7200 3150
Wire Wire Line
	6800 3050 7200 3050
Wire Wire Line
	4950 4150 4400 4150
Text GLabel 3000 4150 0    50   Input ~ 0
DATA_IN
Wire Wire Line
	3000 4150 3400 4150
Wire Wire Line
	3700 2850 4100 2850
Wire Wire Line
	4100 2850 4100 3000
Wire Wire Line
	7400 4000 7750 4000
Wire Wire Line
	7400 4350 7400 4300
Wire Wire Line
	7400 4300 7750 4300
Wire Wire Line
	7400 4050 7400 4100
Wire Wire Line
	7750 4100 7400 4100
Wire Wire Line
	8600 4000 8900 4000
Wire Wire Line
	8600 4200 8900 4200
Wire Wire Line
	8600 4100 8900 4100
Wire Wire Line
	8600 4300 8900 4300
Wire Wire Line
	7400 4200 7750 4200
Wire Wire Line
	6900 4050 7400 4050
Wire Wire Line
	6900 4350 7400 4350
Wire Wire Line
	6650 4050 6900 4050
Connection ~ 6900 4050
Wire Wire Line
	6900 4350 6650 4350
Connection ~ 6900 4350
$Comp
L Device:C C1
U 1 1 5E0F1CBD
P 7650 1300
F 0 "C1" H 7765 1346 50  0000 L CNN
F 1 "10 uF" H 7765 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 7688 1150 50  0001 C CNN
F 3 "~" H 7650 1300 50  0001 C CNN
	1    7650 1300
	1    0    0    -1  
$EndComp
$Comp
L Device:C C2
U 1 1 5E0F21AA
P 8450 1300
F 0 "C2" H 8565 1346 50  0000 L CNN
F 1 "10 uF" H 8565 1255 50  0000 L CNN
F 2 "Capacitor_SMD:C_1206_3216Metric" H 8488 1150 50  0001 C CNN
F 3 "~" H 8450 1300 50  0001 C CNN
	1    8450 1300
	1    0    0    -1  
$EndComp
Wire Wire Line
	8050 1700 7950 1700
Wire Wire Line
	8050 1350 8050 1450
Wire Wire Line
	7650 1450 8050 1450
Connection ~ 8050 1450
Wire Wire Line
	8050 1450 8050 1700
Wire Wire Line
	7650 1150 7650 1050
Connection ~ 7650 1050
Wire Wire Line
	7650 1050 7750 1050
Wire Wire Line
	8450 1150 8450 1050
Connection ~ 8450 1050
Wire Wire Line
	8450 1050 8850 1050
Wire Wire Line
	8450 1450 8050 1450
Wire Wire Line
	3350 1450 3050 1450
$Comp
L Switch:SW_DIP_x01 SW1
U 1 1 5E0D25C6
P 3650 1450
F 0 "SW1" H 3650 1717 50  0000 C CNN
F 1 "SW_DIP_x01" H 3650 1626 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric" H 3650 1450 50  0001 C CNN
F 3 "~" H 3650 1450 50  0001 C CNN
	1    3650 1450
	-1   0    0    -1  
$EndComp
Wire Notes Line
	7000 1100 7000 1850
Wire Notes Line
	7000 1850 4700 1850
Wire Notes Line
	4700 1850 4700 1100
Wire Notes Line
	4700 1100 7000 1100
Wire Notes Line
	4600 1850 2550 1850
Wire Notes Line
	2550 1850 2550 1000
Wire Notes Line
	2550 1000 4600 1000
Wire Notes Line
	4600 1000 4600 1850
Wire Notes Line
	7100 750  9250 750 
Wire Notes Line
	9250 750  9250 1850
Wire Notes Line
	9250 1850 7100 1850
Wire Notes Line
	7100 1850 7100 750 
Wire Notes Line
	6400 2450 7750 2450
Wire Notes Line
	7750 2450 7750 3450
Wire Notes Line
	7750 3450 6400 3450
Wire Notes Line
	6400 3450 6400 2450
Wire Notes Line
	9500 3700 9500 4600
Wire Notes Line
	9500 4600 6300 4600
Wire Notes Line
	6300 4600 6300 3700
Wire Notes Line
	6300 3700 9500 3700
Wire Notes Line
	6200 4950 9050 4950
Wire Notes Line
	9050 4950 9050 5950
Wire Notes Line
	9050 5950 6200 5950
Wire Notes Line
	6200 5950 6200 4950
Wire Notes Line
	5400 2500 5400 5650
Wire Notes Line
	5400 5650 2550 5650
Wire Notes Line
	2550 5650 2550 2500
Wire Notes Line
	2550 2500 5400 2500
Text Notes 2550 1000 0    50   ~ 0
PILA
Text Notes 4700 1100 0    50   ~ 0
REGULADOR 5V
Text Notes 7100 750  0    50   ~ 0
REGULADOR 5V -> 3V3
Text Notes 6400 2450 0    50   ~ 0
ECG
Text Notes 2550 2500 0    50   ~ 0
ARDUINO NANO
Text Notes 6300 3700 0    50   ~ 0
ESP-01
Text Notes 6200 4950 0    50   ~ 0
ANELL DE LEDs
$Comp
L Connector:Conn_01x01_Male J2
U 1 1 5E137D79
P 5500 1450
F 0 "J2" H 5472 1474 50  0000 R CNN
F 1 "Conn_01x01_Male" H 5750 1600 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 5500 1450 50  0001 C CNN
F 3 "~" H 5500 1450 50  0001 C CNN
	1    5500 1450
	-1   0    0    -1  
$EndComp
$Comp
L Connector:Conn_01x01_Male J8
U 1 1 5E13985B
P 5500 1550
F 0 "J8" H 5472 1574 50  0000 R CNN
F 1 "Conn_01x01_Male" H 5800 1500 50  0000 R CNN
F 2 "Connector_PinHeader_2.54mm:PinHeader_1x01_P2.54mm_Vertical" H 5500 1550 50  0001 C CNN
F 3 "~" H 5500 1550 50  0001 C CNN
	1    5500 1550
	-1   0    0    -1  
$EndComp
Text GLabel 5050 4550 2    50   Input ~ 0
GPIO0
Wire Wire Line
	3900 5150 3900 5450
Wire Wire Line
	4400 4550 4600 4550
Wire Wire Line
	4400 4650 4800 4650
$Comp
L Device:R R2
U 1 1 5E0F2BB0
P 4600 3350
F 0 "R2" H 4670 3396 50  0000 L CNN
F 1 "1000" H 4670 3305 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4530 3350 50  0001 C CNN
F 3 "~" H 4600 3350 50  0001 C CNN
	1    4600 3350
	1    0    0    -1  
$EndComp
$Comp
L Device:R R3
U 1 1 5E0F3A53
P 4800 3700
F 0 "R3" H 4870 3746 50  0000 L CNN
F 1 "1000" H 4870 3655 50  0000 L CNN
F 2 "Resistor_SMD:R_1206_3216Metric" V 4730 3700 50  0001 C CNN
F 3 "~" H 4800 3700 50  0001 C CNN
	1    4800 3700
	1    0    0    -1  
$EndComp
Wire Wire Line
	4800 3850 4800 4650
Connection ~ 4800 4650
Wire Wire Line
	4800 4650 5050 4650
Wire Wire Line
	4600 3500 4600 4550
Connection ~ 4600 4550
Wire Wire Line
	4600 4550 5050 4550
Wire Wire Line
	4600 3200 4100 3200
Wire Wire Line
	4100 3200 4100 3150
Connection ~ 4100 3150
Wire Wire Line
	4800 3550 4800 3000
Wire Wire Line
	4800 3000 4100 3000
Connection ~ 4100 3000
Wire Wire Line
	4100 3000 4100 3150
$EndSCHEMATC
