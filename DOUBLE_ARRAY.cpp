#include "stdafx.h"

#include "DOUBLE_ARRAY.h"



DOUBLE_ARRAY::DOUBLE_ARRAY()
{
	//cout << "  ����������� DOUBLE_ARRAY  = " << this << endl;  
}

DOUBLE_ARRAY::~DOUBLE_ARRAY()
{
	//cout << "  ����������  DOUBLE_ARRAY = " << this << endl;
	//while ( !this->DOB_END_QUE_ARR.empty()   );
	//{
	//	delete[] this->DOB_END_QUE_ARR.front();
	//	this->DOB_END_QUE_ARR.pop_front();
	//}
	
}

// ��������� � ������� DOB_END_QUE_ARR ��������� �� ������ string ARR_DOB[2];
// �������� ������ ������(����������) SEARCH � ����������� ������ INSERT
bool DOUBLE_ARRAY::PUSH_DOUBLE_ARRAY(string SEARCH, string INSERT)
{

	PTR = new string [2];  //�������� ������ ��� Array 
	PTR[0] = SEARCH;
	PTR[1] = INSERT;
	DOB_END_QUE_ARR.push_back(PTR);

	return true;
};
