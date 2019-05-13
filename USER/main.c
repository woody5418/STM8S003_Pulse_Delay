/*************** (C) COPYRIGHT  四维拓智 ***************************************
 * 文件名  ：main.c
 * 描述    ：工程模板    
 * 库版本  ：V1.1.0
 * 开发人员：Woody QQ：2490006131
 * 修改时间：2016-10-14
*******************************************************************************/


/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "sysclock.h"
#include "tim1.h"
#include "delay.h"
#include "flash_eeprom.h"
#include "led.h"
#include "key.h"
#include "adc.h"

/*  Defines -----------------------------------------------------------*/
/*  Variate ---------------------------------------------------------*/
u8 flag_eeprom = 0; //读取EEPROM控制
u16 Fir_num=0;      //前一级ADC值读取
u8 delay_flag=0;    //延迟模式控制LED亮
u8 maichong_flag=0; //控制脉冲计数清零
u8 FLAG_DELAY=0;
u8 FLAG_MAICHONG=0;


int main(void)
{    
  /* 系统时钟初始化 */
  SystemClock_Init(); 
  
  delay_init(16);
  Init_EEPROM();
  TIM1_Init();
  key_init();
  LED_Init();
  ADC_Init();
  enableInterrupts(); 	/* 开启总中断 */
  
  GPIO_WriteLow(GPIOA, GPIO_PIN_2);  
  while (1)
  {
     if(flag_eeprom == 0)
     {
        flag_eeprom=1;
        Set_Time = FLASH_Read_Word(0x00004000);  
        if(Set_Time == 0)  Set_Time = 20;
        delay_ms(10);
     }
     key_scan();
     Fir_num = ADC1_GetConversionValue()/64;
     
     if(GPIO_ReadInputPin(GPIOA, GPIO_PIN_1) == 0) // 延迟
     {  
        FLAG_MAICHONG=0;        
        if(Fir_num > 700)  // H
        {
            delay_flag=0; //
            GPIO_WriteHigh(GPIOA, GPIO_PIN_2);
            delay_ms(5);
            count=0;
            Fir_num = ADC1_GetConversionValue()/64;
            if(Fir_num > 700)  
               FLAG_DELAY=0;
            else 
               FLAG_DELAY=1;        
        }else
           {
              FLAG_DELAY=1;  // L
              if(delay_flag == 0)
              {
                delay_flag=1;
                FLAG_DELAY=0;
                GPIO_WriteHigh(GPIOA, GPIO_PIN_2);
              }
           }
     }else   //脉冲
     { 
        FLAG_DELAY=0;
       if(Fir_num > 700)  // H
       {
          if(maichong_flag == 0)
          {
             maichong_flag=1;
             count=0;
             GPIO_WriteHigh(GPIOA, GPIO_PIN_2);
          }
          delay_flag=0; // 
          FLAG_MAICHONG=1;
          delay_ms(5);
          Fir_num = ADC1_GetConversionValue()/64;
          if(Fir_num > 700)  FLAG_MAICHONG=1;
           else FLAG_MAICHONG=0;        
       }else
       {
        FLAG_MAICHONG=0;  // L
        maichong_flag=0;
        GPIO_WriteLow(GPIOA, GPIO_PIN_2);
        //count=0;
      }
     
    }
  }
}

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8* file, u32 line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
    
  }
}
#endif






