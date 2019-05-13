/********************************************************************
 *@file        tim1.c
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       tim1 ��ʼ����PWM����
 *******************************************************************/
#include "tim1.h"
#include "led.h"
#include "key.h"
#include "delay.h"


u32  PWM_set=0;  // ѧϰ����ģʽ
u32  count=0;    // ѧϰʱ���������
/*******************************************************************************
 * ��������TIM1_Init
 * ����  ������TIM1_Init�ĳ�ʼ��
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void TIM1_Init(void)
{
  TIM1->PSCRH = 0x3E; // ϵͳʱ�Ӿ�Ԥ��Ƶf=fck/(PSCR+1)
  TIM1->PSCRL = 0x7F; // PSCR=0x3E7F�� f=16M/(0x3E7F+1)=1000Hz,ÿ����������1ms
  TIM1->ARRH = 0x00; // �Զ����ؼĴ���ARR=0x32=50
  TIM1->ARRL = 0x32; // ÿ����50�β���һ���жϣ���50ms
  TIM1->IER |= 0x01; // ��������ж�
  TIM1->CR1 |= 0x01; // ������ʹ�ܣ���ʼ����
}


/*******************************************************************************
 * ��������TIM1_UPD_OVF_TRG_BRK_IRQHandler
 * ����  ��TIM1�жϣ���������PWM��
 * ����  ����
 * ���  ����
 * ����  ����
 ******************************************************************************/
#pragma vector=0xD     //11+2
__interrupt void TIM1_UPD_OVF_TRG_BRK_IRQHandler(void)//����жϣ����Ŀ���ָ��75ҳ
{
  TIM1->SR1 = 0; //����жϱ��
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










