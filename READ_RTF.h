//#include"stdafx.h"

#if !defined (_READ_RTF_)
#define       _READ_RTF_

//#include "Header.h"
#include "DOUBLE_ARRAY.h"
#include "GLOBAL_FUNCTION.h"


//class READ_RTF : public DOUBLE_ARRAY
class READ_RTF: public DOUBLE_ARRAY
{
public:
	READ_RTF();
	READ_RTF(string File_NAME_IN);
	~READ_RTF();
	bool READ_FILE_RTF(DOUBLE_ARRAY&, string, string);
private:
	string file_name_IN;           // ("D:\\ATM_IN\REPORT.RTF")
	string file_name_OUT;          // ("D:\\ATM_IN\OUT_FILE.RTF")

	static const int MAX = 300000;        // ~270 килобайт 
	//char line[MAX];                             // стек в виде массива

	string SEARCH_WORLD;      //  искома€ строка
	string INSERT_WORLD;      //  вставл€ема€ строка


	ifstream in;   // объ€вление в *.h файле in
	//ofstream out;  // это не работает

};

#endif