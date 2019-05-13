/********************************************************************
 *@file        tim1.h
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       tim1  初始化以及PWM设置
 *******************************************************************/
#ifndef __TIM1_H
#define __TIM1_H

#include "stm8s.h"

extern u32 PWM_set;
extern u32 count;
extern u8 flag_flag;
extern u8 FLAG_DELAY;
extern u8 FLAG_MAICHONG;

void TIM1_Init(void);
void PWM_SET(void);

#endif