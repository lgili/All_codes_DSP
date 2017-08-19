//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"
#include "Geral.h"
#include "math.h"

#include "float.h"


#include "stdio.h"
#include <stdlib.h>



__interrupt void pwm1_isr(void);      // Interrup��o PWM para o retificador

/* function declaration */
void max(float *num1, float *num2, float *num3);
void Transformer_Alfa_beta();
void Transformer_D_Q();
void Transformer_inv_Alfa_beta();
void Transformer_inv_D_Q();


float teste1=0, time=0,alfa=0, beta=0,d=0,q=0,theta=0;
const float Ts = 0.00002;
const float pi = 3.1415926535;
const float rtsd = 0.866;

float a = 100;
float b = 200;
float c = 0;
float num1,num2,num3,ww;
float ret;



//-- ISR ------------------------------------------------------------------
void ISR (void) {
    //-- Configura��es Individuais Perif�ricos --------------------------------


    //-- Populaciona o vetor PIE com o endere�o das ISR -----------------------
    EALLOW;
    //PieVectTable.XXX= &XXX;   // Int XXX
    PieVectTable.EPWM1_INT = &pwm1_isr;

    EDIS;


    //-- Habilita as Interup��es Desejadas (PIE) ------------------------------
    PieCtrlRegs.PIEACK.all  = 0xFFFF;       // Reseta o bit de acknowledgement
    PieCtrlRegs.PIEIER3.bit.INTx1 = 1;      // HAB. INT. ADC1

    //PieCtrlRegs.PIEIERXXX.bit.INTxXXX = 1;    //HAB. INT. XXX


    //-- Habilita as Interup��es no CPU ---------------------------------------
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

   // adicionando para testa git

 //  alfa = 0.66667 * (Vsenos.Va - Vsenos.Vb *0.5 - Vsenos.Vc *0.5);
  // beta = 0.66667 * (rtsd * Vsenos.Vb - rtsd*Vsenos.Vc);

  // d= Vsenos.Va*cos(theta) + Vsenos.Vb*cos(theta -2*pi/3) + Vsenos.Vc*cos(theta -4*pi/3);
  // q= Vsenos.Va*sin(theta) + Vsenos.Vb*sin(theta -2*pi/3) + Vsenos.Vc*sin(theta -4*pi/3);


    if (time >= 0.016667) time=0;




       /* calling a function to get max value */

        Transformer_Alfa_beta();
        Transformer_D_Q();
        Transformer_inv_Alfa_beta();
        Transformer_inv_D_Q();

  //      struct _Alfa_beta t = Transformer_Alfa_beta();
  //     return 0;


    EPwm1Regs.ETCLR.bit.INT = 1;            // Limpa flag permitindo de INT periferica

    PieCtrlRegs.PIEACK.all = PIEACK_GROUP3;     // Reseta o bit de acknowle


}

void max(float *num1, float *num2, float *num3) {

   /* local variable declaration */
    *num1  = 1;
    *num2 = 3;
    *num3 = 4;
}

void Transformer_Alfa_beta(){

    Alfa_beta.Valfa = 0.66667 * (Vsenos.Va - Vsenos.Vb *0.5 - Vsenos.Vc *0.5);
    Alfa_beta.Vbeta = 0.66667 * (rtsd * Vsenos.Vb - rtsd*Vsenos.Vc);

    return Alfa_beta;
}

void Transformer_D_Q(){

    DQ.d = Vsenos.Va*cos(theta) + Vsenos.Vb*cos(theta -2*pi/3) + Vsenos.Vc*cos(theta -4*pi/3);
    DQ.q = Vsenos.Va*sin(theta) + Vsenos.Vb*sin(theta -2*pi/3) + Vsenos.Vc*sin(theta -4*pi/3);

    return DQ;
}

void Transformer_inv_Alfa_beta(){

    Inverse_Alfa_beta.Va = 0.4714*(Alfa_beta.Valfa );
    Inverse_Alfa_beta.Vb = 0.4714*(-0.5*Alfa_beta.Valfa + rtsd*Alfa_beta.Vbeta );
    Inverse_Alfa_beta.Vc = 0.4714*(-0.5*Alfa_beta.Valfa - rtsd*Alfa_beta.Vbeta );

    return Inverse_Alfa_beta;

}
void Transformer_inv_D_Q(){

    alfa = DQ.d*cos(theta) - DQ.q*sin(theta);
    beta = DQ.q*cos(theta) - DQ.d*sin(theta);

    Inverse_D_Q.Va = 0.4714*(alfa );
    Inverse_D_Q.Vb = 0.4714*(-0.5*alfa + rtsd*beta );
    Inverse_D_Q.Vc = 0.4714*(-0.5*alfa - rtsd*beta );

    return Inverse_D_Q;
}
