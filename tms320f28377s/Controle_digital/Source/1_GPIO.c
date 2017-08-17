//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"

//-- GPIO -----------------------------------------------------------------
void GPIO (void) {
	EALLOW;

	//-- GPIO0 -> EPWM1A
    //GpioCtrlRegs.GPAPUD.bit.GPIO0 = 1;	//Desativa Pull Up
    //GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 1; //EPWM1A -> GPIO0
    //GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  //Define GPIO como saída

    //-- GPIO13 -> D6
//	GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0;
//	GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;

	//-- GPIO16 ~ GPIO 19 -> SPI-A
//    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0;   // Enable pull-up on GPIO16 (SPISIMOA)
//    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0;   // Enable pull-up on GPIO17 (SPISOMIA)
//    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;   // Enable pull-up on GPIO18 (SPICLKA)
//    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;   // Enable pull-up on GPIO19 (SPISTEA)
//
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3; // Asynch input GPIO16 (SPISIMOA)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3; // Asynch input GPIO17 (SPISOMIA)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3; // Asynch input GPIO18 (SPICLKA)
//    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3; // Asynch input GPIO19 (SPISTEA)
//
//    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1; // Configure GPIO16 as SPISIMOA
//    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1; // Configure GPIO17 as SPISOMIA
//    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1; // Configure GPIO18 as SPICLKA
//    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0; // Configure GPIO19 as SPISTEA
//    GpioCtrlRegs.GPADIR.bit.GPIO19 = 1;
    //--

    //-- Configuracao GPIO para testes dos pinos do launchpad
	GpioCtrlRegs.GPAMUX1.bit.GPIO2 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO2 = 1;

	GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0;
	GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO10 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO10 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO11 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO11 = 0;
    GpioCtrlRegs.GPAPUD.bit.GPIO11 = 0;

    GpioCtrlRegs.GPAMUX1.bit.GPIO12 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO12 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO13 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO14 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO14 = 1;

    GpioCtrlRegs.GPAMUX1.bit.GPIO15 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO15 = 1;

    GpioCtrlRegs.GPAGMUX2.bit.GPIO16 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO16 = 1;

    GpioCtrlRegs.GPAGMUX2.bit.GPIO17 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO17 = 1;

    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO18 = 0;
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0;

    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 0;
    GpioCtrlRegs.GPADIR.bit.GPIO19 = 0;
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0;

    GpioCtrlRegs.GPAGMUX2.bit.GPIO20 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO20 = 1;

    GpioCtrlRegs.GPAGMUX2.bit.GPIO21 = 1;
    GpioCtrlRegs.GPAMUX2.bit.GPIO21 = 1;
    GpioCtrlRegs.GPADIR.bit.GPIO21 = 1;

    GpioCtrlRegs.GPBMUX1.bit.GPIO42 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO42 = 1;

    GpioCtrlRegs.GPBMUX1.bit.GPIO43 = 0;
    GpioCtrlRegs.GPBDIR.bit.GPIO43 = 1;

    GpioCtrlRegs.GPBGMUX2.bit.GPIO58 = 3;
    GpioCtrlRegs.GPBMUX2.bit.GPIO58 = 3;
    GpioCtrlRegs.GPBPUD.bit.GPIO58 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO58 = 3;
    GpioCtrlRegs.GPBDIR.bit.GPIO58 = 1;

    GpioCtrlRegs.GPBGMUX2.bit.GPIO59 = 3;
    GpioCtrlRegs.GPBMUX2.bit.GPIO59 = 3;
    GpioCtrlRegs.GPBPUD.bit.GPIO59 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO59 = 3;
    GpioCtrlRegs.GPBDIR.bit.GPIO59 = 1;

    GpioCtrlRegs.GPBGMUX2.bit.GPIO60 = 3;
	GpioCtrlRegs.GPBMUX2.bit.GPIO60 = 3;
	GpioCtrlRegs.GPBPUD.bit.GPIO60 = 0;
	GpioCtrlRegs.GPBQSEL2.bit.GPIO60 = 3;
	GpioCtrlRegs.GPBDIR.bit.GPIO60 = 1;

    GpioCtrlRegs.GPBGMUX2.bit.GPIO61 = 3;
    GpioCtrlRegs.GPBMUX2.bit.GPIO61 = 3;
    GpioCtrlRegs.GPBPUD.bit.GPIO61 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO61 = 3;
    GpioCtrlRegs.GPBDIR.bit.GPIO61 = 1;

    GpioCtrlRegs.GPBGMUX2.bit.GPIO63 = 3;
    GpioCtrlRegs.GPBMUX2.bit.GPIO63 = 3;
    GpioCtrlRegs.GPBPUD.bit.GPIO63 = 0;
    GpioCtrlRegs.GPBQSEL2.bit.GPIO63 = 3;
    GpioCtrlRegs.GPBDIR.bit.GPIO63 = 1;

    GpioCtrlRegs.GPCGMUX1.bit.GPIO64 = 3;
    GpioCtrlRegs.GPCMUX1.bit.GPIO64 = 3;
    GpioCtrlRegs.GPCPUD.bit.GPIO64 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO64 = 3;
    GpioCtrlRegs.GPCDIR.bit.GPIO64 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO65 = 3;
    GpioCtrlRegs.GPCGMUX1.bit.GPIO65 = 3;
    GpioCtrlRegs.GPCPUD.bit.GPIO65 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO65 = 3;
    GpioCtrlRegs.GPCDIR.bit.GPIO65 = 1;

    GpioCtrlRegs.GPCGMUX1.bit.GPIO66 = 0;
    GpioCtrlRegs.GPCMUX1.bit.GPIO66 = 0;
    GpioCtrlRegs.GPCPUD.bit.GPIO66 = 0;
    GpioCtrlRegs.GPCQSEL1.bit.GPIO66 = 3;
    GpioCtrlRegs.GPCDIR.bit.GPIO66 = 1;

	GpioCtrlRegs.GPCMUX1.bit.GPIO69 = 0;
	GpioCtrlRegs.GPCDIR.bit.GPIO69 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO72 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO72 = 1;

    GpioCtrlRegs.GPCMUX1.bit.GPIO73 = 0;
    GpioCtrlRegs.GPCDIR.bit.GPIO73 = 1;

	GpioCtrlRegs.GPCMUX1.bit.GPIO78 = 0;
	GpioCtrlRegs.GPCDIR.bit.GPIO78 = 1;
	//--

	EDIS;
}
