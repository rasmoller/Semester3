/*******************************************************************************
* File Name: stepCtrl3.h  
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

#if !defined(CY_PINS_stepCtrl3_H) /* Pins stepCtrl3_H */
#define CY_PINS_stepCtrl3_H

#include "cytypes.h"
#include "cyfitter.h"
#include "cypins.h"
#include "stepCtrl3_aliases.h"

/* APIs are not generated for P15[7:6] */
#if !(CY_PSOC5A &&\
	 stepCtrl3__PORT == 15 && ((stepCtrl3__MASK & 0xC0) != 0))


/***************************************
*        Function Prototypes             
***************************************/    

/**
* \addtogroup group_general
* @{
*/
void    stepCtrl3_Write(uint8 value);
void    stepCtrl3_SetDriveMode(uint8 mode);
uint8   stepCtrl3_ReadDataReg(void);
uint8   stepCtrl3_Read(void);
void    stepCtrl3_SetInterruptMode(uint16 position, uint16 mode);
uint8   stepCtrl3_ClearInterrupt(void);
/** @} general */

/***************************************
*           API Constants        
***************************************/
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup driveMode Drive mode constants
     * \brief Constants to be passed as "mode" parameter in the stepCtrl3_SetDriveMode() function.
     *  @{
     */
        #define stepCtrl3_DM_ALG_HIZ         PIN_DM_ALG_HIZ
        #define stepCtrl3_DM_DIG_HIZ         PIN_DM_DIG_HIZ
        #define stepCtrl3_DM_RES_UP          PIN_DM_RES_UP
        #define stepCtrl3_DM_RES_DWN         PIN_DM_RES_DWN
        #define stepCtrl3_DM_OD_LO           PIN_DM_OD_LO
        #define stepCtrl3_DM_OD_HI           PIN_DM_OD_HI
        #define stepCtrl3_DM_STRONG          PIN_DM_STRONG
        #define stepCtrl3_DM_RES_UPDWN       PIN_DM_RES_UPDWN
    /** @} driveMode */
/** @} group_constants */
    
/* Digital Port Constants */
#define stepCtrl3_MASK               stepCtrl3__MASK
#define stepCtrl3_SHIFT              stepCtrl3__SHIFT
#define stepCtrl3_WIDTH              1u

/* Interrupt constants */
#if defined(stepCtrl3__INTSTAT)
/**
* \addtogroup group_constants
* @{
*/
    /** \addtogroup intrMode Interrupt constants
     * \brief Constants to be passed as "mode" parameter in stepCtrl3_SetInterruptMode() function.
     *  @{
     */
        #define stepCtrl3_INTR_NONE      (uint16)(0x0000u)
        #define stepCtrl3_INTR_RISING    (uint16)(0x0001u)
        #define stepCtrl3_INTR_FALLING   (uint16)(0x0002u)
        #define stepCtrl3_INTR_BOTH      (uint16)(0x0003u) 
    /** @} intrMode */
/** @} group_constants */

    #define stepCtrl3_INTR_MASK      (0x01u) 
#endif /* (stepCtrl3__INTSTAT) */


/***************************************
*             Registers        
***************************************/

/* Main Port Registers */
/* Pin State */
#define stepCtrl3_PS                     (* (reg8 *) stepCtrl3__PS)
/* Data Register */
#define stepCtrl3_DR                     (* (reg8 *) stepCtrl3__DR)
/* Port Number */
#define stepCtrl3_PRT_NUM                (* (reg8 *) stepCtrl3__PRT) 
/* Connect to Analog Globals */                                                  
#define stepCtrl3_AG                     (* (reg8 *) stepCtrl3__AG)                       
/* Analog MUX bux enable */
#define stepCtrl3_AMUX                   (* (reg8 *) stepCtrl3__AMUX) 
/* Bidirectional Enable */                                                        
#define stepCtrl3_BIE                    (* (reg8 *) stepCtrl3__BIE)
/* Bit-mask for Aliased Register Access */
#define stepCtrl3_BIT_MASK               (* (reg8 *) stepCtrl3__BIT_MASK)
/* Bypass Enable */
#define stepCtrl3_BYP                    (* (reg8 *) stepCtrl3__BYP)
/* Port wide control signals */                                                   
#define stepCtrl3_CTL                    (* (reg8 *) stepCtrl3__CTL)
/* Drive Modes */
#define stepCtrl3_DM0                    (* (reg8 *) stepCtrl3__DM0) 
#define stepCtrl3_DM1                    (* (reg8 *) stepCtrl3__DM1)
#define stepCtrl3_DM2                    (* (reg8 *) stepCtrl3__DM2) 
/* Input Buffer Disable Override */
#define stepCtrl3_INP_DIS                (* (reg8 *) stepCtrl3__INP_DIS)
/* LCD Common or Segment Drive */
#define stepCtrl3_LCD_COM_SEG            (* (reg8 *) stepCtrl3__LCD_COM_SEG)
/* Enable Segment LCD */
#define stepCtrl3_LCD_EN                 (* (reg8 *) stepCtrl3__LCD_EN)
/* Slew Rate Control */
#define stepCtrl3_SLW                    (* (reg8 *) stepCtrl3__SLW)

/* DSI Port Registers */
/* Global DSI Select Register */
#define stepCtrl3_PRTDSI__CAPS_SEL       (* (reg8 *) stepCtrl3__PRTDSI__CAPS_SEL) 
/* Double Sync Enable */
#define stepCtrl3_PRTDSI__DBL_SYNC_IN    (* (reg8 *) stepCtrl3__PRTDSI__DBL_SYNC_IN) 
/* Output Enable Select Drive Strength */
#define stepCtrl3_PRTDSI__OE_SEL0        (* (reg8 *) stepCtrl3__PRTDSI__OE_SEL0) 
#define stepCtrl3_PRTDSI__OE_SEL1        (* (reg8 *) stepCtrl3__PRTDSI__OE_SEL1) 
/* Port Pin Output Select Registers */
#define stepCtrl3_PRTDSI__OUT_SEL0       (* (reg8 *) stepCtrl3__PRTDSI__OUT_SEL0) 
#define stepCtrl3_PRTDSI__OUT_SEL1       (* (reg8 *) stepCtrl3__PRTDSI__OUT_SEL1) 
/* Sync Output Enable Registers */
#define stepCtrl3_PRTDSI__SYNC_OUT       (* (reg8 *) stepCtrl3__PRTDSI__SYNC_OUT) 

/* SIO registers */
#if defined(stepCtrl3__SIO_CFG)
    #define stepCtrl3_SIO_HYST_EN        (* (reg8 *) stepCtrl3__SIO_HYST_EN)
    #define stepCtrl3_SIO_REG_HIFREQ     (* (reg8 *) stepCtrl3__SIO_REG_HIFREQ)
    #define stepCtrl3_SIO_CFG            (* (reg8 *) stepCtrl3__SIO_CFG)
    #define stepCtrl3_SIO_DIFF           (* (reg8 *) stepCtrl3__SIO_DIFF)
#endif /* (stepCtrl3__SIO_CFG) */

/* Interrupt Registers */
#if defined(stepCtrl3__INTSTAT)
    #define stepCtrl3_INTSTAT            (* (reg8 *) stepCtrl3__INTSTAT)
    #define stepCtrl3_SNAP               (* (reg8 *) stepCtrl3__SNAP)
    
	#define stepCtrl3_0_INTTYPE_REG 		(* (reg8 *) stepCtrl3__0__INTTYPE)
#endif /* (stepCtrl3__INTSTAT) */

#endif /* CY_PSOC5A... */

#endif /*  CY_PINS_stepCtrl3_H */


/* [] END OF FILE */
