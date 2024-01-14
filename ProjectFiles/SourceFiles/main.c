/*=================================================================================*/
/*  File        : main.c                                                           */
/*  Description : This file is Application on stm32f401CC to Toogel LED            */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 1/5/2023                                                         */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
#include "STD_TYPES.h"
#include "RCC_Interface.h"
#include "GPIO_Interface.h"
#include "SYSTICK_Interface.h"

int StartPiontOfCode(void)
{
	RCC_voidInitSystemClock();
	STK_voidInit();
	RCC_voidEnablePeripheralClock(AHB1,0);
	GPIO_voidPinInit(GPIOA,PIN0,OUTPUT,PUSH_PULL,LOW_SPEED);
	GPIO_voidSetPinValueAtomic(GPIOA,PIN0,SET);
	while(1)
	{
		GPIO_voidSetPinValueAtomic(GPIOA,PIN0,SET);
		STK_voidSetBusyWait(100);
		GPIO_voidSetPinValueAtomic(GPIOA,PIN0,RST);
		STK_voidSetBusyWait(100);
	}
	return 0 ;
}
