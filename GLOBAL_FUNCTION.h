//#pragma once
//#include "stdafx.h"

#if !defined (_GLOBAL_FUNCTION_)
#define       _GLOBAL_FUNCTION_

#include "Header.h"



// ���������� ������� ������� �� � �������������
size_t STRING_TO_CHAR(string , char* );

// ���������� ������� �������  ---->, size_t &OUT_POSITION
bool PARSING_STRING(char*, char*, char*, deque<string>&, size_t&);

// ���������� ������� ������� �� � �������������
string INT_TO_STRING(const unsigned int);

// �������� �����
void DELETE_FILE(const string FILE_NAME);


#endif