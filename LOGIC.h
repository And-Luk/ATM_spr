
#if !defined(_LOGIC_)
#define      _LOGIC_


#include "READ_FILE.h"
#include "MODEL_BANKOMAT.h"
#include "GLOBAL_FUNCTION.h"

// :public  READ_FILE �� ��������    
class LOGIC                              
{
public:
	  LOGIC();                           // LOGIC(string FILE_ini)
	 ~LOGIC();
	 BANKOMAT_STRUCT READ_LOGIC(string);       // READ_FILE &(READ_INI(string)) BANKOMAT_STRUCT
	 
	 class LOGIC_RANGE {};
	 class LOGIC_RANGE_TU {};

private:
	// READ_FILE READ_INI(string);       // ��� �� ������� ���� �������� ������ // static READ_FILE READ_INI(string); 
	// READ_FILE READ_INI(string);
	// READ_FILE READ_INI(string FILE);  // ��� ������ �������� READ_FILE READ_INI("ATM_spr.ini");
	// READ_FILE* pREAD_INI;
};


#endif