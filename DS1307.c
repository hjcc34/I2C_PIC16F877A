#include "CFG_DS1307.h"
#include "CFG_BCD_TO_DEC_TO_BCD.h"

//******************************************************************************
//****************************CFG DS1307 1seg***********************************
//******************************************************************************
void CFG_DS1307()
{
    I2C_Cmd(_Dir_DS1307_W,_Registro_Ctr,_Salida_1seg);                          //Configurar salida de 1seg el DS1307
    I2C_P();                                                                    //Stop de I2C
}
//******************************************************************************
//************************LECTURA DE TIEMPO Posicion X**************************
void lectura_tiempo_posX(unsigned char registro_DS1307,unsigned char pos_uni,unsigned char pos_dec,unsigned char pos_D3,unsigned char caracter)
{
        I2C_Write(_Dir_DS1307_W,registro_DS1307,_Dir_DS1307_R);
        I2C_Read();
        BCD_TO_DEC(DATO_I2C);
        Lcd_pos_x(pos_uni);
        Lcd_Write_Char(unidades);
        Lcd_pos_x(pos_dec);
        Lcd_Write_Char(decenas);
        Lcd_pos_x(pos_D3);
        Lcd_Write_Char(caracter);    
}
//******************************************************************************
//************************LECTURA DE TIEMPO Posicion Y**************************
void lectura_tiempo_posY(unsigned char registro_DS1307,unsigned char pos_uni,unsigned char pos_dec,unsigned char pos_D3,unsigned char caracter)
{
        I2C_Write(_Dir_DS1307_W,registro_DS1307,_Dir_DS1307_R);
        I2C_Read();
        BCD_TO_DEC(DATO_I2C);
        Lcd_pos_y(pos_uni);
        Lcd_Write_Char(unidades);
        Lcd_pos_y(pos_dec);
        Lcd_Write_Char(decenas);
        Lcd_pos_y(pos_D3);
        Lcd_Write_Char(caracter);    
}
//**************************LECTURA DE SEGUNDOS*********************************
void READ_DS1307 (void)
{
    lectura_tiempo_posX(_Registro_Seg,12,11,10,':');
    lectura_tiempo_posX(_Registro_Min,9,8,7,':');
    lectura_tiempo_posX(_Registro_Hor,6,5,4,' ');
    lectura_tiempo_posY(_Registro_Dia,12,11,10,'-');
    lectura_tiempo_posY(_Registro_Mes,9,8,7,'-');
    lectura_tiempo_posY(_Registro_Ano,6,5,4,'0');
    Lcd_pos_y(3);
    Lcd_Write_Char('2');
}
//******************************************************************************
//*************************MENU PRINCIPAL***************************************
//******************************************************************************
void AJUSTE_DS1307(void)
{
    while (BEFORE_ATRAS == 1)                                                   //Bucle principal, se desactiv con INC y DEC
    {
        Lcd_print_string(1,"1.Ajuste Fecha",1,"2.Ajuste de Hora");              //Imprimo menu principal
//******************************************************************************    
//*****************************Menu de Fecha************************************
//******************************************************************************        
        if (INC_1 == 0)                                                         //Selecciono Fecha
        {
            __delay_ms(500);
            Lcd_cmd(_LCD_CLEAR);                                                //Borro LCD
            while (BEFORE_ATRAS == 1)           
            {
                Lcd_print_string(1,"1.Dia     3.Ano",1,"2.Mes");                //Menu de fecha
//-------------------------Menu ajsute de dia-----------------------------------                
                if (INC_1 == 0)                                                 //Selecciona dia (INC)
                {
                    __delay_ms(500);
                    Lcd_cmd(_LCD_CLEAR);                                        //Borro LCD
                    dato_ajuste_dia_lcd_unidad = 0;
                    dato_ajuste_dia_lcd_decena = 0;                    
                    dato_ajuste_dia = 0;
                    dato_ajuste_dia_unidad = 0;
                    dato_ajuste_dia_decena = 0;                    
                    dato_ajuste_dia_lcd_unidad += 0x30;
                    dato_ajuste_dia_lcd_decena += 0x30;                    
                    while (BEFORE_ATRAS == 1)
                    {
                        Lcd_print_string(2,"Ajuste de dia",1,"");               //Ajuste de dia
                        Lcd_pos_y(9);
                        Lcd_Write_Char(dato_ajuste_dia_lcd_unidad);                           //imprimir unidad
                        Lcd_pos_y(8);
                        Lcd_Write_Char(dato_ajuste_dia_lcd_decena);                            //imprimir decena
                        if (INC_1 == 0)                                         //Funcion de incrementar
                        {
                            __delay_ms(1000);
                            dato_ajuste_dia += 1;                                  //incrementar en 1
                            if (dato_ajuste_dia >9)
                            {
                                dato_ajuste_dia_unidad = 0;
                                dato_ajuste_dia_decena = 1;
                                dato_ajuste_dia_decena = dato_ajuste_dia_decena<<4;
                                
                            }                        
                            dato_ajuste_dia_lcd_unidad = dato_ajuste_dia;
                            dato_ajuste_dia_lcd_unidad += 0x30;
                            dato_ajuste_dia_lcd_decena = dato_ajuste_dia;
                            dato_ajuste_dia_lcd_decena += 0x30;
                        }
                        if (DEC_2 == 0)                                         //Funcion de decrementar
                        {
                            __delay_ms(1000);
                            dato_ajuste_dia -= 1;                                  //decrementar en 1
                            dato_ajuste_dia_lcd_unidad = dato_ajuste_dia;
                            dato_ajuste_dia_lcd_unidad += 0x30;                        
                        }                        
                        if (SEL_OK == 0)
                        {
                            __delay_ms(1000);
                            I2C_Cmd(_Dir_DS1307_W,_Registro_Dia,dato_ajuste_dia);
                            I2C_P();
                            Lcd_cmd(_LCD_CLEAR);
                            break;
                        }                        
                    }    
                }    
//-------------------------Menu ajsute de Mes-----------------------------------
                if (DEC_2 == 0)
                {
                    Lcd_cmd(_LCD_CLEAR);                                        //Borro LCD
                    while (BEFORE_ATRAS == 1)
                    {
                        Lcd_print_string(2,"Ajuste de Mes",1,"");               //Ajuste de dia
                        if (BEFORE_ATRAS == 0)
                        {
                            break;                                              //Salir del menu
                        }
                    }
                }
//-------------------------Menu ajsute de Ano-----------------------------------                
                if (NEXT_3 == 0)
                {
                    Lcd_cmd(_LCD_CLEAR);                                        //Borro LCD
                    while (BEFORE_ATRAS == 1)
                    {
                        Lcd_print_string(2,"Ajuste de Ano",1,"");               //Ajuste de dia
                        if (BEFORE_ATRAS == 0)
                        {
                            break;                                              //Salir del menu
                        }
                    }
                }
            }         
        }
    }          
//******************************************************************************    
//*****************************Menu de Tiempo***********************************
//******************************************************************************    
//-------------------------Menu ajsute de Hora----------------------------------    
//-------------------------Menu ajsute de Minutos-------------------------------    
//-------------------------Menu ajsute de Segundos------------------------------    
//------------------------------------------------------------------------------ 
}