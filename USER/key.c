/********************************************************************
 *@file        key.c
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       KEY��ʼ���Լ�ɨ�躯��
 *******************************************************************/
#include "flash_eeprom.h"
#include "delay.h"
#include "key.h"
#include "adc.h"
#include "tim1.h"
#include "led.h"

u8 number=0;
u8 Set_Flag=0;
u32 Set_Time=0;

/*******************************************************************************
 * ��������key_init
 * ����  ������key�ĳ�ʼ��
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void key_init(void)
{
    /* ����KEY�Ĺܽ�Ϊ����ģʽ */
    GPIO_Init(GPIOC, GPIO_PIN_7, GPIO_MODE_IN_PU_NO_IT);
    GPIO_Init(GPIOA, GPIO_PIN_1, GPIO_MODE_IN_PU_NO_IT);
}


/*******************************************************************************
 * ��������key_scan
 * ����  ������keyɨ�躯��,дEEPROM
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void key_scan(void)
{
    if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_7) == 0)
    {
        delay_ms(20);
        if(GPIO_ReadInputPin(GPIOC, GPIO_PIN_7) == 0)
        {
          number=1;
          Set_Flag=1;
          GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
        }
        else 
        {
           if(Set_Flag == 1)
           {
              GPIO_WriteLow(GPIOD, GPIO_PIN_3);
              number=0;
              Set_Flag=0;
              Set_Time= PWM_set;
              WriteEEPROM(Set_Time);
              LED_Study_End();
              PWM_set=0;
           }          
        }
    }else 
       if(Set_Flag == 1)
       {
          GPIO_WriteLow(GPIOD, GPIO_PIN_3);
          number=0;
          Set_Flag=0;  
          Set_Time= PWM_set; 
          WriteEEPROM(Set_Time);
          LED_Study_End();
          PWM_set=0;
       }
}

