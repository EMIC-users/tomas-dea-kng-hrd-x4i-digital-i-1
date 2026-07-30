// Define microcontroller type (pic24FJ64GA002 is the most used in EMIC modules)

// I2C configuration (using I2C2)

// Digital inputs
#define TRIS_DigIn1	                _TRISB6
#define PIN_DigIn1 	                _RB6
#define LAT_DigIn1 	                _LATB6
#define ODC_DigIn1	                _ODB6
#define RPOUT_DigIn1		            RPOR3bits.RP6R
#define RPIN_DigIn1		            6
#define CN_DigIn1		                24
#define TRIS_DigIn2	                _TRISB8
#define PIN_DigIn2 	                _RB8
#define LAT_DigIn2 	                _LATB8
#define ODC_DigIn2	                _ODB8
#define RPOUT_DigIn2		            RPOR4bits.RP8R
#define RPIN_DigIn2		            8
#define CN_DigIn2		                22
#define TRIS_DigIn3	                _TRISB12
#define PORT_DigIn3 	                _RB12
#define LAT_DigIn3 	                _LATB12
#define ODC_DigIn3	                _ODB12
#define PIN_DigIn3 	                _RB12
#define RPOUT_DigIn3		            RPOR6bits.RP12R
#define RPIN_DigIn3		            12
#define CN_DigIn3		                14
#define ADC_value_DigIn3              Buffer_entradas[12]
#define HAL_SetAnalog_DigIn3()        {_PCFG12=0;\
                                        adc_addAnalogChannel(12);}

#define TRIS_DigIn4	                _TRISB14
#define PORT_DigIn4 	                _RB14
#define LAT_DigIn4 	                _LATB14
#define ODC_DigIn4	                _ODB14
#define PIN_DigIn4 	                _RB14
#define RPOUT_DigIn4	                RPOR7bits.RP14R
#define RPIN_DigIn4	                14
#define CN_DigIn4		                12
#define ADC_value_DigIn4              Buffer_entradas[10] 
#define HAL_SetAnalog_DigIn4()        {_PCFG10=0;\
                                        adc_addAnalogChannel(10);}


// LEDs
#define TRIS_Led1	                _TRISB5
#define PIN_Led1 	                _RB5
#define LAT_Led1 	                _LATB5
#define ODC_Led1	                _ODB5
#define RPOUT_Led1		            RPOR2bits.RP5R
#define RPIN_Led1		            5
#define CN_Led1		                27
#define TRIS_Led2	                _TRISB7
#define PORT_Led2 	                _RB7
#define PIN_Led2 	                _RB7
#define LAT_Led2 	                _LATB7
#define ODC_Led2	                _ODB7
#define RPOUT_Led2		            RPOR3bits.RP7R
#define RPIN_Led2		            7
#define CN_Led2		                23
#define TRIS_Led3	                _TRISB9
#define PIN_Led3 	                _RB9
#define LAT_Led3 	                _LATB9
#define ODC_Led3	                _ODB9
#define RPOUT_Led3		            RPOR4bits.RP9R
#define RPIN_Led3		            9
#define CN_Led3		                21
#define TRIS_Led4	                _TRISB13
#define PORT_Led4 	                _RB13
#define LAT_Led4 	                _LATB13
#define ODC_Led4	                _ODB13
#define PIN_Led4 	                _RB13
#define RPOUT_Led4		            RPOR6bits.RP13R
#define RPIN_Led4		            13
#define CN_Led4		                13
#define ADC_value_Led4              Buffer_entradas[11] 
#define HAL_SetAnalog_Led4()        {_PCFG11=0;\
                                        adc_addAnalogChannel(11);}

#define TRIS_Led5	                _TRISB15
#define PORT_Led5 	                _RB15
#define LAT_Led5 	                _LATB15
#define ODC_Led5	                _ODB15
#define PIN_Led5 	                _RB15
#define RPOUT_Led5	                RPOR7bits.RP15R
#define RPIN_Led5	                15
#define CN_Led5		                11
#define ADC_value_Led5              Buffer_entradas[9] 
#define HAL_SetAnalog_Led5()        {_PCFG9=0;\
                                        adc_addAnalogChannel(9);}

//#include "myId.h"

// Board name definition
