/********************************************************************
 *@file        flash_eeprom.h
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       EEPROM��ʼ���Լ���ȡ/д������
 *******************************************************************/
#ifndef __FLASH_EEPROM_H
#define __FLASH_EEPROM_H

#include "stm8s.h"

void Init_EEPROM(void);  // ��ʼ��
void WriteEEPROM(u32 data);
u32 FLASH_Read_Word(u32 Address_temp);



#endif


