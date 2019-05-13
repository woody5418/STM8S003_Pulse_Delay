/********************************************************************
 *@file        tim1.c
 *@author      Woody      QQ：2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       tim1 初始化，PWM设置
 *******************************************************************/
#include "tim1.h"
#include "led.h"
#include "key.h"
#include "delay.h"


u32  PWM_set=0;  // 学习计数模式
u32  count=0;    // 学习时间计数控制
/*******************************************************************************
 * 函数名：TIM1_Init
 * 描述  ：配置TIM1_Init的初始化
 * 输入  ：无
 * 输出  ：无
 * 调用  ：外部调用
 ******************************************************************************/
void TIM1_Init(void)
{
  TIM1->PSCRH = 0x3E; // 系统时钟经预分频f=fck/(PSCR+1)
  TIM1->PSCRL = 0x7F; // PSCR=0x3E7F， f=16M/(0x3E7F+1)=1000Hz,每个计数周期1ms
  TIM1->ARRH = 0x00; // 自动重载寄存器ARR=0x32=50
  TIM1->ARRL = 0x32; // 每记数50次产生一次中断，即50ms
  TIM1->IER |= 0x01; // 允许更新中断
  TIM1->CR1 |= 0x01; // 计数器使能，开始计数
}


/*******************************************************************************
 * 函数名：TIM1_UPD_OVF_TRG_BRK_IRQHandler
 * 描述  ：TIM1中断，用于配置PWM波
 * 输入  ：无
 * 输出  ：无
 * 调用  ：无
 ******************************************************************************/
#pragma vector=0xD     //11+2
__interrupt void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void)//溢出中断，中文开发指南75页
{
  TIM1->SR1 = 0; //清除中断标记
  if(number == 1)
  {
    // PWM_set = Set_Time;
     PWM_set++;
  }
  else if(number == 0)
  {
    if(FLAG_MAICHONG == 1) 
    {
     count++;
     if(count >= Set_Time)
     {
        count = 0;
        GPIO_WriteReverse(GPIOA, GPIO_PIN_2);
     }
    }
    //////////////////////
    if(FLAG_DELAY == 1)
    {
      count++;
      if(count >= Set_Time)
       {
          count = 0;
          FLAG_DELAY=0;
          GPIO_WriteLow(GPIOA, GPIO_PIN_2);
       }
    }
  }
}










