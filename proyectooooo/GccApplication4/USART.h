/*
 * USART.h
 *
 * Created: 08/11/2024 04:59:01 p. m.
 *  Author: emili
 */ 
#ifndef USART_H
#define USART_H

void USART_init(unsigned int ubrr);
void USART_sendData(const char *data);

#endif
