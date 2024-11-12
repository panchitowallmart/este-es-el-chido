/*
 * ADC.h
 *
 * Created: 08/11/2024 04:59:21 p. m.
 *  Author: emili
 */ 

#ifndef ADC_H
#define ADC_H

void ADC_init();
int ADC_read(int pin);
float ADC_convertToVoltage(int value);

#endif
