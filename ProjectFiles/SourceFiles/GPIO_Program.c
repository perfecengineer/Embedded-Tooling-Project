/*=================================================================================*/
/*  File        : GPIO_Program.c                                                   */
/*  Description : This file includes GPIO Driver implementations for stm32f401CC   */
/*  Author      : Ahmed Bahaa Taha Nasr. Embedded SW Engineer                      */
/*  Date        : 12/5/2023                                                        */
/*  Linkedin    : https://www.linkedin.com/in/ahmed-bahaa1/                        */
/*  Git account : https://github.com/ahmedbahaa11                                  */
/*  mail        : abahaa14842@gmil.com                                             */
/*=================================================================================*/
/*==========================================*/
/* Include Header Files From include Folder */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
/*==========================================*/
#include "GPIO_Interface.h"
#include "GPIO_Private.h"
#include "GPIO_Config.h"
/*==========================================*/

/*====================================================================================================*/
/*=========================     A.BAHAA GPIO Functions Implementation      ===========================*/
/*====================================================================================================*/
/*********************************    GPIO_voidPinInit                   ******************************/
/*********************************    GPIO_voidSetPinMode                ******************************/ 
/*********************************    GPIO_voidSetPinType                ******************************/ 
/*********************************    GPIO_voidSetPinSpeed               ******************************/ 
/*********************************    GPIO_voidSetPinValueNonAtomic      ******************************/ 
/*********************************    GPIO_voidSetPinValueAtomic         ******************************/ 
/*********************************    GPIO_u8GetPinValue                 ******************************/ 
/*********************************    GPIO_voidPortInit                  ******************************/ 
/*********************************    GPIO_voidSetPortMode               ******************************/ 
/*********************************    GPIO_voidSetPortType               ******************************/
/*********************************    GPIO_voidSetPortSpeed              ******************************/
/*====================================================================================================*/

/*==============================================================================================*/
/* ==============================        Init Functions          ===============================*/
/*==============================================================================================*/
/************************************************************************************************/
/* Function Name : GPIO_voidPinInit                                                             */
/* Description : Inilization of Pin {Mode,Type,Speed}                                           */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument4: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument5: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPinInit(u8 Copy_u8PortID ,u8 Copy_u8PinID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed)
{
    /* i/p Validation */
    if ( Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 || Copy_u8Mode > ANALOG || Copy_u8Type > PULL_DOWN || Copy_u8Speed >  HIGH_SPEED )
    {
        /* Do Nothing */
    }
    else
    {
        GPIO_voidSetPinMode (Copy_u8PortID , Copy_u8PinID , Copy_u8Mode );
        GPIO_voidSetPinType (Copy_u8PortID , Copy_u8PinID , Copy_u8Type );
        if ( Copy_u8Mode == OUTPUT )
        {
            GPIO_voidSetPinSpeed(Copy_u8PortID , Copy_u8PinID , Copy_u8Speed);
        }
    }
}

/************************************************************************************************/
/* Function Name : GPIO_voidSetPinMode                                                          */
/* Description : Inilization of Pin {Mode}                                                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinMode(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Mode )
{
    /* i/p Validation */
    if ( Copy_u8Mode > ANALOG || Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 )
    {
        /* Do Nothing */
    }
    else
    {
        switch(Copy_u8Mode)
        {
            case OUTPUT : 
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            SET_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            SET_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            SET_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }
                            break;
            case INPUT  :  
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            CLEAR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            CLEAR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            CLEAR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            } 
                            break;
            case ALTERNATE :  
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            CLEAR_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                                            SET_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            CLEAR_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                                            SET_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            CLEAR_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                                            SET_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }    
                            break;
            case ANALOG : 
                        switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            SET_BIT(GPIOA_MODER,(Copy_u8PinID*2));
                                            SET_BIT(GPIOA_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            SET_BIT(GPIOB_MODER,(Copy_u8PinID*2));
                                            SET_BIT(GPIOB_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            SET_BIT(GPIOC_MODER,(Copy_u8PinID*2));
                                            SET_BIT(GPIOC_MODER,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }    
                            break;
            default :       break;  
        }
    }  
}

