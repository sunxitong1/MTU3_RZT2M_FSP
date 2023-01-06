/***********************************************************************************************************************
 * Copyright [2020-2022] Renesas Electronics Corporation and/or its affiliates.  All Rights Reserved.
 *
 * This software and documentation are supplied by Renesas Electronics Corporation and/or its affiliates and may only
 * be used with products of Renesas Electronics Corp. and its affiliates ("Renesas").  No other uses are authorized.
 * Renesas products are sold pursuant to Renesas terms and conditions of sale.  Purchasers are solely responsible for
 * the selection and use of Renesas products and Renesas assumes no liability.  No license, express or implied, to any
 * intellectual property right is granted by Renesas.  This software is protected under all applicable laws, including
 * copyright laws. Renesas reserves the right to change or discontinue this software and/or this documentation.
 * THE SOFTWARE AND DOCUMENTATION IS DELIVERED TO YOU "AS IS," AND RENESAS MAKES NO REPRESENTATIONS OR WARRANTIES, AND
 * TO THE FULLEST EXTENT PERMISSIBLE UNDER APPLICABLE LAW, DISCLAIMS ALL WARRANTIES, WHETHER EXPLICITLY OR IMPLICITLY,
 * INCLUDING WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, AND NONINFRINGEMENT, WITH RESPECT TO THE
 * SOFTWARE OR DOCUMENTATION.  RENESAS SHALL HAVE NO LIABILITY ARISING OUT OF ANY SECURITY VULNERABILITY OR BREACH.
 * TO THE MAXIMUM EXTENT PERMITTED BY LAW, IN NO EVENT WILL RENESAS BE LIABLE TO YOU IN CONNECTION WITH THE SOFTWARE OR
 * DOCUMENTATION (OR ANY PERSON OR ENTITY CLAIMING RIGHTS DERIVED FROM YOU) FOR ANY LOSS, DAMAGES, OR CLAIMS WHATSOEVER,
 * INCLUDING, WITHOUT LIMITATION, ANY DIRECT, CONSEQUENTIAL, SPECIAL, INDIRECT, PUNITIVE, OR INCIDENTAL DAMAGES; ANY
 * LOST PROFITS, OTHER ECONOMIC DAMAGE, PROPERTY DAMAGE, OR PERSONAL INJURY; AND EVEN IF RENESAS HAS BEEN ADVISED OF THE
 * POSSIBILITY OF SUCH LOSS, DAMAGES, CLAIMS OR COSTS.
 **********************************************************************************************************************/

#include "hal_data.h"

void R_BSP_WarmStart(bsp_warm_start_event_t event);

#define MTU_COUNT_STOP        (0)
#define MTU_CMPLMT_PWM_START  (0xC0)
#define MTU_C_SET_CYCLE       (0x1388)   // Carrier cycle = 100us (PCLKC/4)
#define MTU_C_CYCLE           (0x9C4)   // Carrier cycle/2 = 50us (PCLKC/4)
#define MTU_DEAD_TIME         (0x64)    // Dead time = 2us (PCLKC/4)

#define MTU_DUTY_75           ((uint16_t) MTU_C_CYCLE * 1/4+ MTU_DEAD_TIME / 2)
#define MTU_DUTY_50           ((uint16_t) MTU_C_CYCLE * 2/4+ MTU_DEAD_TIME / 2)
#define MTU_DUTY_25           ((uint16_t) MTU_C_CYCLE * 3/4+ MTU_DEAD_TIME / 2)

#define DUTY_CNT_MAX          (3)

#define MAIN_SW_STATUS_ON      (0u)
#define MAIN_SW_STATUS_OFF     (1u)


uint16_t g_duty_rate[DUTY_CNT_MAX] = { MTU_DUTY_25, MTU_DUTY_50, MTU_DUTY_75 };
uint8_t  g_duty_cnt;

#define MAIN_SW1_OB        R_PORT_NSR->PIN_b[23].PIN5
#define MAIN_SW2_OB        R_PORT_NSR->PIN_b[23].PIN3
#define MAIN_SW1_NB        R_PORT_NSR->PIN_b[10].PIN5
#define MAIN_SW2_NB        R_PORT_NSR->PIN_b[16].PIN3

static void r_main_mtu_chng_duty(void);

static three_phase_duty_cycle_t duty_cycle;

/*******************************************************************************
 Sub function MTU3 Complement PWM
*******************************************************************************/


/*******************************************************************************************************************//**
 * @brief  Blinky example application
 *
 * Blinks all leds at a rate of 1 second using the software delay function provided by the BSP.
 *
 **********************************************************************************************************************/
