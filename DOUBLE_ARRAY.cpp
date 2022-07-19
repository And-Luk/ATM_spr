#include "stdafx.h"

#include "DOUBLE_ARRAY.h"



DOUBLE_ARRAY::DOUBLE_ARRAY()
{
	//cout << "  Конструктор DOUBLE_ARRAY  = " << this << endl;  
}

DOUBLE_ARRAY::~DOUBLE_ARRAY()
{
	//cout << "  Деструктор  DOUBLE_ARRAY = " << this << endl;
	//while ( !this->DOB_END_QUE_ARR.empty()   );
	//{
	//	delete[] this->DOB_END_QUE_ARR.front();
	//	this->DOB_END_QUE_ARR.pop_front();
	//}
	
}

// Запихнуть в очередь DOB_END_QUE_ARR указатель на массив string ARR_DOB[2];
// Входящие строка поиска(заменяемая) SEARCH и вставляемая строка INSERT
bool DOUBLE_ARRAY::PUSH_DOUBLE_ARRAY(string SEARCH, string INSERT)
{

	PTR = new string [2];  //выделить память под Array 
	PTR[0] = SEARCH;
	PTR[1] = INSERT;
	DOB_END_QUE_ARR.push_back(PTR);

	return true;
};
