//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"

//-- ISR ------------------------------------------------------------------
void ISR (void) {
    //-- Configura��es Individuais Perif�ricos --------------------------------


    //-- Populaciona o vetor PIE com o endere�o das ISR -----------------------
    EALLOW;
    //PieVectTable.XXX= &XXX;   // Int XXX
    EDIS;


    //-- Habilita as Interup��es Desejadas (PIE) ------------------------------
    PieCtrlRegs.PIEACK.all  = 0xFFFF;       // Reseta o bit de acknowledgement
    //PieCtrlRegs.PIEIERXXX.bit.INTxXXX = 1;    //HAB. INT. XXX


    //-- Habilita as Interup��es no CPU ---------------------------------------
    //IER |= M_INTX;    // Enable CPU Interrupt X


    EINT;   // Enable Interrupts at the CPU level
    ERTM;   // Coloca 0 no FLAG DBGM, permitindo Debug em Tempo Real
}