void hal_entry (void)
{
    uint8_t u8_sw2_old=MAIN_SW_STATUS_OFF;
  
    /* Define the units to be used with the software delay function */
    const bsp_delay_units_t bsp_delay_units = BSP_DELAY_UNITS_MILLISECONDS;

    /* Set the blink frequency (must be <= bsp_delay_units */
    const uint32_t freq_in_hz = 5;

    /* Calculate the delay in terms of bsp_delay_units */
    const uint32_t delay = bsp_delay_units / freq_in_hz;


    //MSTPCRA register Bit0 Clear
    *((unsigned long*)0x80280308)&=0xFFFFFFFEu;
    

    (void)R_MTU3_THREE_PHASE_Open(&g_three_phase0_ctrl, &g_three_phase0_cfg);
    
        /* Update duty cycle values (example) */
    duty_cycle.duty[THREE_PHASE_CHANNEL_U] = g_duty_rate[0];
    duty_cycle.duty[THREE_PHASE_CHANNEL_V] = g_duty_rate[0];
    duty_cycle.duty[THREE_PHASE_CHANNEL_W] = g_duty_rate[0];
    (void) R_MTU3_THREE_PHASE_DutyCycleSet(&g_three_phase0_ctrl, &duty_cycle);
    
    (void) R_POE3_Open(&g_poe30_ctrl, &g_poe30_cfg);
    
//    R_MTU_PWM_Complement_Control(MTU_CHANNEL_3_4, MTU_CMD_START, NULL);
//    (void) R_MTU3_Start (&g_timer0_ctrl);

    (void) R_MTU3_THREE_PHASE_Start(&g_three_phase0_ctrl);
//    R_MTU->TSTRA=0xc0u;
	__asm volatile ("cpsie i");

    //LED0 ON
    R_PORT_NSR->P_b[19].POUT_6=1;
    
    while (1)
    {
        if((MAIN_SW_STATUS_OFF ==u8_sw2_old)&&((MAIN_SW_STATUS_ON==MAIN_SW2_OB)||(MAIN_SW_STATUS_ON==MAIN_SW2_NB)))
        {
            u8_sw2_old=MAIN_SW_STATUS_ON;
            r_main_mtu_chng_duty();
            /* Delay */
            R_BSP_SoftwareDelay(delay, bsp_delay_units);
        }
        else
        {
            if((MAIN_SW_STATUS_ON!= MAIN_SW2_OB)&&(MAIN_SW_STATUS_ON!= MAIN_SW2_NB))
            {
                u8_sw2_old=MAIN_SW_STATUS_OFF;
            }
        }
        if((MAIN_SW_STATUS_ON==MAIN_SW1_OB)||(MAIN_SW_STATUS_ON==MAIN_SW1_NB))
        {
            (void) R_POE3_OutputDisable(&g_poe30_ctrl);
            /* break */
            break;
        }
    }
    //LED0 OFF
    R_PORT_NSR->P_b[19].POUT_6=0;
    //LED1 ON
    R_PORT_NSR->P_b[19].POUT_4=1;
    
    (void) R_MTU3_THREE_PHASE_Stop(&g_three_phase0_ctrl);
    (void) R_MTU3_THREE_PHASE_Close(&g_three_phase0_ctrl);

    (void)R_POE3_Close(&g_poe30_ctrl);
    
    
    while(1);
}

/*******************************************************************************************************************//**
 * This function is called at various points during the startup process.  This implementation uses the event that is
 * called right before main() to set up the pins.
 *
 * @param[in]  event    Where at in the start up process the code is currently at
 **********************************************************************************************************************/
void R_BSP_WarmStart (bsp_warm_start_event_t event)
{
    if (BSP_WARM_START_POST_C == event)
    {
        /* C runtime environment and system clocks are setup. */

        /* Configure pins. */
        R_IOPORT_Open(&g_ioport_ctrl, &g_bsp_pin_cfg);
    }
}


/*******************************************************************************
* Function Name: r_main_mtu_chng_duty
* Description  : Change the duty rate (25% -> 50% -> 75%) at a repetition.
* Arguments    : none
* Return Value : none
*******************************************************************************/
static void r_main_mtu_chng_duty(void)
{
    
    /* Change Duty rate 25% -> 50% -> 75 % at a repetition */
    
    g_duty_cnt ++;
    
    if ( DUTY_CNT_MAX <= g_duty_cnt )
    {
        g_duty_cnt = 0;                      // Clear duty counter 
        
    }
 
    duty_cycle.duty[THREE_PHASE_CHANNEL_U] = g_duty_rate[g_duty_cnt];
    duty_cycle.duty[THREE_PHASE_CHANNEL_V] = g_duty_rate[g_duty_cnt];
    duty_cycle.duty[THREE_PHASE_CHANNEL_W] = g_duty_rate[g_duty_cnt];
    
    (void) R_MTU3_THREE_PHASE_DutyCycleSet(&g_three_phase0_ctrl, &duty_cycle);
}
/*******************************************************************************
 End of function r_main_mtu_chng_duty
*******************************************************************************/

/*******************************************************************************
 Sub function MTU3 Complement PWM
*******************************************************************************/

