/*********************************************************************************************
**********************************************************************************************
****** .File        : LinkerScriptForStm32f401xx                                              
****** .Description : Linker Script For STM32f, create all standered sections  
****** .Author      : Mohamed Ashour Hassan                       
****** .Date        : 5/1/2024
***********************************************************************************************
***********************************************************************************************                                                         
*/
/**** This object used to store the inial address of stack pointer ,that point to Ram ****/ 
_initStackPtr = ORIGIN(RAM) + LENGTH(RAM);
/**** The Main memories in system ***/
MEMORY 
{
/******* .Memory name/Type -------> Permmision(read/write) ------------> Memory base adderss ---------> MEMORY length ****/
    RAM    (rwx)  : ORIGIN = 0x20000000, LENGTH = 64K
    FLASH  (rx) : ORIGIN = 0x08000000, LENGTH = 256K
}
/********************* The Main Section in memories,We create any number of sections in any memory loction ************/
SECTIONS
{
/***** Create (.isr_vector) section use to store interrupt vector table in Flash for all interrupt sources *****************/
	.isr_vector :
	{
		*(.isr_vector)
		*(isr_vector*)
	}> FLASH
/***** Create (.init) section use to store Startup code in Falsh **********************************************************/
	.init :
	{
		*(.init)
		*(.init*)
	}>FLASH
/***** Create (.text) section use to store the app code and its insructions in Flash *************************************/
	.text :
	{
		*(.text)
		*(.text*)
	}> FLASH
/***** Create (.rodata) section use to store constant or read only objects in Flash ************************************/
	.rodata :
	{
		*(.rodata)
		*(.rodata*)
	}>FLASH
/***** Create (.data) section use to store the inialized Static & Global variable in Flash and then transfer to Ram ****/
	/*** This object use to store the first location of (.data) section of flash memory ****/
	startAdressOfDataSectionInFlash = LOADADDR(.data);
	.data :
	{
	/*** This object use to store the first location of (.data) section of Ram memory *******/
		startAdressOfDataSectionInRam = . ;
		*(.data)
		*(.data*)
		/*** This object use to store the last location of (.data) section of Ram memory ***/
		endAdressOfDataSectionInRam = . ;
	}> RAM AT > FLASH
	/***** Create (.bss) section use to store the uninialized Static & Global variable in Ram **************************/
	.bss :
	{
	/*** This object use to store the first location of (.bss) section of Ram memory *******/
		startAdderssOfBssSectionInRam = . ;
		*(.bss)
		*(.bss*)
		/*** This object use to store the last location of (.bss) section of Ram memory ****/
		endAdderssOfBssSectionInRam = . ;
	}> RAM
	
}