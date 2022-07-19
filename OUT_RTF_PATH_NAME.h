#pragma once
//#include"stdafx.h"

#ifndef _OUT_RTF_PATH_NAME_
#define _OUT_RTF_PATH_NAME_


//#include "Header.h"
#include "ARG_COMAND.h"
#include "MODEL_BANKOMAT.h"


class OUT_RTF_PATH_NAME //: public MODEL_BANKOMAT , ARG_COMAND   //friend MODEL_BANKOMAT
{
public:
	OUT_RTF_PATH_NAME();
   ~OUT_RTF_PATH_NAME();
   string* OUT_P_N(MODEL_BANKOMAT&, ARG_COMAND& );

private:
	string OUT_P[2];  // двумерный массив выходных файлов
	string IN_P[2];   // двумерный массив входных файлов


};

#endif 