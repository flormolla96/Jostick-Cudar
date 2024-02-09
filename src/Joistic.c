/*
 * Joistic.c
 *
 *  Created on: 18 jul. 2021
 *      Author: german
 */
#include "main.h"
#include "math.h"
#include "Joistic.h"
volatile uint16_t centerX=0,centerY=0;
int16_t int_pow(int16_t base, int16_t exp)
{
	int16_t result = 1;
    while (exp)
    {
        if (exp % 2)
           result *= base;
        exp /= 2;
        base *= base;
    }
    return result;
}
void SelecADC1(ADC_HandleTypeDef *ADC){
	ADC_ChannelConfTypeDef sConfig = {0};
/** Configure Regular Channel
 */
 sConfig.Channel = ADC_CHANNEL_0;
 sConfig.Rank = ADC_REGULAR_RANK_1;
 sConfig.SamplingTime = ADC_SAMPLETIME_1CYCLE_5;
 if (HAL_ADC_ConfigChannel(ADC, &sConfig) != HAL_OK)
 {
   Error_Handler();
 }
}
void SelecADC2(ADC_HandleTypeDef *ADC){
	ADC_ChannelConfTypeDef sConfig = {0};
 /** Configure Regular Channel
 */
 sConfig.Channel = ADC_CHANNEL_1;
 sConfig.Rank = ADC_REGULAR_RANK_1;
 sConfig.SamplingTime = ADC_SAMPLETIME_7CYCLES_5;
 if (HAL_ADC_ConfigChannel(ADC, &sConfig) != HAL_OK)
 {
   Error_Handler();
 }
}
void SelecADC3(ADC_HandleTypeDef *ADC){
	ADC_ChannelConfTypeDef sConfig = {0};
/** Configure Regular Channel
 */
 sConfig.Channel = ADC_CHANNEL_6;
 sConfig.Rank = ADC_REGULAR_RANK_1;
 sConfig.SamplingTime = ADC_SAMPLETIME_13CYCLES_5;
 if (HAL_ADC_ConfigChannel(ADC, &sConfig) != HAL_OK)
 {
   Error_Handler();
 }
}
void GetDInStatus(uint8_t *DIO)
{
  if(!HAL_GPIO_ReadPin(GPIOB,BTT_1_Pin))
  {
	  *DIO |=1<<0;
  }
  else
  {
	  *DIO &=~(1<<0);
  }
  if(!HAL_GPIO_ReadPin(GPIOB,BTT_2_Pin))
  {
	  *DIO |=1<<1;
  }
  else
  {
	  *DIO &=~(1<<1);
  }
  if(!HAL_GPIO_ReadPin(GPIOB,BTT_3_Pin))
  {
	  *DIO |=1<<2;
  }
  else
  {
	  *DIO &=~(1<<2);
  }
  if(!HAL_GPIO_ReadPin(GPIOB,BTT_4_Pin))
  {
	  *DIO |=1<<3;
  }
  else
  {
	  *DIO &=~(1<<3);
  }
  if(!HAL_GPIO_ReadPin(GPIOB,BTT_5_Pin))
  {
	  *DIO |=1<<4;
  }
  else
  {
	  *DIO &=~(1<<4);
  }
}
void getJoyCenter(ADC_HandleTypeDef *ADC)
{
	uint16_t ADCX=0,ADCY=0;
	//TOMO X
	SelecADC1(ADC);
	HAL_ADC_Start(ADC);
	if(HAL_ADC_PollForConversion(ADC,1000)==HAL_OK)
		ADCX=(HAL_ADC_GetValue(ADC));//>>2;
	HAL_ADC_Stop(ADC);
	//TOMO Y
	SelecADC2(ADC);
	HAL_ADC_Start(ADC);
	if(HAL_ADC_PollForConversion(ADC,1000)==HAL_OK)
		ADCY=(HAL_ADC_GetValue(ADC));//>>2;
	HAL_ADC_Stop(ADC);
	centerX=ADCX;
	centerX=ADCX;
	centerY=ADCY;
}

void GetADCStatus(int16_t *X,int16_t *Y,uint8_t *Batt,ADC_HandleTypeDef *ADC)
{
	static uint16_t ADCX=0,ADCY=0,ADCBatt=0,AcumX=0,AcumY=0,AcumBatt=0;
	int16_t jostikX=0,jostikY=0;
	//TOMO X
	SelecADC1(ADC);
	HAL_ADC_Start(ADC);
	if(HAL_ADC_PollForConversion(ADC,1000)==HAL_OK)
		ADCX=(HAL_ADC_GetValue(ADC));//>>2;
	HAL_ADC_Stop(ADC);
	//TOMO Y
	SelecADC2(ADC);
	HAL_ADC_Start(ADC);
	if(HAL_ADC_PollForConversion(ADC,1000)==HAL_OK)
		ADCY=(HAL_ADC_GetValue(ADC));//>>2;
	HAL_ADC_Stop(ADC);
	//TOMO BATT
	SelecADC3(ADC);
	HAL_ADC_Start(ADC);
	if(HAL_ADC_PollForConversion(ADC,1000)==HAL_OK)
		ADCBatt=(HAL_ADC_GetValue(ADC));//>>2;
	HAL_ADC_Stop(ADC);
	jostikY=(int16_t)(((ADCY*1.0-centerY*1.0)/centerY*1.0)*100.0);
	*Y=(int16_t)((0.00007*pow(jostikY,3))+(0.3*jostikY));
	//*Y=(int16_t)ADCY;
	jostikX=(int16_t)((float)((ADCX*1.0-centerX*1.0)/centerX)*100.0);
	*X=(int16_t)((0.00007*pow(jostikX,3))+(0.3*jostikX));
	*Batt=(uint8_t)(ADCBatt*100.0/1024.0);

}


void SetTxData(uint8_t TXstr[], int16_t *X2,int16_t *Y2,uint8_t *Batt,uint8_t *DIO)
{
	TXstr[0]=0xFE;
	TXstr[1]=0x55;
	TXstr[2]=0x03;
	TXstr[3]=0x00;
	TXstr[4]=((*X2)>>8)&(0xFF);
	TXstr[5]=(*X2)&(0xFF);
	TXstr[6]=((*Y2)>>8)&(0xFF);
	TXstr[7]=(*Y2)&(0xFF);
	TXstr[8]=*DIO;
	TXstr[9]=*Batt;
}
