/*\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\
		 	    |
-     BIBLIOTECA: LCD_SPI
________________|__________________________________________________________
			    |
-           DATA: 06/10/2016
-         VERSÃO: 1.0
________________|__________________________________________________________
 			    |
-DESENVOLVIMENTO: LUCAS MUNARETTO - INEP
_______________ |__________________________________________________________
			    |
-    OBSERVAÇÕES:	Biblioteca para utilizar display lcd com shift register
				| externo e spi interno (do DSP).
				|	Lembrar de configurar o periférico do SPI corretamente
				| 	Esta biblioteca utiliza do SPI-B (configuravel)
_______________ |__________________________________________________________
			    |
-        FUNÇÕES:	LCD_byte(uint16_t command, uint16_t data)
				| 		command:	CMD 	- Enviar comando
				| 		        	DATA 	- Enviar dado
				|
				| 		data:	0bXXXXXXXX 	- Envia 8 bits da esquerda para
				|							a direita
				|__________________________________________________________
				|
				|	void LCD_nible(uint16_t command, uint16_t data)
				| 		command:	CMD 	- Enviar comando
				| 		        	DATA 	- Enviar dado
				|
				| 		data:	0bXXXX 	- Envia 4 bits da esquerda para
				|						a direita
				|__________________________________________________________
				|
				|	void LCD_string(char* strpointer)
				|		strpointer:	- Escreve char por char até acabar a
				|					string inserida
				|__________________________________________________________
				|
				|	void LCD_number(float number)
				|		number:	- Escreve números entre -9999,9 e  +9999,9
				|__________________________________________________________
				|
				|	void LCD_posit(uint16_t row, uint16_t col)
				|		row:	- Escolhe a linha para posicionar o cursor
				|
				|		col:	- Escolhe a coluna para posicionar o cursor
				|				- Primeira coluna é a 0
				|__________________________________________________________
				|
				|	void LCD_disp(uint16_t display, uint16_t cursor, uint16_t cursor_blink)
				|		display:	0	- Display Off
				|					1	- Display On
				|
				|		cursor:	0	- Cursor Off
				|				1	- Cursor On
				|
				|		cursor_blink:	0	- Blink Cursor Off
				|						1	- Blink Cursor On
_______________ |__________________________________________________________
\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\\*/

//-- Includes -------------------------------------------------------------
#include "F2837xS_device.h"
#include "F2837xS_Examples.h"
#include "LCD_SPI.h"

void LCD_byte(uint16_t command, uint16_t data) {
	uint16_t h_nible,
			 l_nible;

	h_nible = (data & 0xF0) >> 4;
	l_nible = (data & 0x0F);

	LCD_nible(command, h_nible);
	LCD_nible(command, l_nible);
}

void LCD_nible(uint16_t command, uint16_t data) {
	while (SpibRegs.SPISTS.bit.BUFFULL_FLAG);
	SpibRegs.SPITXBUF = (command << 4 | data) << 8;
	while (SpibRegs.SPISTS.bit.BUFFULL_FLAG);
	DELAY_US(1);
	GpioDataRegs.GPCSET.bit.GPIO66 = 1;
	DELAY_US(3);
	GpioDataRegs.GPCCLEAR.bit.GPIO66 = 1;
	DELAY_US(1);
}

void LCD_string(char* strpointer){
	uint16_t h_nible,
			 l_nible;

	while (*strpointer) {
		h_nible = (*strpointer & 0xF0) >> 4;
		l_nible = (*strpointer & 0x0F);

		DELAY_US(40);

		LCD_nible(DATA, h_nible);
		LCD_nible(DATA, l_nible);

		strpointer++;
	}
}

