/*******************************************************************************
* File Name: stepCtrl1.h  
* Version 2.20
*
* Description:
*  This file contains Pin function prototypes and register defines
*
* Note:
*
********************************************************************************
* Copyright 2008-2015, Cypress Semiconductor Corporation.  All rights reserved.
* You may use this file only in accordance with the license, terms, conditions, 
* disclaimers, and limitations in the end user license agreement accompanying 
* the software package with which this file was provided.
*******************************************************************************/

#if !defined(CY_PINS_stepCtrl1_H) /* Pins stepCtrl1_H */
#define CY_PINS_stepCtrl1_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "stepCtrl1_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 stepCtrl1__PORT == 15 && ((stepCtrl1__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    stepCtrl1_Write(uint8 value);
void    stepCtrl1_SetDriveMode(uint8 mode);
uint8   stepCtrl1_ReadDataReg(void);
uint8   stepCtrl1_Read(void);
void    stepCtrl1_SetInterruptMode(uint16 position, uint16 mode);
uint8   stepCtrl1_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the stepCtrl1_SetDriveMode() function.
     *  @{
     */
        #define stepCtrl1_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define stepCtrl1_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define stepCtrl1_DM_RES_UP          PIN_DM_RES_UP
        #define stepCtrl1_DM_RES_DWN         PIN_DM_RES_DWN
        #define stepCtrl1_DM_OD_LO           PIN_DM_OD_LO
        #define stepCtrl1_DM_OD_HI           PIN_DM_OD_HI
        #define stepCtrl1_DM_STRONG          PIN_DM_STRONG
        #define stepCtrl1_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define stepCtrl1_MASK               stepCtrl1__MASK
#define stepCtrl1_SHIFT              stepCtrl1__SHIFT
#define stepCtrl1_WIDTH              1u

/* Interrupt constants */
#if defined(stepCtrl1__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in stepCtrl1_SetInterruptMode() function.
     *  @{
     */
        #define stepCtrl1_INTR_NONE      (uint16)(0x0000u)
        #define stepCtrl1_INTR_RISING    (uint16)(0x0001u)
        #define stepCtrl1_INTR_FALLING   (uint16)(0x0002u)
        #define stepCtrl1_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define stepCtrl1_INTR_MASK      (0x01u) 
#endif /* (stepCtrl1__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define stepCtrl1_PS                     (* (reg8 *) stepCtrl1__PS)
/* Data Register */
#define stepCtrl1_DR                     (* (reg8 *) stepCtrl1__DR)
/* Port Number */
#define stepCtrl1_PRT_NUM                (* (reg8 *) stepCtrl1__PRT) 
/* Connect to Analog Globals */                                                  
#define stepCtrl1_AG                     (* (reg8 *) stepCtrl1__AG)                       
/* Analog MUX bux enable */
#define stepCtrl1_AMUX                   (* (reg8 *) stepCtrl1__AMUX) 
/* Bidirectional Enable */                                                        
#define stepCtrl1_BIE                    (* (reg8 *) stepCtrl1__BIE)
/* Bit-mask for Aliased Register Access */
#define stepCtrl1_BIT_MASK               (* (reg8 *) stepCtrl1__BIT_MASK)
/* Bypass Enable */
#define stepCtrl1_BYP                    (* (reg8 *) stepCtrl1__BYP)
/* Port wide control signals */                                                   
#define stepCtrl1_CTL                    (* (reg8 *) stepCtrl1__CTL)
/* Drive Modes */
#define stepCtrl1_DM0                    (* (reg8 *) stepCtrl1__DM0) 
#define stepCtrl1_DM1                    (* (reg8 *) stepCtrl1__DM1)
#define stepCtrl1_DM2                    (* (reg8 *) stepCtrl1__DM2) 
/* Input Buffer Disable Override */
#define stepCtrl1_INP_DIS                (* (reg8 *) stepCtrl1__INP_DIS)
/* LCD Common or Segment Drive */
#define stepCtrl1_LCD_COM_SEG            (* (reg8 *) stepCtrl1__LCD_COM_SEG)
/* Enable Segment LCD */
#define stepCtrl1_LCD_EN                 (* (reg8 *) stepCtrl1__LCD_EN)
/* Slew Rate Control */
#define stepCtrl1_SLW                    (* (reg8 *) stepCtrl1__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define stepCtrl1_PRTDSI__CAPS_SEL       (* (reg8 *) stepCtrl1__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define stepCtrl1_PRTDSI__DBL_SYNC_IN    (* (reg8 *) stepCtrl1__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define stepCtrl1_PRTDSI__OE_SEL0        (* (reg8 *) stepCtrl1__PRTDSI__OE_SEL0) 
#define stepCtrl1_PRTDSI__OE_SEL1        (* (reg8 *) stepCtrl1__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define stepCtrl1_PRTDSI__OUT_SEL0       (* (reg8 *) stepCtrl1__PRTDSI__OUT_SEL0) 
#define stepCtrl1_PRTDSI__OUT_SEL1       (* (reg8 *) stepCtrl1__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define stepCtrl1_PRTDSI__SYNC_OUT       (* (reg8 *) stepCtrl1__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(stepCtrl1__SIO_CFG)
    #define stepCtrl1_SIO_HYST_EN        (* (reg8 *) stepCtrl1__SIO_HYST_EN)
    #define stepCtrl1_SIO_REG_HIFREQ     (* (reg8 *) stepCtrl1__SIO_REG_HIFREQ)
    #define stepCtrl1_SIO_CFG            (* (reg8 *) stepCtrl1__SIO_CFG)
    #define stepCtrl1_SIO_DIFF           (* (reg8 *) stepCtrl1__SIO_DIFF)
#endif /* (stepCtrl1__SIO_CFG) */

/* Interrupt Registers */
#if defined(stepCtrl1__INTSTAT)
    #define stepCtrl1_INTSTAT            (* (reg8 *) stepCtrl1__INTSTAT)
    #define stepCtrl1_SNAP               (* (reg8 *) stepCtrl1__SNAP)
    
	#define stepCtrl1_0_INTTYPE_REG 		(* (reg8 *) stepCtrl1__0__INTTYPE)
#endif /* (stepCtrl1__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_stepCtrl1_H */


/* [] END OF FILE */
