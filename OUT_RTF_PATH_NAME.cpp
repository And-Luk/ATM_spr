
#include "stdafx.h"
#include "OUT_RTF_PATH_NAME.h"


OUT_RTF_PATH_NAME::OUT_RTF_PATH_NAME()
{
	//cout << "  Конструктор OUT_RTF_PATH_NAME  = " << this << endl;
}


OUT_RTF_PATH_NAME::~OUT_RTF_PATH_NAME()
{
	//cout << "  Деструктор  OUT_RTF_PATH_NAME = " << this << endl;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// возвращает  путь выхода и имя файла RTF
// 
string* OUT_RTF_PATH_NAME::OUT_P_N(MODEL_BANKOMAT & BANKOMAT, ARG_COMAND& ARG_C)
{
	//string OUT_P[2];
	//string IN_P[2];
	string TEMP;
	string TEMP_ARR[2];
//	TEMP_ARR[0] = (ARG_C.PATH_IN_OUT())[0];
//	TEMP_ARR[1] = (ARG_C.PATH_IN_OUT())[0];

// "D:\\ATM_OUT\\ATM_2017.04.03_UN.rtf"

	TEMP = ARG_C.Output_Directory();
	TEMP += BANKOMAT.B_STRUCT.ATM;
	TEMP += "_";
	TEMP += BANKOMAT.B_STRUCT.DATE;
	TEMP += "_UN.rtf";
	OUT_P[0] = TEMP;


// "D:\\ATM_OUT\\ATM_2017.04.03_LOAD.rtf"
	TEMP = ARG_C.Output_Directory();
	TEMP += BANKOMAT.B_STRUCT.ATM;
	TEMP += "_";
	TEMP += BANKOMAT.B_STRUCT.DATE;
	TEMP += "_LOAD.rtf";
	OUT_P[1] = TEMP;



	return OUT_P;



}
