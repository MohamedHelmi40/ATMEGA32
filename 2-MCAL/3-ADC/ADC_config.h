#ifndef ADC_CONFIG_H
#define ADC_CONFIG_H



#define REFERENCE_SELECTION   AREF
/* you can choose
 AREF,AVCC,V_REF_CAPACITOR 
*/


#define ADC_PRESCALER  ADC_pre_128
/* You can choose 
ADC_pre_2,ADC_pre_4,ADC_pre_8,ADC_pre_16,ADC_pre_32,ADC_pre_64,ADC_pre_128
*/

#define ADC_AUTO_TRIGGER_SOURCE  FREE_RUNNING_MODE
/*
FREE_RUNNING_MODE    
ANALOG_COMPARATOR   
EXT_INTERRUPT_REQUEST
T_C_0COMPARE_MATCH   
T_C_0_OVERFLOW       
T_C_1_COMPARE_MATCH_B
T_C_1_OVERFLOW       
T_C_1_CAPTURE_EVENT   */

#define ADC_ENABLE   ENABLE
/*you can choose 
ENABLE
DISABLE
*/

#define ADC_INTERRUPT_ENABLE ENABLE
/*you can choose 
ENABLE
DISABLE
*/

#define Auto_Trigger_Enable  DISABLE
/*you can choose
ENABLE
DISABLE
*/
#endif