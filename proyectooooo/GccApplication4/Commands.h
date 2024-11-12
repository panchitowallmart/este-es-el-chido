/*
 * Commands.h
 *
 * Created: 08/11/2024 04:59:41 p. m.
 *  Author: emili
 */ 

#ifndef COMMANDS_H
#define COMMANDS_H

#include "USART.h"
#include "ADC.h"

void processCommand(char command, int potPin1, int potPin2);

#endif
