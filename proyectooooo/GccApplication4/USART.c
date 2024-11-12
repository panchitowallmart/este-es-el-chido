/*
 * USART.c
 *
 * Created: 08/11/2024 04:56:12 p. m.
 *  Author: emili
 */ 

#include "USART.h"
#include <avr/io.h>

void USART_init(unsigned int ubrr) {
	UBRR0H = (unsigned char)(ubrr >> 8);
	UBRR0L = (unsigned char)ubrr;
	UCSR0B = (1 << RXEN0) | (1 << TXEN0); // Habilita RX y TX
	UCSR0C = (1 << UCSZ01) | (1 << UCSZ00); // Configura 8 bits de datos y 1 bit de parada
}

void USART_sendData(const char *data) {
	while (*data) {
		while (!(UCSR0A & (1 << UDRE0))); // Espera a que el registro de datos esté vacío
		UDR0 = *data; // Envía el dato
		data++;
	}
}
