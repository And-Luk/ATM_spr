//#pragma once
//#include "stdafx.h"

#if !defined (_GLOBAL_FUNCTION_)
#define       _GLOBAL_FUNCTION_

#include "Header.h"



// объ€вление внешней функции до еЄ использовани€
size_t STRING_TO_CHAR(string , char* );

// объ€вление внешней функции  ---->, size_t &OUT_POSITION
bool PARSING_STRING(char*, char*, char*, deque<string>&, size_t&);

// объ€вление внешней функции до еЄ использовани€
string INT_TO_STRING(const unsigned int);

// удаление файла
void DELETE_FILE(const string FILE_NAME);


#endif