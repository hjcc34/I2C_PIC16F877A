/* 
 * File:   CFG_16F877A.h
 * Author: Familia CS
 *
 * Created on May 14, 2023, 10:09 AM
 */

#ifndef CFG16F877A_H
#define	CFG16F877A_H

#pragma config FOSC = XT                                                        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF                                                       // Watchdog Timer Enable bit (WDT disabled)
#pragma config PWRTE = ON                                                       // Power-up Timer Enable bit (PWRT enabled)
#pragma config BOREN = ON                                                       // Brown-out Reset Enable bit (BOR enabled)
#pragma config LVP = OFF                                                        // Low-Voltage (Single-Supply) In-Circuit Serial Programming Enable bit (RB3 is digital I/O, HV on MCLR must be used for programming)
#pragma config CPD = OFF                                                        // Data EEPROM Memory Code Protection bit (Data EEPROM code protection off)
#pragma config WRT = OFF                                                        // Flash Program Memory Write Enable bits (Write protection off; all program memory may be written to by EECON control)
#pragma config CP = OFF                                                         // Flash Program Memory Code Protection bit (Code protection off)

#define _XTAL_FREQ 4000000

#include <xc.h>
#include <string.h>
#include <stdio.h>
#include "CFG_LCD_16x2.h"
#include "CFG_I2C.h"
#include "CFG_DS1307.h"

#define SEL_OK          PORTBbits.RB0                                           //Tecla OK 
#define DEC_2           PORTBbits.RB1                                           //Tecla hacia decremento
#define INC_1           PORTBbits.RB2                                           //Tecla hacia incremento
#define BEFORE_ATRAS    PORTBbits.RB3                                           //Tecla hacia izquierda
#define NEXT_3          PORTBbits.RB4                                           //Tecla derecha

#define ALARMA    PORTCbits.RC0                                                 //Salida alarma

#endif	/* CFG16F877A_H */