void LCD_number(float number) {
	char str[9];
	int i = 0,
		flag = -1,
		comma = -1;

	str[0] = '\0';
	str[1] = '\0';
	str[2] = '\0';
	str[3] = '\0';
	str[4] = '\0';
	str[5] = '\0';
	str[6] = '\0';
	str[7] = '\0';

	if (number == 0) {
		str[0] = '0';
		str[1] = ',';
		str[2] = '0';
		str[3] = '0';
		str[4] = ' ';
	} else if(number < 10000.0 && number > -10000.0) {

		if(number < 0) {
			str[i++] = '-';
			number *= -1;
		}
		if (number >= 1000) {
			str[i] = '0';
			str[i+1] = '0';
			str[i+2] = '0';
			str[i+3] = '0';
			comma = i+4;
			flag = 1;
		} else if (number >= 100) {
			str[i] = '0';
			str[i+1] = '0';
			str[i+2] = '0';
			str[i+3] = ' ';
			comma = i+3;
			flag = 2;
		} else if (number >= 10) {
			str[i] = '0';
			str[i+1] = '0';
			str[i+2] = ',';
			str[i+3] = '0';
			comma = i+2;
			flag = 3;
		} else if (number >= 1){
			str[i] = '0';
			str[i+1] = ',';
			str[i+2] = '0';
			str[i+3] = '0';
			comma = i+1;
			flag = 4;
		} else if (number >= 0.1){
			str[i] = '0';
			str[i+1] = ',';
			str[i+2] = '0';
			str[i+3] = '0';
			comma = i+1;
			flag = 5;
			i = i + 2;
		} else if (number >= 0.01){
			str[i] = '0';
			str[i+1] = ',';
			str[i+2] = '0';
			str[i+3] = '0';
			comma = i+1;
			flag = 6;
			i = i +3;
		}

		if (flag <= 1) {
			if (i == comma)
				i++;
			while (number >= 1000) {
				str[i]++;
				number -= 1000;
			}
			i++;
		}

		if (flag <= 2) {
			if (i == comma)
				i++;
			while (number >= 100) {
				str[i]++;
				number -= 100;
			}
			i++;
		}

		if (flag <= 3) {
			if (i == comma)
				i++;
			while (number >= 10) {
				str[i]++;
				number -= 10;
			}
			i++;
		}

		if (flag <= 4) {
			if (i == comma)
				i++;
			while (number >= 1) {
				str[i]++;
				number -= 1;
			}
			i++;
		}

		if (flag <= 5 && flag >= 3) {
			if (i == comma)
				i++;
			while (number >= 0.1) {
				str[i]++;
				number -= 0.1;
			}
			i++;
		}

		if (flag <= 6 && flag >= 4) {
			if (i == comma)
				i++;
			while (number >= 0.01) {
				str[i]++;
				number -= 0.01;
			}
		}

	} else {
		str[0] = 'E';
		str[1] = 'R';
		str[2] = 'R';
		str[3] = 'O';
	}
	LCD_string(str);
}

void LCD_posit(uint16_t row, uint16_t col){
	DELAY_US(38);
	switch (row){
	case 1:
		LCD_byte(CMD,(0x80 | col));
		break;
	case 2:
		LCD_byte(CMD,(0x80 | (col+0x40)));
		break;
	}
}

void LCD_disp(uint16_t display, uint16_t cursor, uint16_t cursor_blink) {
	DELAY_US(38);
	LCD_byte(CMD, 0x08 | display << 2 | cursor << 1 | cursor_blink);
}

void LCD_init(void) {
	DELAY_US(20000);
	LCD_nible(CMD,0x03);
	DELAY_US(5000);
	LCD_nible(CMD,0x03);
	DELAY_US(2000);
	LCD_nible(CMD,0x03);
	DELAY_US(5000);
	LCD_nible(CMD,0x02);
	DELAY_US(500);
	LCD_byte(CMD,0x2C);
	DELAY_US(500);
	LCD_byte(CMD,0x06);
	DELAY_US(500);
	LCD_byte(CMD,0x0C);
	DELAY_US(500);
	LCD_byte(CMD,0x01);
	DELAY_US(1500);
}
