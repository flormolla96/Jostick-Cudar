/*
 * Joistic.h
 *
 *  Created on: 18 jul. 2021
 *      Author: german
 */

#ifndef JOISTIC_H_
#define JOISTIC_H_


void GetDInStatus(uint8_t *DIO);
void GetADCStatus(int16_t *X,int16_t *Y,uint8_t *Batt,ADC_HandleTypeDef *ADC);
void SetTxData(uint8_t TXstr[], int16_t *X,int16_t *Y,uint8_t *Batt,uint8_t *DIO);
void getJoyCenter(ADC_HandleTypeDef *ADC);


#endif /* JOISTIC_H_ */
