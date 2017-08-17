//-- CLA - Defines
//-------------------------------------------------------------------------
#define WAITSTEP    asm(" RPT #255 || NOP")

//-- CLA - Funções
//-------------------------------------------------------------------------
extern void CLA_runTest(void);
extern void CLA_configClaMemory(void);
extern void CLA_initCpu1Cla1(void);

//-- CLA - Task 1
//-------------------------------------------------------------------------
__interrupt void Cla1Task1();
extern float fVal; //input
extern float fResult;  //Estimated result

//-- CLA - Task 2
//-------------------------------------------------------------------------
__interrupt void Cla1Task2();

//-- CLA - Task 3
//-------------------------------------------------------------------------
__interrupt void Cla1Task3();

//-- CLA - Task 4
//-------------------------------------------------------------------------
__interrupt void Cla1Task4();

//-- CLA - Task 5
//-------------------------------------------------------------------------
__interrupt void Cla1Task5();

//-- CLA - Task 6
//-------------------------------------------------------------------------
__interrupt void Cla1Task6();

//-- CLA - Task 7
//-------------------------------------------------------------------------
__interrupt void Cla1Task7();

//-- CLA - Task 8
//-------------------------------------------------------------------------
__interrupt void Cla1Task8();

