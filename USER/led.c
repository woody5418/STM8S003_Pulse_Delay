/********************************************************************
 *@file        led.c
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       LED ��ʼ���Լ�LED_Show����
 *******************************************************************/
#include "led.h"
#include "delay.h"
/*******************************************************************************
 * ��������LED_Init
 * ����  ������LED_Init�ĳ�ʼ������
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void LED_Init(void)
{       
    //����LED�Ĺܽ�Ϊ���ģʽ
   GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_OUT_PP_LOW_FAST );  //OUT
    GPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_OUT_PP_LOW_FAST );  //OUT
}
/*******************************************************************************
 * ��������LED_Config
 * ����  ������LED��ʼ������
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void LED_Config(GPIO_Pin_TypeDef led, u8 state)
{
    if(ON == state) 
    {
        GPIO_WriteLow(LED_PORT, led);
    }
    else
    {
        GPIO_WriteHigh(LED_PORT, led);
    }
}
/*******************************************************************************
 * ��������LED_Study_End
 * ����  ��ѧϰ�����Ժ�Ч������
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void LED_Study_End(void)
{
   GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
   delay_ms(40);
   GPIO_WriteLow(GPIOD, GPIO_PIN_3);
   delay_ms(40);
   GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
   delay_ms(40);
   GPIO_WriteLow(GPIOD, GPIO_PIN_3);
   delay_ms(40);
   GPIO_WriteHigh(GPIOD, GPIO_PIN_3);
   delay_ms(40);
   GPIO_WriteLow(GPIOD, GPIO_PIN_3);
   delay_ms(40);
}
/*******************************************************************************
 * ��������LED_Show
 * ����  ������LED_Show��ʼ������
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void LED_Show(void)
{
    LED_Config(LED_1, OFF);// ��
    delay_ms(40);
    LED_Config(LED_1, ON);//  ��
    delay_ms(40);
    
     LED_Config(LED_1, OFF);// ��
    delay_ms(40);
    LED_Config(LED_1, ON);//  ��
    delay_ms(40);

     LED_Config(LED_1, OFF);// ��
    delay_ms(40);
    LED_Config(LED_1, ON);//  ��
    delay_ms(40);
    
     LED_Config(LED_1, OFF);// ��
    delay_ms(40);
    LED_Config(LED_1, ON);//  ��
    delay_ms(40);
    
     LED_Config(LED_1, OFF);// ��
    delay_ms(40);
    LED_Config(LED_1, ON);//  ��
    delay_ms(40);
}


