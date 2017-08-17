/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\


___________________________________________________________________________
		 	    |
-        PROJETO: 28377_LIMPO
________________|__________________________________________________________
			    |
-           DATA: 20/03/2017
-    ATUALIZAÇÃO: 30/06/2017
-         VERSÃO: 1.1
________________|__________________________________________________________
 			    |
-DESENVOLVIMENTO: LUCAS MUNARETTO
-   ORIENTADORES:
_______________ |__________________________________________________________
			    |
-    OBSERVAÇÕES: Função de build para FLASH e RAM
				| Possui biblioteca para display LCD (2x12)
				| SPIs pré configurados para display e WIZ550io
_______________ |__________________________________________________________
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"     // F2837xS Headerfile Include File
#include "F2837xS_Examples.h"   // F2837xS Examples Include File
#include "LCD_SPI.h"

//-- Funções --------------------------------------------------------------
void GPIO	(void);
void ADC 	(void);
void PWM 	(void);
void TIMER	(void);
void ISR	(void);
void SPI	(void);

//-- Funções da Flash para RAM --------------------------------------------
#ifdef FLASH

#endif

//-- Variáveis ------------------------------------------------------------
float teste = 0;

//-- Main -----------------------------------------------------------------
int main(void) {
    #ifdef FLASH
        memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, (size_t)&RamfuncsLoadSize);
    #endif

	//-- Inicializar Clock do Sistema -----------------------------------------

    InitSysCtrl();

	//-- Inicializar Controle do PIE ------------------------------------------
	DINT;
	InitPieCtrl();
	IER = 0x00000000;
	IFR = 0x00000000;
	InitPieVectTable();

	//-- Inicializar Periféricos ----------------------------------------------
	GPIO 	();
	ADC		();
	PWM		();
	TIMER	();
	ISR		();
	SPI		();

    //-- Inicializa o LCD -----------------------------------------------------
    LCD_init();
    LCD_posit(1,0);
    LCD_string("Tensao:         ");
    LCD_posit(2,0);
    LCD_string("Corrente:       ");

	//-- Main Loop ------------------------------------------------------------
	for(;;){
        DELAY_US(500000);
        //teste = 320;//(float)AdcaResultRegs.ADCRESULT0*3.3/4095;
        LCD_posit(1,9);
        LCD_number(teste);
        LCD_posit(2,9);
        LCD_number(teste);
	}
}
