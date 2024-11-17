/* 
 * File:   CFG_DS1307.h
 * Author: Familia CS
 *
 * Created on 10 de noviembre de 2024, 12:53
 */

#ifndef CFG_DS1307_H
#define	CFG_DS1307_H

#include "CFG_16F877A.h"

#ifdef	__cplusplus
extern "C" {
#endif

#define   _Dir_DS1307_W     0xD0
#define   _Dir_DS1307_R     0xD1
#define   _Salida_1seg      0x90
#define   _Registro_Ctr     0x07
#define   _Registro_Seg     0x00
#define   _Registro_Min     0x01
#define   _Registro_Hor     0x02
#define   _Registro_DiaSe   0x03
#define   _Registro_Dia     0x04
#define   _Registro_Mes     0x05
#define   _Registro_Ano     0x06
#define   _Registro_Stop    0x80
#define   _Registro_Borrar  0x00
#define   _Registro_AM_PM   0x40

unsigned char dato_ajuste_dia,dato_ajuste_dia_unidad,dato_ajuste_dia_decena,dato_ajuste_dia_lcd_unidad,dato_ajuste_dia_lcd_decena;    
    
void CFG_DS1307 (void);
void READ_DS1307 (void);
void AJUSTE_DS1307 (void);
void lectura_tiempo_posX (unsigned char registro_DS1307,unsigned char pos_uni,unsigned char pos_dec,unsigned char pos_D3,unsigned char caracter);
void lectura_tiempo_posY (unsigned char registro_DS1307,unsigned char pos_uni,unsigned char pos_dec,unsigned char pos_D3,unsigned char caracter);

#ifdef	__cplusplus
}
#endif

#endif	/* CFG_DS1307_H */

