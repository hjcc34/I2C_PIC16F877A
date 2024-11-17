/*
 * File:   RELOJ_LCD_MAIN.c
 * Author: Familia CS
 *
 * Created on 9 de noviembre de 2024, 21:40
 */


#include <xc.h>
#include "CFG_16F877A.h"
#include "CFG_BCD_TO_DEC_TO_BCD.h"

void main(void) 
{
    TRISA = 0;                                                                  //Puerto A todos salida               
    TRISD = 0;                                                                  //Puerto D todos salidas
    TRISE = 0;                                                                  //Puerto E todos salidas
    TRISC = 0X83;                                                               //PORTC7, PORTC1 y PORTC0 como entradas
    TRISB = 0xFF;                                                               //Todos los pines de puerto B como entradas
    CMCON = 0x07;                                                               //DESACTIVA LOS COMPARADORES
    OPTION_REGbits.nRBPU = 0;                                                   //Activar push pull en puerto B
    PORTA = 0, PORTB = 0, PORTC = 0, PORTD = 0, PORTE = 0;                      //Limpiar todos los puertos
    CMCON = 0x07;                                                               //DESACTIVA LOS COMPARADORES
    ADCON1bits.PCFG3 = 0, ADCON1bits.PCFG2 = 1, ADCON1bits.PCFG1 = 1;           //DESACTIVA Entradas analogicas
//*************************Inicializar LCD**************************************
    Lcd_inicio();                                                               //Inicializar la LCD
//*************************Inicializar I2C**************************************
    I2C_Initialize();                                                           //Inicializando I2C
//*************************Configurar RS1307************************************
    CFG_DS1307();                                                               //Configura DS1307 a salida de 1seg
//*************************Mensaje de inicio LCD********************************    
    Lcd_print_string(6,"Reloj",5,"Digital");                                    //Mensaje de incio
    __delay_ms(3000);
    Lcd_cmd(_LCD_CLEAR);                                                        //Borrar LCD
//******************************************************************************
    I2C_Cmd(_Dir_DS1307_W,_Registro_Seg,0);                                     //Activacion del del reloj DS1307
    I2C_P();
//******************************************************************************
    while (1)
    {
        READ_DS1307();
        if (SEL_OK == 0)
        {
            Lcd_cmd(_LCD_CLEAR);
            AJUSTE_DS1307();
            Lcd_cmd(_LCD_CLEAR);
        }
    }
}
