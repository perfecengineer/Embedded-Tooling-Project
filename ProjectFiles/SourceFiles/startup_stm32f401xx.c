/*********************************************************************************************
**********************************************************************************************
****** .File        : startup_stm32f401xx                                               
****** .Description : Startup  code for STM32f401xx 
****** .Author      : Mohamed Ashour Hassan                       
****** .Date        : 5/1/2024
***********************************************************************************************
***********************************************************************************************                                                         
*/

#include "STD_TYPES.h"
#define LOGIC_LOW (0)
#define BSS_DATA_FOR_EACH_LOCATION LOGIC_LOW
#define RESERVED_LOCATION LOGIC_LOW 
/*************************************** Extern the variable from linker script file **********************************/
/************* The object has the inial address for stack pionter ***/
extern u32 _initStackPtr;
/************* The object has the start address of .data section in flash  ***/
extern u32 startAdressOfDataSectionInFlash;
/************* The object has the start address of .data section in Ram ***/
extern u32 startAdressOfDataSectionInRam;
/************* The object has the end address of .data section in Ram ***/
extern u32 endAdressOfDataSectionInRam;
/************* The object has the  start address of .Bss section in Ram ***/
extern u32 startAdderssOfBssSectionInRam;
/************* The object has the  end address of .Bss section in Ram ***/
extern u32 endAdderssOfBssSectionInRam;
/*************************************** Extern the main function from the application ********************************/
extern int StartPiontOfCode();
/************************* The all Prototype for each handler , using the weak and alies to aviod the linker errors ***/
/************************* Weak only, meaning that we have already implementation of this function ********************/
void __attribute__((weak))                                   Reset_Handler(void);
void __attribute__((weak))                                   Default_Handler(void);
/**** Weak and alies() ,mean we check the prototype first by useing weak, then if found -> execute it ,if not -> execute the alies function (defualt) ***/
void __attribute__((weak , alias("Default_Handler")))       NMI_Handler(void);      
void __attribute__((weak , alias("Default_Handler")))       HardFault_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       MemManage_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       BusFault_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       UsageFault_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SVCall_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DebugMonitor_Handeler(void);
void __attribute__((weak , alias("Default_Handler")))       PendSV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       Systick_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       WWDG_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       PVD_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TAMP_STAMP_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       RTC_WKUP_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       FLASH_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       RCC_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI0_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream0_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream6_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       ADC_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI9_5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_BRK_TIM9_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_UP_TIM10_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_TRG_COM_TIM11_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM1_CC_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C1_EV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C1_ER_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C2_EV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C2_ER_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       USART1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       USART2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       EXTI15_10_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       RTC_Alarm_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       OTG_FS_WKUP_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA1_Stream7_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SDIO_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       TIM5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream0_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream1_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream2_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream3_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream4_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       OTG_FS_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream5_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream6_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       DMA2_Stream7_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       USART6_handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C3_EV_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       I2C3_ER_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       FPU_Handler(void);
void __attribute__((weak , alias("Default_Handler")))       SPI4_Handler(void);
/**** Create the PTR_TO_FUN type, for next used ***/
typedef void (* const Ptr_Handler)(void);
/**** Select the section To store this object ***/
__attribute__((section(".isr_vector"),used))
/*** The Vector table's handlers ****/
Ptr_Handler Vector_Table[] = 
{
	/*** Resrved to stack pionter content ****/
	(Ptr_Handler)&_initStackPtr,
	/***** The function's address for each handler ****/
	Reset_Handler,
	NMI_Handler ,
    HardFault_Handler ,
    MemManage_Handler ,
    BusFault_Handler , 
    UsageFault_Handler ,
    RESERVED_LOCATION , //Reserved
    RESERVED_LOCATION , //Reserved
    RESERVED_LOCATION , //Reserved
    RESERVED_LOCATION , //Reserved
    SVCall_Handler ,
    DebugMonitor_Handeler ,
    RESERVED_LOCATION ,
    PendSV_Handler ,
    Systick_Handler ,
    WWDG_Handler ,
    PVD_Handler ,
    TAMP_STAMP_Handler ,
    RTC_WKUP_Handler ,
    FLASH_Handler ,
    RCC_Handler ,
    EXTI0_Handler ,
    EXTI1_Handler ,
    EXTI2_Handler ,
    EXTI3_Handler ,
    EXTI4_Handler ,
    DMA1_Stream0_Handler ,
    DMA1_Stream1_Handler ,
    DMA1_Stream2_Handler ,
    DMA1_Stream3_Handler ,
    DMA1_Stream4_Handler ,
    DMA1_Stream5_Handler ,
    DMA1_Stream6_Handler ,
    ADC_Handler ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION , 
    RESERVED_LOCATION , 
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    EXTI9_5_Handler ,
    TIM1_BRK_TIM9_Handler ,
    TIM1_UP_TIM10_Handler ,
    TIM1_TRG_COM_TIM11_Handler ,
    TIM1_CC_Handler ,
    TIM2_Handler ,
    TIM3_Handler ,
    TIM4_Handler ,
    I2C1_EV_Handler ,
    I2C1_ER_Handler ,
    I2C2_EV_Handler ,
    I2C2_ER_Handler ,
    SPI1_Handler ,
    SPI2_Handler ,
    USART1_Handler ,
    USART2_Handler ,
    RESERVED_LOCATION ,
    EXTI15_10_Handler , 
    RTC_Alarm_Handler ,
    OTG_FS_WKUP_Handler ,
    RESERVED_LOCATION , 
    RESERVED_LOCATION ,
    RESERVED_LOCATION , 
    RESERVED_LOCATION ,
    DMA1_Stream7_Handler ,
    RESERVED_LOCATION ,
    SDIO_Handler ,
    TIM5_Handler ,
    SPI3_Handler ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    DMA2_Stream0_Handler , 
    DMA2_Stream1_Handler ,
    DMA2_Stream2_Handler ,
    DMA2_Stream3_Handler ,
    DMA2_Stream4_Handler ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    OTG_FS_Handler ,
    DMA2_Stream5_Handler ,
    DMA2_Stream6_Handler ,
    DMA2_Stream7_Handler ,
    USART6_handler ,
    I2C3_EV_Handler ,
    I2C3_ER_Handler ,
    RESERVED_LOCATION , 
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    FPU_Handler ,
    RESERVED_LOCATION ,
    RESERVED_LOCATION ,
    SPI4_Handler 
	
};
/*** Select the .init section to write these objects i it  ***/
/*** The StartUp code implementation ***/
void __attribute__((section(".init"),used))				Reset_Handler(void)
{
/******************* Copy the (.data) section from Flash to Ram ***/
	/*** This object used to point to the first location of (.data) section in Flash ***/
	u32 *SourceFlashPionter    = (u32 *) &startAdressOfDataSectionInFlash;
	/*** This object used to point to the first location of (.data) section in Ram ***/
	u32 *DistinationRamPionter = (u32 *) &startAdressOfDataSectionInRam;
	/*** This object used to store the size of (.data) section in Ram ***/
	u32 SectionSize 		  = ((&endAdressOfDataSectionInRam) - (&startAdressOfDataSectionInRam));
	/*** counter use to count the locations in (.data) section in Ram ***/
	u32 ItreationNumber;
	/*** Loop from location to last one in (.data) section in Ram, Copy the data from Flash to Ram in this segmant ***/
	for(ItreationNumber = LOGIC_LOW; ItreationNumber < SectionSize; ItreationNumber ++)
	{
		/*** Assign and then increase the counter by one for new location ****/
		*DistinationRamPionter ++ = *SourceFlashPionter ++;
	}
/************************** Reserve the (.bss) section in Ram, iniat each location by BSS_DATA_FOR_EACH_LOCATION value ****/
	/*** Point to the first location of (.bss) section in Ram ***/
	DistinationRamPionter = (u32 *) &startAdderssOfBssSectionInRam;
	/*** Store the size of (.bss) section in Ram ***/
	SectionSize = ((&endAdderssOfBssSectionInRam) - (&startAdderssOfBssSectionInRam));
	for(ItreationNumber = LOGIC_LOW; ItreationNumber < SectionSize; ItreationNumber ++)
	{
		/*** Assign and then increase the counter by one for new location ****/
		*DistinationRamPionter ++ = BSS_DATA_FOR_EACH_LOCATION;
	}
	/****************** Call the main function ************************/
	StartPiontOfCode();// main()
	/*** This wait loop used after the  super loop in app is broken, CPU will stuck here ****/
	while(1);
}
void __attribute__((section(".init"),used))			   Default_Handler(void)
{
	/***** No thing ***/
	while(1);
}
