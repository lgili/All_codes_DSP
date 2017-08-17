//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"
#include "Geral.h"
#include "math.h"

#include "float.h"


#include "stdio.h"
#include <stdlib.h>



__interrupt void pwm1_isr(void);      // Interrupção PWM para o retificador


float teste1=0, time=0,alfa=0, beta=0,d=0,q=0,theta=0;
const float Ts = 0.00002;
const float pi = 3.1415926535;
const float rtsd = 0.866;
//-- ISR ------------------------------------------------------------------
void ISR (void) {
    //-- Configurações Individuais Periféricos --------------------------------


    //-- Populaciona o vetor PIE com o endereço das ISR -----------------------
    EALLOW;
    //PieVectTable.XXX= &XXX;   // Int XXX
    PieVectTable.EPWM1_INT = &pwm1_isr;

    EDIS;


    //-- Habilita as Interupções Desejadas (PIE) ------------------------------
    PieCtrlRegs.PIEACK.all  = 0xFFFF;       // Reseta o bit de acknowledgement
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;      // HAB. INT. ADC1

    //PieCtrlRegs.PIEIERXXX.bit.INTxXXX = 1;    //HAB. INT. XXX


    //-- Habilita as Interupções no CPU ---------------------------------------
    //IER |= M_INTX;    // Enable CPU Interrupt X


   // EINT;   // Enable Interrupts at the CPU level
   // ERTM;   // Coloca 0 no FLAG DBGM, permitindo Debug em Tempo Real

//
     //   EDIS;                                 // Disable writing to EALLOW protected registers
   //     InitTimer_ePWMx(&EPwm1Regs, period); // Init ePWM1 module


      //  EPwm1Regs.ETSEL.bit.INTSEL = ET_CTR_ZERO;      // Select INT on Period event

     //   EPwm1Regs.ETSEL.bit.INTEN = 1;                 // Enable INT

      //  EPwm1Regs.ETPS.bit.INTPRD = ET_1ST;            // Generate INT on 1st event

     //   PieCtrlRegs.PIEIER3.bit.INTx1 = 1;  //Olhar esse cara qui //  // Enable EPWM1 INT in the PIE: Group 3 interrupt 1

     //   EALLOW;
        // Enable writing to EALLOW protected registers

   //     SysCtrlRegs.PCLKCR0.bit.TBCLKSYNC = 1;// Start all the timers synced
        EDIS;                                 // Disable writing to EALLOW protected registers
        IER |= M_INT3;                        // Enable CPU INT2 for EPWM1 INT
        EINT;                                 // Enable Global interrupt INTM
        ERTM;
}

interrupt void pwm1_isr(void)
{

    time = time + Ts;
   // time ++;
   theta = 2*pi*time*60;
   Vsenos.Va = sin(theta);
   Vsenos.Vb = sin(theta - 2*pi/3);
   Vsenos.Vc = sin(theta + 2*pi/3);



   alfa = 2/3 * (Vsenos.Va -0.5*Vsenos.Vb - 0.5*Vsenos.Vc);
   beta =  2/3 * (rtsd * Vsenos.Vb - rtsd*Vsenos.Vc);

   d= Vsenos.Va*cos(theta) + Vsenos.Vb*cos(theta -2*pi/3) + Vsenos.Vc*cos(theta -4*pi/3);
   q= Vsenos.Va*sin(theta) + Vsenos.Vb*sin(theta -2*pi/3) + Vsenos.Vc*sin(theta -4*pi/3);


    if (time >= 0.016667) time=0;

   //  teste1 ++;
   // if(teste1 >= 1000 ) teste1=0;
    EPwm1Regs.ETCLR.bit.INT = 1;            // Limpa flag permitindo de INT periferica

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;     // Reseta o bit de acknowle


}
