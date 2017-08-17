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
				| externo e spi interno (do DSP)
				|	Lembrar de configurar o periférico do SPI corretamente
				| 	Esta biblioteca utiliza o SPI-A
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

//-- Variáveis ------------------------------------------------------------
#define CMD 0x00
#define DATA 0x01

//-- Funções --------------------------------------------------------------
extern void LCD_byte(uint16_t command, uint16_t data);
extern void LCD_nible(uint16_t command, uint16_t data);
extern void LCD_string(char* strpointer);
extern void LCD_number(float number);
extern void LCD_posit(uint16_t row, uint16_t col);
extern void LCD_disp(uint16_t display, uint16_t cursor, uint16_t cursor_blink);
extern void LCD_init(void);
