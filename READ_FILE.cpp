// если строка поиска пуста вернуть через неё строку  а метод возвращает NULL
// возврат строки через  SEARCH_WORLD если он был пуст при вызове метода
#include "stdafx.h"

#include "READ_FILE.h"


READ_FILE::READ_FILE()
{}



READ_FILE::READ_FILE(string FILE_NAME)
{
	file_name = FILE_NAME;
	in.open(FILE_NAME);                // open for read
 	//cout << "  Конструктор READ_FILE " << FILE_NAME << " =  "<<this << endl;   // проверка на присутствие файла TEST.jrn
}

READ_FILE::~READ_FILE()
{
	in.close();
	//cout << "  Деструктор  READ_FILE = " << this->file_name << " = " << this << endl;
}

// возврат строки через  SEARCH_WORLD если он был пуст при вызове метода deque<string> & DOBLE_ENDED_QUEUE
//	char* SEARCH_WORLD = "=REMAINING";   // найти слово за размер которого будет указывать iterator a;
//	char* MISSING_CHAR = " -:";          // пропускаемые символы после найденного слова
//  ifstream in(file_name);              // ("TEST.jrn")
bool READ_FILE::READ_FILE_FUNCTION(deque<string> &DOBLE_ENDED_QUEUE, char* &SEARCH_WORLD, char* MISSING_CHAR)
{



	DOBLE_ENDED_QUEUE.clear();


	if (!MISSING_CHAR)         // если  MISSING_CHAR не определён
	{
		MISSING_CHAR = " ";
	}


	if (!in)
	{    
		//cout << "  Метод READ_FILE::READ_FILE_FUNCTION." << endl;
		cout << "  Нет файла для чтения ! " << endl;

		cout << "  " << (this->file_name) << endl;

		throw Range();

	}







	size_t n_poz = 0;
	size_t n_SEARCH_WORLD = 0;



	bool PUST_STROKA = true;
	bool NO_MISSING_FILE = true;                      // возможно не закрытый файл  пока отрицание  NO_MISSING_FILE
	string IN_GET_CHAR;  // строка для щитывания стролки из файла

	while (PUST_STROKA && !in.eof())
	{




		IN_GET_CHAR.erase();


		///size_t www;                         //     <--------удалить
		///www = IN_GET_CHAR.size();          ///     <--------удалить  IN_GET_CHAR.size()= = 0
	
		do
		{



			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			//проверить в конце NO_MISSING_FILE

			while (!in.eof() && in.good() && NO_MISSING_FILE && IN_GET_CHAR.empty())
			{
				char ch;                              // символ для считывания


				//////////////////////////////////////////////////////////////////////////////////////////////////
				//  получение строки считывание посимвольно
				n_poz = 0;
				do
				{
					in.get(ch);
					if (ch == '\r' || ch == '\n')          // заменять  перевод каретки на конец строки
					{
						ch = '\0';
						break;
					}
					++n_poz;
					IN_GET_CHAR.push_back(ch);

					if ((MAX - 3) < IN_GET_CHAR.size())   //  n_poz>199 если битый файл игнорировать последнюю строку "типа"
					{
						//ch = '\0';
						IN_GET_CHAR.push_back(ch);
						NO_MISSING_FILE = false;         // оказалось что файл не закрыт
						break;
					}
				} while (ch != '\r' && ch != '\0'&&ch != '\n');



			}

		
		} while (IN_GET_CHAR.empty());





		//  запихнуть строку из string IN_GET_CHAR в массив line
		/////////////////////////////////////////////////////////////////////////////////////////
		STRING_TO_CHAR(IN_GET_CHAR, line);

		/////////////////////////////////////////////////////////////////////////////////////////

		// возврат строки через  SEARCH_WORLD если он был пуст при вызове метода
		if (SEARCH_WORLD==NULL)   // если строка поиска пуста NULL вернуть через неё строку   //SEARCH_WORLD==NULL
		{
			SEARCH_WORLD = line;
			return false;
		}


		// начать анализировать строку и если найдено искомое слово искать за ним нужные лексемы  или слова
		char* ptr;
		size_t a = 0;                 //////////////<----------------------------------------------------
		ptr = search(line, line + MAX, SEARCH_WORLD, SEARCH_WORLD + strlen(SEARCH_WORLD));
		if (ptr != line + MAX)
		{
			PUST_STROKA = true;
			read_world.erase();

			a = static_cast<size_t> (ptr - line + strlen(SEARCH_WORLD));   // указывает на символ за найденным словом



			bool NO_MISSING_CHAR = true;                    // пропустить символ по совпадению из массива MISSING_CHAR
			////////////////////////////////////////////////// пока не конец строки находить и запихивать в контейнер
			while (line[a] != '\0')                         // пока не конец строки
			{


				while (line[a] != '\0' && line[a] != '\n'&& NO_MISSING_CHAR)  // пропустить разделители из массива MISSING_CHAR
				{
					for (size_t i = 0; i < strlen(MISSING_CHAR); i++)
					{
						NO_MISSING_CHAR = false;
						if (line[a] == MISSING_CHAR[i])
						{
							NO_MISSING_CHAR = true;
							++a;
							break;
						}
					}
				}


				//  переделать код ниже если окончание искомого слова заканчивается не пробелом ..&& line[a] != ' '
				//<<<<<<<<<<------------------------------------------------------------------>>>>>>>>>>>
				// пока не конец строки и не "line[a] != '\n' && и не пробел за первым найденным словом "
				while (line[a] != '\0' && line[a] != ' ')  // читать слово из массива до пробела
				{
					read_world.push_back(line[a]);
					++a;
				}

// если в "read_world" есть слово - запихнуть во внешнюю двусторонню очередь "DOBLE_ENDED_QUEUE" а там посмотрим
				if (!read_world.empty())
				{
					DOBLE_ENDED_QUEUE.push_back(read_world);
					read_world.clear();
					PUST_STROKA = false;
				}
				NO_MISSING_CHAR = true;  // цикл можно продолжать
			}

			

		}

	}
	

// если  конец файла или проблемы с чтением  или возможно не закрытый файл	"return true"    иначе    "return false;"
	if (in.eof() && DOBLE_ENDED_QUEUE.empty() )  //&& !in.good() && !NO_MISSING_FILE
	{
		//cout << "  Метод READ_FILE::READ_FILE_FUNCTION." << endl;
		cout << "  " << this->file_name << endl;
		cout << "  Файл журнала прочитан, искомое не найдено !" << endl;
		throw Range();
		return true;
	}
	else
	{
		return false;
	}


}
