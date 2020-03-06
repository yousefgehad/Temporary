	
	
	#include <stdint.h>
	#define Std_ReturnType uint32_t
	#define Adc_GroupType uint32_t
	#define Adc_ValueGroupType uint32_t
	#define E_OK 1
	#define E_NOT_OK 0
	    
			
typedef struct {
	uint32_t ADC_Base;
	uint32_t ADC_Peripheral;
}Adc_ConfigType;


			
void ADC_Init(const Adc_ConfigType* ConfigPtr);
void ADC_Config_Init(uint32_t ADC_Base,uint32_t PeripheralClockEnable);
Std_ReturnType Adc_SetupResultBuffer(Adc_GroupType Group,const Adc_ValueGroupType *DataBuffer);
void Adc_EnableHardwareTrigger(Adc_GroupType Group);
void Adc_ReadGroup(Adc_GroupType Group , Adc_ValueGroupType *DataBufferPtr);
