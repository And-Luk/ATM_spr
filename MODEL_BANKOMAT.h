//#include "stdafx.h"

#if !defined(_MODEL_BANKOMAT_)
#define      _MODEL_BANKOMAT_


//#include "Header.h"
#include "DOUBLE_ARRAY.h"                    ////<-----------------------
#include "GLOBAL_FUNCTION.h"




///////////////////////////////////////////////////////////////////////////////////////////////
struct BANKOMAT_STRUCT
{
	string DATE;                   // Дата
	string TIME;                   // Время 
	string ATM;                    // Номер банкомата 
	string ADRES_ASCII;            // Адрес банкомата и номер дома
	string FAMALY_ASCII;           // Фамилия

	string count_str_VYG[4][4];    // DISPENSED: кассета  выгрузка
	string count_str_ZAG[4][4];    // DISPENSED: кассета  загрузка

	unsigned int count_int_VYG[4][4]; // DISPENSED: кассета
	unsigned int count_int_ZAG[4][4]; // DISPENSED: кассета

	string SUMMA;                     // расчитанное значение оставшейся суммы STRING
	string SUMMA_ASCII;               // расчитанное значение оставшейся суммы STRING

	string SUMMA_ZAG;            // расчитанное значение оставшейся суммы STRING
	string SUMMA_ZAG_ASCII;      // расчитанное значение оставшейся суммы STRING



};

///////////////////////////////////////////////////////////////////////////////////
class MODEL_BANKOMAT
{
public:
	 MODEL_BANKOMAT();                   //MODEL_BANKOMAT(string FILE_NAME);
	virtual ~MODEL_BANKOMAT();

	unsigned int STRING_TO_INT(string IN_STRING);        // на входе слово типа string IN_STRING -> на выходе число unsigned int 
	string STRING_TO_ASCII(string IN_STRING);            // на входе число типа ште int IN_INT -> на выходе string ASCII
	string INT_TO_STRING_OF_WORLDS(unsigned int IN_INT); // на входе int перевод числа в слова
	string TranslatePart(int x, short p);                // вторая часть перевода числа в слова
	void PUSH_STRUCT_BANKOMAT(BANKOMAT_STRUCT&);          // Получение структуры в для объекта 
	void TRANS_STRUCT_BANKOMAT();                        // Изменение структуры в INT объекта 
	unsigned int INT_ROUND(const unsigned int);          // Округление чисел до сотен 1990 -> 2000
	void PUSH_DOUBLE_ARRAY_STRUCTUR(DOUBLE_ARRAY&);      // Загнать значения поисков и замен в очередь массивов Выгрузка
	void PUSH_DOUBLE_ARRAY_STRUCTUR_LOAD(DOUBLE_ARRAY&); // Загнать значения поисков и замен в очередь массивов Загрузка
	void operator =(const BANKOMAT_STRUCT);              // перегрузка для копирования структуры

	struct BANKOMAT_STRUCT B_STRUCT;

protected:
//private:
	//struct BANKOMAT_STRUCT B_STRUCT;
	//static struct BANKOMAT_STRUCT B_STRUCT;
};

#endif
