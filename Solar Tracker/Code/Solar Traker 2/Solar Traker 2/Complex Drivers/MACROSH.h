/*
 * MACROSH.h
 *
 * Created: 6/19/2019 6:24:02 PM
 *  Author: shaher
 *This file for the Macros that Used mostly
 */ 


#ifndef MACROSH_H_
#define MACROSH_H_

  #define Set_Bit(reg,bit)        (reg|=(1<<(bit)))
  #define Clear_Bit(reg,bit)      (reg&=(~(1<<(bit))))
  #define Toggle_Bit(reg,bit)     (reg^=(1<<(bit))
  #define Bit_Is_Set(reg,bit)     (reg&(1<<(bit)))
  #define Bit_Is_Clear(reg,bit)   (!Bit_Is_Set)
  
#endif /* MACROSH_H_ */