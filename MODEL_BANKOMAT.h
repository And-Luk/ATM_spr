//#include "stdafx.h"

#if !defined(_MODEL_BANKOMAT_)
#define      _MODEL_BANKOMAT_


//#include "Header.h"
#include "DOUBLE_ARRAY.h"                    ////<-----------------------
#include "GLOBAL_FUNCTION.h"




///////////////////////////////////////////////////////////////////////////////////////////////
struct BANKOMAT_STRUCT
{
	string DATE;                   // ����
	string TIME;                   // ����� 
	string ATM;                    // ����� ��������� 
	string ADRES_ASCII;            // ����� ��������� � ����� ����
	string FAMALY_ASCII;           // �������

	string count_str_VYG[4][4];    // DISPENSED: �������  ��������
	string count_str_ZAG[4][4];    // DISPENSED: �������  ��������

	unsigned int count_int_VYG[4][4]; // DISPENSED: �������
	unsigned int count_int_ZAG[4][4]; // DISPENSED: �������

	string SUMMA;                     // ����������� �������� ���������� ����� STRING
	string SUMMA_ASCII;               // ����������� �������� ���������� ����� STRING

	string SUMMA_ZAG;            // ����������� �������� ���������� ����� STRING
	string SUMMA_ZAG_ASCII;      // ����������� �������� ���������� ����� STRING



};

///////////////////////////////////////////////////////////////////////////////////
class MODEL_BANKOMAT
{
public:
	 MODEL_BANKOMAT();                   //MODEL_BANKOMAT(string FILE_NAME);
	virtual ~MODEL_BANKOMAT();

	unsigned int STRING_TO_INT(string IN_STRING);        // �� ����� ����� ���� string IN_STRING -> �� ������ ����� unsigned int 
	string STRING_TO_ASCII(string IN_STRING);            // �� ����� ����� ���� ��� int IN_INT -> �� ������ string ASCII
	string INT_TO_STRING_OF_WORLDS(unsigned int IN_INT); // �� ����� int ������� ����� � �����
	string TranslatePart(int x, short p);                // ������ ����� �������� ����� � �����
	void PUSH_STRUCT_BANKOMAT(BANKOMAT_STRUCT&);          // ��������� ��������� � ��� ������� 
	void TRANS_STRUCT_BANKOMAT();                        // ��������� ��������� � INT ������� 
	unsigned int INT_ROUND(const unsigned int);          // ���������� ����� �� ����� 1990 -> 2000
	void PUSH_DOUBLE_ARRAY_STRUCTUR(DOUBLE_ARRAY&);      // ������� �������� ������� � ����� � ������� �������� ��������
	void PUSH_DOUBLE_ARRAY_STRUCTUR_LOAD(DOUBLE_ARRAY&); // ������� �������� ������� � ����� � ������� �������� ��������
	void operator =(const BANKOMAT_STRUCT);              // ���������� ��� ����������� ���������

	struct BANKOMAT_STRUCT B_STRUCT;

protected:
//private:
	//struct BANKOMAT_STRUCT B_STRUCT;
	//static struct BANKOMAT_STRUCT B_STRUCT;
};

#endif
