#include "CFG_BCD_TO_DEC_TO_BCD.h"
//******************************************************************************
//***********************Conversor BCD a decimal********************************
//******************************************************************************
unsigned char DEC_TO_BCD(unsigned char dato)
{
    unidades = dato;
    decenas = dato;
    if (dato >9)
    {
        unidades = 0;
    }
    return dato;
}
//******************************************************************************
//***********************Conversor decimal a BCD********************************
//******************************************************************************
unsigned char BCD_TO_DEC(unsigned char dato)
{
    decenas = dato;
    unidades = dato;
//------------------------------------------------------------------------------    
    decenas = decenas>>4;
    decenas += 0x30;
//------------------------------------------------------------------------------
    if (unidades > 9)
    {
        unidades = unidades<<4;
        unidades /= 0x10;
    }
    unidades += 0x30;
//------------------------------------------------------------------------------    
    return decenas,unidades;
}