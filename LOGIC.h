
#if !defined(_LOGIC_)
#define      _LOGIC_


#include "READ_FILE.h"
#include "MODEL_BANKOMAT.h"
#include "GLOBAL_FUNCTION.h"

// :public  READ_FILE не работает    
class LOGIC                              
{
public:
	  LOGIC();                           // LOGIC(string FILE_ini)
	 ~LOGIC();
	 BANKOMAT_STRUCT READ_LOGIC(string);       // READ_FILE &(READ_INI(string)) BANKOMAT_STRUCT
	 
	 class LOGIC_RANGE {};
	 class LOGIC_RANGE_TU {};

private:
	// READ_FILE READ_INI(string);       // так по крайней мере создаётся объект // static READ_FILE READ_INI(string); 
	// READ_FILE READ_INI(string);
	// READ_FILE READ_INI(string FILE);  // так объект создаётся READ_FILE READ_INI("ATM_spr.ini");
	// READ_FILE* pREAD_INI;
};


#endif