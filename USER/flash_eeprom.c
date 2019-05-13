/********************************************************************
 *@file        flash_eeprom.c
 *@author      Woody      QQ��2490006131
 *@version     V1.0
 *@date        2016-10-14
 *@brief       eeprom��ʼ��
 *******************************************************************/
#include "flash_eeprom.h"
#include "key.h"
#include "uart.h"
#include "tim1.h"
/*******************************************************************************
 * ��������Init_EEPROM
 * ����  ������EEPROM�ĳ�ʼ��
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 * ˵��  : ÿ���ͺŵ�EEPROM�Ĵ�С��һ�������ô˺�����ʱ��Ҫע�⽫Ҫд�����ֽ�����
         �Ĵ�С�Ƿ񳬹����ͺŵ�EEPROM�ĵ�ַ��
         ��������EEPROM���ͺ���STM8S208, STM8S207, STM8S007, STM8AF52Ax, STM8AF62Ax 
         EEPROM�ĵ�ַ�Ǵ�0x004000��0x0047ff����2048Byte,ÿ��Block��128Byte,һ��16��Block.
         BlockNum @ 1~16
         ��������EEPROM���ͺ���STM8S105, STM8S005, STM8AF626x
         EEPROM�ĵ�ַ�Ǵ�0x004000��0x0043ff����1024Byte,ÿ��Block��128Byte,һ��8��Block.
         BlockNum @ 1~8
         С������EEPROM���ͺ���STM8S103, STM8S003, STM8S903 
         EEPROM�ĵ�ַ�Ǵ�0x004000��0x00427f����1024Byte,ÿ��Block��64Byte,һ��10��Block.
         BlockNum @ 1~10
 ******************************************************************************/
void Init_EEPROM(void)
{
    FLASH_DeInit();
    //Define flash programming time.
    //���ʱ��Ϊ��׼���ʱ���һ��(1/2 tprog)
    FLASH_SetProgrammingTime(FLASH_PROGRAMTIME_STANDARD); 
}
/*******************************************************************************
 * ��������FLASH_Read_Word
 * ����  ����FLASH ��ȡһ��U32���͵�����
 * ����  ����
 * ���  ��u32�������
 * ����  ���ⲿ����
 ******************************************************************************/
u32 FLASH_Read_Word(u32 Address_temp)
{
  u32 temp;
  temp = (u32)FLASH_ReadByte(Address_temp+3) | ((u32)FLASH_ReadByte(Address_temp+2) << 8) |\
         ((u32)FLASH_ReadByte(Address_temp+1) << 16) | ((u32)FLASH_ReadByte(Address_temp) << 24);
  
  return(temp);
}
/*******************************************************************************
 * ��������WriteEEPROM
 * ����  ��WriteEEPROMдһ��U32���͵����ݵ�EEPROM
 * ����  ����
 * ���  ����
 * ����  ���ⲿ����
 ******************************************************************************/
void WriteEEPROM(u32 data)
{ 
  FLASH_Unlock(FLASH_MEMTYPE_DATA); // ����EEPROM
  
  FLASH_ProgramWord(0x00004000, data);
  FLASH_Lock(FLASH_MEMTYPE_DATA); 
} 

