/************************************************************************************************/
/* Function Name : GPIO_voidSetPinType                                                          */
/* Description : Inilization of Pin {Type}                                                      */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinType(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Type )
{
    /* i/p Validation */
    if ( Copy_u8Type > PULL_DOWN || Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 )
    {
        /* Do Nothing */
    }
    else
    {
        switch(Copy_u8Type)
        {
            case PUSH_PULL : 
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA :    CLEAR_BIT(GPIOA_OTYPER,Copy_u8PinID);     break;
                                case GPIOB :    CLEAR_BIT(GPIOB_OTYPER,Copy_u8PinID);     break;
                                case GPIOC :    CLEAR_BIT(GPIOC_OTYPER,Copy_u8PinID);     break;
                                default    :                                              break;
                            }
                            break;
            case OPEN_DRAIN  :  
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA :    SET_BIT(GPIOA_OTYPER,Copy_u8PinID);     break;
                                case GPIOB :    SET_BIT(GPIOB_OTYPER,Copy_u8PinID);     break;
                                case GPIOC :    SET_BIT(GPIOC_OTYPER,Copy_u8PinID);     break;
                                default    :                                            break;
                            }
                            break;
            case NO_PULL_UP_DOWM :  
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            CLEAR_BIT(GPIOA_INPUT_TYPE,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOA_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            CLEAR_BIT(GPIOB_INPUT_TYPE,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOB_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            CLEAR_BIT(GPIOC_INPUT_TYPE,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOC_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }    
                            break;
            case PULL_UP : 
                        switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            SET_BIT(GPIOA_INPUT_TYPE,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOA_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            SET_BIT(GPIOB_INPUT_TYPE,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOB_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            SET_BIT(GPIOC_INPUT_TYPE,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOC_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }    
                            break;
            case PULL_DOWN :
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            CLEAR_BIT(GPIOA_INPUT_TYPE,(Copy_u8PinID*2));
                                            SET_BIT(GPIOA_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            CLEAR_BIT(GPIOB_INPUT_TYPE,(Copy_u8PinID*2));
                                            SET_BIT(GPIOB_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            CLEAR_BIT(GPIOC_INPUT_TYPE,(Copy_u8PinID*2));
                                            SET_BIT(GPIOC_INPUT_TYPE,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }    
                            break;
            default :       break;  
        }
    }
}

/************************************************************************************************/
/* Function Name : GPIO_voidSetPinSpeed                                                         */
/* Description : Inilization of Pin {Speed}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                               */
/* Fun. Argument3: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPinSpeed(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Speed )
{
    /* i/p Validation */
    if ( Copy_u8Speed > HIGH_SPEED || Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 )
    {
        /* Do Nothing */
    }
    else
    {
        switch(Copy_u8Speed)
        {
            case LOW_SPEED : 
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            CLEAR_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOA_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            CLEAR_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOB_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            CLEAR_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOC_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }
                            break;
            case MEDIUM_SPEED  :  
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            SET_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOA_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            SET_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOB_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            SET_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2));
                                            CLEAR_BIT(GPIOC_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            } 
                            break;
            case HIGH_SPEED :  
                            switch(Copy_u8PortID)  
                            {
                                case GPIOA : 
                                            CLEAR_BIT(GPIOA_OSPEEDR,(Copy_u8PinID*2));
                                            SET_BIT(GPIOA_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOB :
                                            CLEAR_BIT(GPIOB_OSPEEDR,(Copy_u8PinID*2));
                                            SET_BIT(GPIOB_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                case GPIOC :
                                            CLEAR_BIT(GPIOC_OSPEEDR,(Copy_u8PinID*2));
                                            SET_BIT(GPIOC_OSPEEDR,((Copy_u8PinID*2)+1));
                                            break;
                                default :   break;
                            }   
                            break;
            default :       break;  
        }
    }
}

/************************************************************************************************/
/* Function Name : GPIO_voidPortInit                                                            */
/* Description : Inilization of Port {Mode,Type,Speed}                                          */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Argument3: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Argument4: Copy_u8Speed {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                             */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidPortInit(u8 Copy_u8PortID ,u8 Copy_u8Mode ,u8 Copy_u8Type ,u8 Copy_u8Speed)
{
    /* i/p Validation */
    if ( Copy_u8PortID > GPIOC || Copy_u8Mode > ANALOG || Copy_u8Type > PULL_DOWN || Copy_u8Speed >  HIGH_SPEED )
    {
        /* Do Nothing */
    }
    else
    {
        GPIO_voidSetPortMode( Copy_u8PortID , Copy_u8Mode );
        GPIO_voidSetPortType( Copy_u8PortID , Copy_u8Type );
        if ( Copy_u8Mode == OUTPUT )
        {
            GPIO_voidSetPortSpeed( Copy_u8PortID , Copy_u8Speed );
        }
    }
}

/************************************************************************************************/
/* Function Name : GPIO_voidSetPortMode                                                         */
/* Description : Inilization of Port {Mode}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Mode { OUTPUT , INPUT , ALTERNATE , ANALOG }                          */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortMode(u8 Copy_u8PortID , u8 Copy_u8Mode )
{
    for ( u8 Pin = 0 ; Pin < 16 ; Pin++ )
    {
        GPIO_voidSetPinMode( Copy_u8PortID , Pin , Copy_u8Mode );
    }  
}

/************************************************************************************************/
/* Function Name : GPIO_voidSetPortType                                                         */
/* Description : Inilization of Port {Type}                                                     */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Type  {PUSH_PULL,OPEN_DRAIN,NO_PULL_UP_DOWM,PULL_UP,PULL_DOWN }       */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortType(u8 Copy_u8PortID , u8 Copy_u8Type )
{
    for ( u8 Pin = 0 ; Pin < 16 ; Pin++ )
    {
        GPIO_voidSetPinType( Copy_u8PortID , Pin , Copy_u8Type );
    }  
}

/************************************************************************************************/
/* Function Name : GPIO_voidSetPortSpeed                                                        */
/* Description : Inilization of Port {Speed}                                                    */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                          */
/* Fun. Argument2: Copy_u8Speed  {LOW_SPEED,MEDIUM_SPEED,HIGH_SPEED}                            */
/* Fun. Return : void                                                                           */
/************************************************************************************************/
void GPIO_voidSetPortSpeed(u8 Copy_u8PortID , u8 Copy_u8Speed )
{
    for ( u8 Pin = 0 ; Pin < 16 ; Pin++ )
    {
        GPIO_voidSetPinSpeed( Copy_u8PortID , Pin , Copy_u8Speed );
    }  
}



/*========================================================================================*/
/* ===========================         Write Modules          ============================*/
/*========================================================================================*/
/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueNonAtomic                                          */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { HIGH , LOW }                                            */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueNonAtomic(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8Value )
{
    /* i/p Validation */
    if ( Copy_u8Value > HIGH || Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 )
    {
        /* Do Nothing */
    }
    else
    {
        switch(Copy_u8Value)
        {
            case LOW : 
                        switch(Copy_u8PortID)  
                        {
                            case GPIOA :    CLEAR_BIT(GPIOA_ODR,Copy_u8PinID);     break;
                            case GPIOB :    CLEAR_BIT(GPIOB_ODR,Copy_u8PinID);     break;
                            case GPIOC :    CLEAR_BIT(GPIOC_ODR,Copy_u8PinID);     break;
                            default    :                                           break;
                        }
                        break;
            case HIGH  :  
                        switch(Copy_u8PortID)  
                        {
                            case GPIOA :    SET_BIT(GPIOA_ODR,Copy_u8PinID);     break;
                            case GPIOB :    SET_BIT(GPIOB_ODR,Copy_u8PinID);     break;
                            case GPIOC :    SET_BIT(GPIOC_ODR,Copy_u8PinID);     break;
                            default    :                                         break;
                        }
                        break;
            default :   break;
        }
    }
}

/******************************************************************************************/
/* Function Name : GPIO_voidSetPinValueAtomic                                             */
/* Description : Write value for one bit of the GPIO register                             */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                                    */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                                         */
/* Fun. Argument3: Copy_u8Value { SET , RST }                                             */
/* Fun. Return : void                                                                     */
/******************************************************************************************/
void GPIO_voidSetPinValueAtomic(u8 Copy_u8PortID , u8 Copy_u8PinID , u8 Copy_u8SenseLevel )
{
    /* i/p Validation */
    if ( Copy_u8SenseLevel > RST || Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 )
    {
        /* Do Nothing */
    } 
    else
    {
        switch(Copy_u8SenseLevel)
        {
            case SET :
                        switch (Copy_u8PortID)
                        {
                            case GPIOA :    GPIOA_BSRR = (1<<Copy_u8PinID);     break;
                            case GPIOB :    GPIOB_BSRR = (1<<Copy_u8PinID);     break;
                            case GPIOC :    GPIOC_BSRR = (1<<Copy_u8PinID);     break;
                            default    :                                        break;
                        }
                        break;
            case RST :
                        switch (Copy_u8PortID)
                        {
                            case GPIOA :    GPIOA_BSRR = (1<<(Copy_u8PinID+16));     break;
                            case GPIOB :    GPIOB_BSRR = (1<<(Copy_u8PinID+16));     break;
                            case GPIOC :    GPIOC_BSRR = (1<<(Copy_u8PinID+16));     break;
                            default    :                                             break;
                        }
                        break;
            default :   break;
        }
    }
}


/*==========================================================================*/
/*======================         Read Modules          =====================*/
/*==========================================================================*/
/****************************************************************************/
/* Function Name : GPIO_u8GetPinValue                                       */
/* Description : Read pin value from one bit of the Port register           */
/* Fun. Argument1: Copy_u8PortID { GPIOA,GPIOB,GPIOC }                      */
/* Fun. Argument2: Copy_u8PinID { PIN0 -> PIN15 }                           */
/* Fun. Return :  unsigned char   { HIGH , LOW }                            */
/****************************************************************************/
u8 GPIO_u8GetPinValue(u8 Copy_u8PortID , u8 Copy_u8PinID )
{
    u8 Local_u8Variable;
    /* i/p validation */
    if ( Copy_u8PortID > GPIOC || Copy_u8PinID > PIN15 )
    {
        // Do Nothing
    }
    else
    {
        switch(Copy_u8PortID)
        {
            case GPIOA :    Local_u8Variable = GET_BIT( GPIOA_IDR ,Copy_u8PinID );   break;   
            case GPIOB :    Local_u8Variable = GET_BIT( GPIOB_IDR ,Copy_u8PinID );   break;
            case GPIOC :    Local_u8Variable = GET_BIT( GPIOC_IDR ,Copy_u8PinID );   break;
            default :                                                                break;
        }
    }
    return Local_u8Variable ;
}

