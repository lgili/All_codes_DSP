//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"
//#include "Geral.h"

//-- PWM ------------------------------------------------------------------
void PWM (void) {
	//-- Configuração PWM -----------------------------------------------------
	EALLOW;
	CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 0;	// Para poder sincronizar ao TBCLK
	EDIS;

	//-- ePWM2 ----------------------------------------------------------------
	EPwm2Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1; 	// TBCLK = SYSCLK
	EPwm2Regs.TBCTL.bit.CLKDIV = TB_DIV1;		// TBCLK = SYSCLK

	EPwm2Regs.TBCTL.bit.FREE_SOFT = 2;

	EPwm2Regs.TBCTR = 0; 						// Clear TB counter
	EPwm2Regs.TBPRD = 1000; 					// Period
	EPwm2Regs.TBPHS.bit.TBPHS = 0;				// Delay between ePWM's
	EPwm2Regs.TBCTL.bit.PHSEN = TB_DISABLE;		// Enable TBPHS
	EPwm2Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;	// Counter Mode

	EPwm2Regs.CMPCTL.bit.SHDWAMODE = 0;	// Shadow
	EPwm2Regs.CMPCTL.bit.SHDWBMODE = 0;	// Shadow
	EPwm2Regs.CMPCTL.bit.LOADAMODE = 2;	// load on ZRO and PRD
	EPwm2Regs.CMPCTL.bit.LOADBMODE = 2;	// load on ZRO and PRD

	EPwm2Regs.CMPA.bit.CMPA = 500;	// Compare A
	EPwm2Regs.CMPB.bit.CMPB = 0; 	// Compare B

	EPwm2Regs.AQCTLA.bit.ZRO = AQ_CLEAR;	// Saída ePWM2A
	EPwm2Regs.AQCTLA.bit.CAU = AQ_CLEAR;

	EPwm2Regs.AQCTLB.bit.ZRO = AQ_CLEAR;	// Saída ePWM2B
	EPwm2Regs.AQCTLB.bit.CAU = AQ_CLEAR;

	//-- Desativado pois a chave de baixo será usada como diodo
/*	EPwm2Regs.DBCTL.bit.IN_MODE = DBA_ALL;
	EPwm2Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
	EPwm2Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
	EPwm2Regs.DBFED = ePWM_DB_FE;
	EPwm2Regs.DBRED = ePWM_DB_RE;*/

	EPwm2Regs.ETSEL.bit.SOCAEN = 1;		// Enable the ADC Start of Conversion A (EPWMxSOCA) Pulse.
	EPwm2Regs.ETSEL.bit.SOCASEL = 1;	// Determine when a EPWMxSOCA pulse will be generated. (1 -> When CTR = ZERO)
	EPwm2Regs.ETPS.bit.SOCAPRD = 1;		// Generate pulse on 1st event.

	EPwm2Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;	// Enable One Shot 1 Event for ePWM2 Trip Zone
	EPwm2Regs.TZCTL.bit.TZA = TZ_FORCE_LO;	// EPWM2A will be forced low on a trip event
	EPwm2Regs.TZCTL.bit.TZB = TZ_FORCE_LO;	// EPWM2B will be forced low on a trip event

	EPwm2Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO;	// Sincronização
	EPwm2Regs.TBCTL.bit.SWFSYNC = 1;

	//--

    //-- ePWM2 ----------------------------------------------------------------
    EPwm9Regs.TBCTL.bit.HSPCLKDIV = TB_DIV1;    // TBCLK = SYSCLK
    EPwm9Regs.TBCTL.bit.CLKDIV = TB_DIV1;       // TBCLK = SYSCLK

    EPwm9Regs.TBCTL.bit.FREE_SOFT = 2;

    EPwm9Regs.TBCTR = 0;                        // Clear TB counter
    EPwm9Regs.TBPRD = 10000;                    // Period
    EPwm9Regs.TBPHS.bit.TBPHS = 0;              // Delay between ePWM's
    EPwm9Regs.TBCTL.bit.PHSEN = TB_DISABLE;     // Enable TBPHS
    EPwm9Regs.TBCTL.bit.CTRMODE = TB_COUNT_UP;  // Counter Mode

    EPwm9Regs.CMPCTL.bit.SHDWAMODE = 0; // Shadow
    EPwm9Regs.CMPCTL.bit.SHDWBMODE = 0; // Shadow
    EPwm9Regs.CMPCTL.bit.LOADAMODE = 2; // load on ZRO and PRD
    EPwm9Regs.CMPCTL.bit.LOADBMODE = 2; // load on ZRO and PRD

    EPwm9Regs.CMPA.bit.CMPA = 5000; // Compare A
    EPwm9Regs.CMPB.bit.CMPB = 0;    // Compare B

    EPwm9Regs.AQCTLA.bit.ZRO = AQ_CLEAR;    // Saída ePWM2A
    EPwm9Regs.AQCTLA.bit.CAU = AQ_SET;

    EPwm9Regs.AQCTLB.bit.ZRO = AQ_CLEAR;    // Saída ePWM2B
    EPwm9Regs.AQCTLB.bit.CAU = AQ_SET;

    //-- Desativado pois a chave de baixo será usada como diodo
/*  EPwm9Regs.DBCTL.bit.IN_MODE = DBA_ALL;
    EPwm9Regs.DBCTL.bit.OUT_MODE = DB_FULL_ENABLE;
    EPwm9Regs.DBCTL.bit.POLSEL = DB_ACTV_HIC;
    EPwm9Regs.DBFED = ePWM_DB_FE;
    EPwm9Regs.DBRED = ePWM_DB_RE;*/

/*
    EPwm9Regs.ETSEL.bit.SOCAEN = 1;     // Enable the ADC Start of Conversion A (EPWMxSOCA) Pulse.
    EPwm9Regs.ETSEL.bit.SOCASEL = 1;    // Determine when a EPWMxSOCA pulse will be generated. (1 -> When CTR = ZERO)
    EPwm9Regs.ETPS.bit.SOCAPRD = 1;     // Generate pulse on 1st event.
*/

    EPwm9Regs.TZSEL.bit.OSHT1 = TZ_ENABLE;  // Enable One Shot 1 Event for ePWM2 Trip Zone
    EPwm9Regs.TZCTL.bit.TZA = TZ_FORCE_LO;  // EPWM2A will be forced low on a trip event
    EPwm9Regs.TZCTL.bit.TZB = TZ_FORCE_LO;  // EPWM2B will be forced low on a trip event

    EPwm9Regs.TBCTL.bit.SYNCOSEL = TB_CTR_ZERO; // Sincronização
    EPwm9Regs.TBCTL.bit.SWFSYNC = 1;

	EALLOW;
	CpuSysRegs.PCLKCR0.bit.TBCLKSYNC = 1;	// Sincroniza os módulos ao TBCLK
	EDIS;
}
