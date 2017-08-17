//-- Includes
//-------------------------------------------------------------------------
#include "CLA.h"

//-- Defines
//-------------------------------------------------------------------------
#define CLK 200000000.0
#define F_PWM 50000.0
#define F_REDE 60.0
#define VBAR_NOM 380.0
#define VREDE_NOM 311.01269837
#define VPWM_NOM 1000.0*VREDE_NOM/VBAR_NOM

//-- Variáveis
//-------------------------------------------------------------------------

//-- Estrutura
//-------------------------------------------------------------------------

typedef struct {
    float Va;
    float Vb;
    float Vc;

} _Vsenos;

extern _Vsenos Vsenos;


typedef struct
{
    float Valfa;
    float Vbeta;

} _Alfa_beta;

extern _Alfa_beta Alfa_beta;

typedef struct
{
    float d;
    float q;

} _DQ;

extern _DQ DQ;

typedef struct
{
    float Va;
    float Vb;
    float Vc;

} _Inverse_Alfa_beta;

extern _Inverse_Alfa_beta Inverse_Alfa_beta;

typedef struct
{
    float Va;
    float Vb;
    float Vc;

} _Inverse_D_Q;

extern _Inverse_D_Q Inverse_D_Q;


//-- Funções
//-------------------------------------------------------------------------
