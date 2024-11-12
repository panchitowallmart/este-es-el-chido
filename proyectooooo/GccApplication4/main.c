/*
 * GccApplication4.c
 *
 * Created: 08/11/2024 04:50:58 p. m.
 * Author : emili
 */ 

#include <avr/io.h>
#include "USART.h"
#include "ADC.h"
#include "Commands.h"

#define POT1 0  // Pin A0
#define POT2 1  // Pin A1

int main(void) {
	USART_init(9600);   // Inicializa USART a 9600 bps
	ADC_init();         // Inicializa el ADC

	while (1) {
		if (UCSR0A & (1 << RXC0)) {  // Verifica si hay un comando recibido
			char command = UDR0;
			processCommand(command, POT1, POT2);  // Procesa el comando
		}
	}
}
