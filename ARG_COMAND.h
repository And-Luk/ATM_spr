//#pragma once
//#include"stdafx.h"

#ifndef _ARG_COMAND_
#define _ARG_COMAND_

#include"Header.h"
#include "GLOBAL_FUNCTION.h"
//#include "MODEL_BANKOMAT.h"


class ARG_COMAND// :public MODEL_BANKOMAT
{
public:
	ARG_COMAND();
	ARG_COMAND(const int , _TCHAR* const* );     //  (int argc, char* argv[]) 
   ~ARG_COMAND();

  string Input_Directory();
  string Output_Directory();
	void READ_DIRECTORY();
	bool EMPTY_DOB_ARR(bool DEL_OR_NO);
	string OUT_DOB_ARR(bool);
	string* PATH_IN_OUT();

private:

	int arg;
	_TCHAR* Input;
	_TCHAR* Output;
	deque<string> DOB_ARR;
	string INPUT_S;
	string OUTPUT_S;




};
#endif 



