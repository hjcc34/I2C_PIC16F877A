/* 
 * File:   CFG_LCD_16x2.h
 * Author: Familia CS
 *
 * Created on 9 de noviembre de 2024, 21:57
 */

#ifndef CFG_LCD_16X2_H
#define	CFG_LCD_16X2_H

#include "CFG_16F877A.h"

#define RS  TRISEbits.TRISE0                                                    //Rs del LCD
#define E   TRISEbits.TRISE2                                                    //Enable del LCD
#define D0  TRISDbits.TRISD0                                                    //D0
#define D1  TRISDbits.TRISD1                                                    //D1
#define D2  TRISDbits.TRISD2                                                    //D2
#define D3  TRISDbits.TRISD3                                                    //D3
#define D4  TRISDbits.TRISD4                                                    //D4
#define D5  TRISDbits.TRISD5                                                    //D5
#define D6  TRISDbits.TRISD6                                                    //D6
#define D7  TRISDbits.TRISD7                                                    //D7

#define Dato_RS PORTEbits.RE0                                                   //RS del LCD
#define Dato_E  PORTEbits.RE2                                                   //Enable de la LCD
#define Dato_D0 PORTDbits.RD0                                                   //D0
#define Dato_D1 PORTDbits.RD1                                                   //D1
#define Dato_D2 PORTDbits.RD2                                                   //D2
#define Dato_D3 PORTDbits.RD3                                                   //D3
#define Dato_D4 PORTDbits.RD4                                                   //D4
#define Dato_D5 PORTDbits.RD5                                                   //D5
#define Dato_D6 PORTDbits.RD6                                                   //D6
#define Dato_D7 PORTDbits.RD7                                                   //D7
//****************************Comandos LCD**************************************
#define      _LCD_FIRST_ROW           128
#define      _LCD_SECOND_ROW          192
#define      _LCD_THIRD_ROW           148
#define      _LCD_FOURTH_ROW          212
#define      _LCD_CLEAR               1
#define      _LCD_RETURN_HOME         2
#define      _LCD_CURSOR_OFF          12
#define      _LCD_UNDERLINE_ON        14
#define      _LCD_BLINK_CURSOR_ON     15
#define      _LCD_MOVE_CURSOR_LEFT    16
#define      _LCD_MOVE_CURSOR_RIGHT   20
#define      _LCD_TURN_OFF            0
#define      _LCD_TURN_ON             8
#define      _LCD_SHIFT_LEFT          24
#define      _LCD_SHIFT_RIGHT         28
//******************************************************************************
#ifdef	__cplusplus
extern "C" {
#endif
//*********************************Funciones************************************   
void Lcd_inicio(void);                                                          //Funcion de incializar la pantalla LCD
void Lcd_print_string(unsigned char POSx,char *String_x,unsigned char POSy,char *String_y);    //Imprimir en x,y un string
void Lcd_cmd(unsigned char comando);                                            //Envio de comando para LCD
void Lcd_out_cmd(void);
void Lcd_out_data(void);
void Lcd_Write_String(char *a);                                                 //Envio de cadena de caracteres
void Lcd_Write_Char(unsigned char a);                                           //Envio de caracter
void Lcd_pos_x (unsigned char POSx);
void Lcd_pos_y (unsigned char POSy);

#endif	/* CFG_LCD_16X2_H */

