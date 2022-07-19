//#include "stdafx.h"

#if !defined (_READ_FILE_)
#define       _READ_FILE_

//#include "Header.h"
#include "GLOBAL_FUNCTION.h"



//////////////////////////////////////////////////////////////////////////////
// если строка поиска пуста вернуть через неё строку  а метод возвращает NULL
// возврат строки через  SEARCH_WORLD если он был пуст при вызове метода
class READ_FILE
{
public:
	READ_FILE();
	READ_FILE(string FILE_NAME);  //FILE_NAME
	~READ_FILE();
	bool READ_FILE_FUNCTION(deque<string> &DOBLE_ENDED_QUEUE, char* &SEARCH_WORLD, char* MISSING_CHAR);  //(deque<string> & DOBLE_ENDED_QUEUE)
	//friend void READ_LOGIC(READ_FILE);
	class Range {};


private:
	string file_name;                           // ("TEST.jrn")
	static const int MAX = 200;
	char line[MAX];                             // стек в виде массива
	string file_line;                           // стек в в string
	string search_world;
	string read_world;
	ifstream in;                                // потоковый объект

};
#endif
