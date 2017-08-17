//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"

//-- SPI ------------------------------------------------------------------
void SPI (void) {
	//-- Configuração SPI A ---------------------------------------------------
    /*
     * Configura o SPI A para uso do WIZ550io (Controlador Ethernet SPI - TCP/IP)
     *
     */
/*
	SpiaRegs.SPICCR.bit.SPISWRESET = 0;	// Reset SPI

	SpiaRegs.SPICCR.all = 0x000F;		// 8-bit character
	SpiaRegs.SPICCR.bit.CLKPOLARITY = 1;// Inverte a polaridade do clock
	SpiaRegs.SPICTL.bit.CLK_PHASE = 1;	// Inverte a polaridade do clock
	SpiaRegs.SPICTL.all = 0x0006;		// Transmission Enabled | Master Mode Enabled | Interrupt Disabled
	SpiaRegs.SPIPRI.bit.TRIWIRE = 0;	// Tri-wire communication
	SpiaRegs.SPIBRR.all = 49;		    // Baud rate = LSPCLK / (SPIBRR + 1)
    SpiaRegs.SPIFFTX.all = 0xE040;		//
    SpiaRegs.SPIFFRX.all = 0x204F;		//
    SpiaRegs.SPIFFCT.all = 0x0000;		// Delay de ciclos seriais até o próximo envio
	SpiaRegs.SPIPRI.all = 0x0010;		// Free Run
*/
    //--

    //-- Configuração SPI B ---------------------------------------------------
    /*
     * Configura o SPI B para uso do display (LCD 2x12)
     *
     */
    SpibRegs.SPICCR.bit.SPISWRESET = 0; // Reset SPI

    SpibRegs.SPICCR.all = 0x0008;       // 8-bit character
    SpibRegs.SPICCR.bit.CLKPOLARITY = 1;// Inverte a polaridade do clock
    SpibRegs.SPICTL.bit.CLK_PHASE = 1;  // Inverte a polaridade do clock
    SpibRegs.SPICTL.all = 0x0006;       // Transmission Enabled | Master Mode Enabled | Interrupt Disabled
    SpibRegs.SPIPRI.bit.TRIWIRE = 1;    // Tri-wire communication
    SpibRegs.SPIBRR.all = 7;            // Baud rate = LSPCLK / (SPIBRR + 1)
    SpibRegs.SPIFFTX.all = 0xE040;      //
    SpibRegs.SPIFFRX.all = 0x204F;      //
    SpibRegs.SPIFFCT.all = 0x0000;      // Delay de ciclos seriais até o próximo envio
    SpibRegs.SPIPRI.all = 0x0010;       // Free Run

    //--

	SpiaRegs.SPICCR.bit.SPISWRESET = 1;	// Enable SPI
	SpibRegs.SPICCR.bit.SPISWRESET = 1; // Enable SPI
}
