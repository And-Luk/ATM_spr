#include"stdafx.h"

#include "READ_RTF.h"


READ_RTF::READ_RTF() : DOUBLE_ARRAY()   //  : DOUBLE_ARRAY()  было закентено
{
	//cout << "  Конструктор READ_RTF без аргументов = " << this << endl;   // проверка на присутствие файла TEST.jrn
	file_name_IN  = "Report.RTF";
	file_name_OUT = "D://ATM_OUT/OUT_FILE.RTF";             // ("D://ATM_IN/OUT_FILE.RTF")
}


//in.open(File_NAME_IN);                
READ_RTF::READ_RTF(string File_NAME_IN) : DOUBLE_ARRAY()
{   
	//cout << "  Конструктор READ_RTF с аргументом " << " =  " << this << endl;   // проверка на присутствие файла TEST.jrn
	file_name_IN  = File_NAME_IN;
	file_name_OUT = "D://ATM_OUT/OUT_FILE.RTF";
}


READ_RTF::~READ_RTF()
{	
	//cout << "  Деструктор  READ_RTF = " << this->file_name_IN << " = " << this << endl;
}

//////////////////////////////////////////////////////////////////////////////////
//bool READ_RTF::READ_FILE_RTF(DOUBLE_ARRAY&)
// открыть файл RTF для клонирования
bool READ_RTF::READ_FILE_RTF(DOUBLE_ARRAY &DOUB_ARR, string PATH_NAME_IN, string PATH_NAME_OUT) //(DOUBLE_ARRAY &DOUB_ARR)
{
	string IN_GET_CHAR;              // строка для щитывания строки из файла
	size_t END_RTF ;                  // счётчик скобок "{"   "}"
	char ch;                         // символ для считывания из файла
	char BUFER[MAX];                 // буфер перед выводом в файл

//////////////////////////////////////////////////////////////////////////////////////////////////
// открыть файл RTF для клонирования
	in.open(PATH_NAME_IN);

	if (!in)
	{
		cout << "    Нет RTF файла " << file_name_IN << " для чтения" << endl;   // проверка на присутствие файла TEST.jrn
	}

// порождение потокового объекта буфера в памяти 
// создать потоковый объект в памяти
	ostrstream Object_Memory(BUFER, MAX);   

											

		
//////////////////////////////////////////////////////////////////////////////////////////////////
//  получение строки считывание посимвольно до символа "}"

	END_RTF = 0;

	// пока не конец RTF а !END_RTF = 0;
	do
	{

		do
		{
			IN_GET_CHAR.erase();
			do
			{
				in.get(ch);
				if (ch == '{')          // заменять  перевод каретки на конец строки
				{
					++END_RTF;
				}
				if (ch == '}')          // заменять  перевод каретки на конец строки
				{
					--END_RTF;
				}

				IN_GET_CHAR.push_back(ch);

			} while (ch != '}');


			if (true)
			{

				
				for (size_t i = 0; i < DOUB_ARR.DOB_END_QUE_ARR.size(); i++)
				{
					PTR = DOUB_ARR.DOB_END_QUE_ARR[i];   //DOUBLE_ARRAY
					SEARCH_WORLD = PTR[0];
					INSERT_WORLD = PTR[1];

					
					int POZ;    //позиция в искомой строки в считываемой из файла
					POZ = IN_GET_CHAR.find(SEARCH_WORLD);
					if (POZ > 0)
					{
	
						IN_GET_CHAR.replace(POZ, SEARCH_WORLD.size(), INSERT_WORLD);

						SEARCH_WORLD.clear();
						INSERT_WORLD.clear();
						break;
					}

				}
				



			}

//////////////////////////////////////////////////////////////////////////////////////////////////
// загнать в буфер перед выыодом в файл
			Object_Memory << IN_GET_CHAR;
			
			IN_GET_CHAR.clear();

		} while (!IN_GET_CHAR.empty() && END_RTF!=0);


	} while (END_RTF!=0);/////////////////////  конец чтения файла RTF
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// закрыть RTF
	in.close();

/////////////////////////////////////////////////////////////////////////////////////////
//   завершить буфер "\0"
	Object_Memory << '\0';
/////////////////////////////////////////////////////////////////////////////////////////
// создать выходной файл  "ATM_11571_DATE_OUT.RTF"
	file_name_OUT = PATH_NAME_OUT;

	
	ofstream   out (file_name_OUT);          
	out << BUFER;
	out.close();





// очистить выделенную память
	while (!DOUB_ARR.DOB_END_QUE_ARR.empty())
	{
		delete[] DOUB_ARR.DOB_END_QUE_ARR.front();
		DOUB_ARR.DOB_END_QUE_ARR.pop_front();
	}


	

	return false;

/////////////////////////////////////////////////////////////////////////////////////////
}//////////  END  //////// bool READ_RTF::READ_FILE_RTF() ///////////////////////////////