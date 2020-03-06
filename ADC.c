
#include <stdbool.h>
//#include <stdint.h>
#include "ADC_Main.h"
#define Std_ReturnType uint32_t
	#define Adc_GroupType uint32_t
	#define Adc_ValueGroupType uint32_t
	#define E_OK 1
	#define E_NOT_OK 0
#include <math.h>
#include "driverlib/sysctl.h"
#include "driverlib/adc.h"
extern Adc_ConfigType Adc_Config_Test;

extern	    uint32_t ADCValues[1];


void Adc_ReadGroup(Adc_GroupType Group , Adc_ValueGroupType *DataBufferPtr){
						ADCSequenceDataGet(Group, 3, DataBufferPtr);
						}
void Adc_EnableHardwareTrigger(Adc_GroupType Group){
	ADCProcessorTrigger(Group, 3);
}
void ADC_Config_Init(uint32_t ADC_Base,uint32_t PeripheralClockEnable){
	Adc_Config_Test.ADC_Base = ADC_Base;
	Adc_Config_Test.ADC_Peripheral=SYSCTL_PERIPH_ADC0;
}
void ADC_Init(const Adc_ConfigType* ConfigPtr){
	    SysCtlPeripheralEnable(ConfigPtr->ADC_Peripheral);
	    SysCtlDelay(3);
	    ADCSequenceConfigure(ConfigPtr->ADC_Base, 3, ADC_TRIGGER_PROCESSOR, 0);
			ADCSequenceStepConfigure(ConfigPtr->ADC_Base, 3, 0, ADC_CTL_TS | ADC_CTL_IE | ADC_CTL_END);
	    ADCSequenceEnable(ConfigPtr->ADC_Base, 3);
			ADCIntClear(ConfigPtr->ADC_Base, 3);
}

