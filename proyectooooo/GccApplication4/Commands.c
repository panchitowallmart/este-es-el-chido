/*
 * Commands.c
 *
 * Created: 08/11/2024 04:57:13 p. m.
 *  Author: emili
 */ 

#include "Commands.h"
#include "USART.h"
#include "ADC.h"
#include <stdio.h>

void processCommand(char command, int potPin1, int potPin2) {
	int potValue;
	char buffer[20];

	if (command == '1') {
		potValue = ADC_read(potPin1);  // Lee el valor del primer potenciómetro
		} else if (command == '2') {
		potValue = ADC_read(potPin2);  // Lee el valor del segundo potenciómetro
		} else {
		USART_sendData("Comando no reconocido\n");
		return;
	}

	// Convierte el valor del potenciómetro a voltaje y envía la respuesta
	float voltage = ADC_convertToVoltage(potValue);
	snprintf(buffer, sizeof(buffer), "Voltaje: %.2f V\n", voltage);
	USART_sendData(buffer);
}
