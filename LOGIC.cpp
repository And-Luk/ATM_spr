#include "stdafx.h"

#include "LOGIC.h"


///////////////////////////////////////////////////////////////////////////////////////////
//     LOGIC()
LOGIC::LOGIC()       
{
	//cout << "  Конструктор LOGIC  = " << this << endl; 
}

///////////////////////////////////////////////////////////////////////////////////////////
LOGIC::~LOGIC()
{
	//cout  << "  Деструктор  LOGIC = " << this << endl;  
}

///////////////////////////////////////////////////////////////////////////////////////////
//     BANKOMAT_STRUCT READ_LOGIC();              
BANKOMAT_STRUCT LOGIC::READ_LOGIC(string FUL_PATH )   
{
	BANKOMAT_STRUCT BAN_STR;


	const int MAX = 100;             // static const int MAX = 200;
	char TEMP_line[MAX];             // стек в виде массива
	char* block = " ";
	char* S_WORLD;                  // искомое слово 
	deque<string> D_ENDED_Q(0);      // двусторонняя очередь по ссылке из метода класса READ_FILE
	string TEMP_str;
	size_t POZ;                      // PARSING_STRING
	const size_t MIN = 20;
	char A[MIN];
	char B[MIN];
	//string Input, Output;

	//string FILE_NAME;              // ("D:\\ATM_IN\\*.jrn")
	





	READ_FILE RJrnF(FUL_PATH);          // ("D://ATM_IN/*.jrn");
	READ_FILE RIniF("ATM_spr.ini");      //   "D://ATM_IN/ATM_spr.ini"



	//  дальше таблица выгрузки WINCOR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_WIN_V[4][4] = { { "0", "0", "0", "0" }, { "0", "0", "0", "0" },
                             	{ "0", "0", "0", "0" }, { "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  дальше таблица загрузки WINCOR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_WIN_Z[4][4] = { { "0", "0", "0", "0" }, { "0", "0", "0", "0" },
	                            { "0", "0", "0", "0" }, { "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  дальше таблица TEMP  WINCOR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_WIN_T[4][2] = { { "0", "0" }, { "0", "0" },
	                            { "0", "0" }, { "0", "0" } };
	
    /////////////////////////////////////////////////////////////////////////////////////
	//  дальше таблица выгрузки NCR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_NCR_V[4][6] = { { "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" },
	                            { "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  дальше таблица загрузки NCR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_NCR_Z[4][6] = { { "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" },
                            	{ "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  дальше таблица TEMP NCR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_NCR_T[4][2] = { { "0", "0" }, { "0", "0" },
	                            { "0", "0" }, { "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////	
	S_WORLD = "AUDIT";
	
	if (RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block))
	{
		//cout << "  Метод LOGIC::READ_LOGIC." << endl;
		cout << "  В файле журнала нет адита !" << endl;
		cout << "  " << FUL_PATH<< endl;
	
	    throw LOGIC_RANGE();
	
	}
	
	/////////////////////////////////////////////////////////////////////////////////////	
	// прочесть след строку   time  date
	S_WORLD = NULL;
	RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
	TEMP_str = S_WORLD;

	PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);

	BAN_STR.DATE= D_ENDED_Q.front();       // вывод   date
	D_ENDED_Q.pop_front();
	BAN_STR.TIME = D_ENDED_Q.front();      // вывод  time 
	D_ENDED_Q.pop_front();

	/////////////////////////////////////////////////////////////////////////////////////	
	S_WORLD = "ATM";
	RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
	
	BAN_STR.ATM = D_ENDED_Q.front();       // вывод   ATM
	TEMP_str = D_ENDED_Q.front();

    /////////////////////////////////////////////////////////////////////////////////////	
	STRING_TO_CHAR(TEMP_str, TEMP_line);
	S_WORLD = TEMP_line;
	D_ENDED_Q.clear();    // очистить очередь
	RIniF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);      //TEMP_line       S_WORLD


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (D_ENDED_Q.front()=="Wincor")  // WINCOR     конфигурация в массив
	{
		D_ENDED_Q.pop_front();

		size_t i;
		i = 0;
		while (!D_ENDED_Q.empty())
		{

			TABL_WIN_V[i][0] = D_ENDED_Q.front();
			TABL_WIN_Z[i][0] = D_ENDED_Q.front();
			TABL_WIN_T[i][0] = D_ENDED_Q.front();
			D_ENDED_Q.pop_front();
			++i;
		}
		//занёс в матрицу
		
		                                           //<-----------------  создать объект в зависимости от колличества купюр
		
// прочитать строку
		S_WORLD = NULL;
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		BAN_STR.ADRES_ASCII = S_WORLD;              // вывод   ADRES
//разбить на лексемы
		PARSING_STRING(S_WORLD,"", " ", D_ENDED_Q, POZ );

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//найти  CARD: 911299******7318
		// прочитать строку
		S_WORLD = "CARD:";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);

		TEMP_str = D_ENDED_Q.front();
		STRING_TO_CHAR(TEMP_str, TEMP_line);
		S_WORLD = TEMP_line;

		RIniF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);      //       S_WORLD
		//cout << "           ";
		
		while (!D_ENDED_Q.empty())                                // вывод фамилии по CARD:
		{
			BAN_STR.FAMALY_ASCII += D_ENDED_Q.front();
			D_ENDED_Q.pop_front();
		}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// прочитать строку из файла
		S_WORLD = "RETAINED CARDS:";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		cout << "  " << FUL_PATH << endl;
		cout  << "  RETAINED CARDS: " << D_ENDED_Q.front() << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// прочитать строку из файла
		S_WORLD = NULL;                              //"DISPENSED:"   переходит в конец файла         <-------------косяк в 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);                                            //READ_FILE_FUNCTION
/////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////
		do                                                       // пока не END AUDIT
		{
			// прочитать строку из файла                         // получена строку  "C 50.00 BYN 933 809"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "END AUDIT", " ", D_ENDED_Q, POZ))
			{
				break;                                           // выход если    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // строка разобрана на лексемы  "C" "50.00" "BYN" "933" "809"

	
			const size_t MAX = 10;
			char A[MAX];
			char B[MAX];


			i = 0;      // хождение по массиву
			while (!D_ENDED_Q.empty())                          // выкинуть  "933"        // закинуть  "809"
			{
				STRING_TO_CHAR(TABL_WIN_V[i][0], A);
				STRING_TO_CHAR(D_ENDED_Q.front(), B);
				if ((strcmp("a", B) == 0) ? true : false)
					STRING_TO_CHAR("A", B);
				if ((strcmp("b", B) == 0) ? true : false)
					STRING_TO_CHAR("B", B);
				if ((strcmp("c", B) == 0) ? true : false)
					STRING_TO_CHAR("C", B);
				if ((strcmp("d", B) == 0) ? true : false)
					STRING_TO_CHAR("D", B);
				if ((strcmp("e", B) == 0) ? true : false)
					STRING_TO_CHAR("E", B);

				if ((strcmp(A, B) == 0) ? true : false)
				{
					D_ENDED_Q.pop_front();
					D_ENDED_Q.pop_front();
					D_ENDED_Q.pop_front();
					D_ENDED_Q.pop_front();

					TABL_WIN_V[i][1] = D_ENDED_Q.front();
					TABL_WIN_V[i][0] = "X";
					D_ENDED_Q.pop_front();
					break;
					//++i;


				}
				++i;
				//continue;

				
				if ((strcmp("@", B) == 0) ? true : false)
				{
					D_ENDED_Q.pop_front();
				}

			}
		

		STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "END AUDIT", " ", D_ENDED_Q, POZ));  // <---------------- TRUE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for (size_t i = 0; i < 4; i++)
		{
			TABL_WIN_V[i][0] = TABL_WIN_T[i][0];
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////
		

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//найти ID BILLS REMAIN
			// прочитать строку из файла
			S_WORLD = "ID BILLS";          //"ID BILLS REMAIN"   переходит в конец файла         <-------------косяк в 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		do                                                       // пока не DIV
		{
			// прочитать строку из файла                         // получена строку  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "DIV", " ", D_ENDED_Q, POZ))
			{
				break;                                           // выход если    END AUDIT
			}
/////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////
			// если в фыгрузке пустая строка                     <---------------------------------
			if (false)
			{
				S_WORLD = NULL;
				RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
				PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);
				break;

				if ((strcmp("@", B) == 0) ? true : false)
				{
					D_ENDED_Q.pop_front();
					break;
				}




			}


///////////////////////////////////////////////////////////////////////////////////////
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // строка разобрана на лексемы  "C" "00809" "00090"
			
			const size_t MAX = 10;
			char A[MAX];
			char B[MAX];

			i = 0;      // хождение по массиву
			while (!D_ENDED_Q.empty())                          // выкинуть  "933"        // закинуть  "809"
			{
				STRING_TO_CHAR(TABL_WIN_V[i][0], A);
				STRING_TO_CHAR(D_ENDED_Q.front(), B);
				if ((strcmp("a", B) == 0) ? true : false)
					STRING_TO_CHAR("A", B);
				if ((strcmp("b", B) == 0) ? true : false)
					STRING_TO_CHAR("B", B);
				if ((strcmp("c", B) == 0) ? true : false)
					STRING_TO_CHAR("C", B);
				if ((strcmp("d", B) == 0) ? true : false)
					STRING_TO_CHAR("D", B);
				if ((strcmp("e", B) == 0) ? true : false)
					STRING_TO_CHAR("E", B);
		

				if ((strcmp(A, B) == 0) ? true : false)
				{
					D_ENDED_Q.pop_front();
				//	D_ENDED_Q.pop_front();
				//	D_ENDED_Q.pop_front();
				//	D_ENDED_Q.pop_front();

					size_t RAZ = D_ENDED_Q.size();
					++RAZ;
					for (size_t j = 1; j < RAZ; j++)
					{
						TABL_WIN_V[i][j] = D_ENDED_Q.front();
						TABL_WIN_V[i][0] = "X";
						D_ENDED_Q.pop_front();

					}

					++i;
					break;
					
				}
				++i;

				if ((strcmp("@", B) == 0) ? true : false)
				{
					D_ENDED_Q.pop_front();
					break;
				}

			}


			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "DIV", " ", D_ENDED_Q, POZ));  // <---------------- TRUE
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		for (size_t i = 0; i < 4; i++)
		{
			TABL_WIN_V[i][0] = TABL_WIN_T[i][0];
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// разбить строку 
		STRING_TO_CHAR(TEMP_str, S_WORLD);
		PARSING_STRING(S_WORLD, "DIV", " ", D_ENDED_Q, POZ);
		D_ENDED_Q.pop_front();
		cout  << "  REJECTS: " << D_ENDED_Q.front()<<endl;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////		

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//найти CASH COUNTERS AFTER
		// прочитать строку из файла
		S_WORLD = "CASH COUNTERS AFTER";          //"ID BILLS REMAIN"   переходит в конец файла         <-------------косяк в 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		//найти CASH COUNTERS AFTER
		// прочитать строку из файла
		S_WORLD = "   BYN";          //"ID BILLS REMAIN"   переходит в конец файла         <-------------косяк в 
		
		
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);                            //    "20"   "1499"	

		//          пока не --------->    RETRACTS: 

		while ("RETRACTS:"!=D_ENDED_Q.front())
		{

			i = 0;      // хождение по массиву
			while ("RETRACTS:" != D_ENDED_Q.front())                          // выкинуть  "933"        // закинуть  "809"
			{
				STRING_TO_CHAR(TABL_WIN_Z[i][0], A);
				STRING_TO_CHAR(D_ENDED_Q.front(), B);

				if ((strcmp("100", B) == 0) ? true : false)
					STRING_TO_CHAR("A", B);

				if ((strcmp("20", B) == 0) ? true : false)
					STRING_TO_CHAR("B", B);

				if ((strcmp("50", B) == 0) ? true : false)
					STRING_TO_CHAR("C", B);

				if ((strcmp("10", B) == 0) ? true : false)
					STRING_TO_CHAR("D", B);

				if ((strcmp("5", B) == 0) ? true : false)
					STRING_TO_CHAR("E", B);



				if ((strcmp("100000", B) == 0) ? true : false)
				{
				//	STRING_TO_CHAR("H", B);
					S_WORLD = NULL;
					RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
					PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);
					break;
				}



			
////////////////////////////////////////////////////////////
				// если в загрузке пустая строка
				if (D_ENDED_Q.size()< 2 )
				{
					S_WORLD = NULL;
					RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
					PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);
					break;
				}
////////////////////////////////////////////////////////////////
				// ghjdthbnm проверить 08-04-2017

				if ((strcmp(A, "X") == 0) ? true : false)
				{
					++i;

				}
////////////////////////////////////////////////////////////////

				if ((strcmp(A, B) == 0) ? true : false)
				{
					D_ENDED_Q.pop_front();
					//  D_ENDED_Q.pop_front();

					TABL_WIN_Z[i][2] = D_ENDED_Q.front();
					TABL_WIN_Z[i][0] = "X";
					S_WORLD = NULL;
					RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
					PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);
					if ("RETRACTS:" == D_ENDED_Q.front())
					{
						break;
					}

					D_ENDED_Q.pop_front();
					break;
					++i;
				}

				
				//вроде как обошлось  11841
				//if (true)  // 100  если ни нашёл такой купюры в таблице банкомата
				//{
				//	S_WORLD = NULL;
				//	RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
				//	PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);
				//	if ("RETRACTS:" == D_ENDED_Q.front())
				//	{
				//		break;
				//	}
				//
				//}




			}

		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// замена A B C D E WINCOR

		for (size_t i = 0; i < 4; i++)
		{
			STRING_TO_CHAR(TABL_WIN_T[i][0], A);

			if ((strcmp("A", A) == 0) ? true : false)
				STRING_TO_CHAR("100", A);
			if ((strcmp("B", A) == 0) ? true : false)
				STRING_TO_CHAR("20", A);
			if ((strcmp("C", A) == 0) ? true : false)
				STRING_TO_CHAR("50", A);
			if ((strcmp("D", A) == 0) ? true : false)
				STRING_TO_CHAR("10", A);
			if ((strcmp("E", A) == 0) ? true : false)
				STRING_TO_CHAR("5", A);


			//if ((strcmp("H", A) == 0) ? true : false)
			//	STRING_TO_CHAR("0", A);
			//else STRING_TO_CHAR("0", B);

			TABL_WIN_V[i][0] = A;
			TABL_WIN_Z[i][0] = A;
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Заполнение таблицы для WINCOR
		for (size_t i = 0; i < 4; i++)
		{
			for (size_t j = 0; j < 4; j++)
			{
				BAN_STR.count_str_VYG[i][j] = TABL_WIN_V[i][j];
				BAN_STR.count_str_ZAG[i][j] = TABL_WIN_Z[i][j];
			}
		}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		} ///////////////////// END WINCOR  //////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////	
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////////
		////  дальше таблица выгрузки NCR
		///////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////
	if (D_ENDED_Q.front() == "NCR")  // NCR     конфигурация в массив
	{

		D_ENDED_Q.pop_front();

		size_t i;
		i = 0;
		while (!D_ENDED_Q.empty())
		{

			TABL_NCR_V[i][0] = D_ENDED_Q.front();
			TABL_NCR_Z[i][0] = D_ENDED_Q.front();
			TABL_NCR_T[i][0] = D_ENDED_Q.front();
			D_ENDED_Q.pop_front();
			++i;
		}
		//занёс в матрицу



		//  создать объект в зависимости от колличества купюр

		//// прочитать строку
		//S_WORLD = NULL; 		//D_ENDED_Q.clear();    // очистить очередь
		//RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		//PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);//разбить на лексемы


		// прочитать строку
		S_WORLD = NULL;
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		BAN_STR.ADRES_ASCII = S_WORLD;              // вывод   ADRES
		PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);//разбить на лексемы

		/////////////////////////////////////////////////////////////////////////////////////////////////////////








		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//найти  CARD: 911299******7318
		// прочитать строку
		S_WORLD = "CARD:";
		//D_ENDED_Q.clear();    // очистить очередь
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);

		TEMP_str = D_ENDED_Q.front();
		STRING_TO_CHAR(TEMP_str, TEMP_line);
		S_WORLD = TEMP_line;

		//D_ENDED_Q.clear();    // очистить очередь
		RIniF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);      //       S_WORLD
		//cout << "           ";
		//TEMP_str.clear();
		while (!D_ENDED_Q.empty())                                // вывод фамилии по CARD:
		{
			BAN_STR.FAMALY_ASCII += D_ENDED_Q.front();
			D_ENDED_Q.pop_front();
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// прочитать строку из файла
		S_WORLD = "RETAINED CARDS:";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		cout << "  " << FUL_PATH << endl;
		cout << "  RETAINED CARDS: " << D_ENDED_Q.front() << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// прочитать строку из файла
		S_WORLD = NULL;                              //"DISPENSED:"   переходит в конец файла         <-------------косяк в 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);                                            //READ_FILE_FUNCTION
		/////////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		do                                                       // пока не END AUDIT
		{
			// прочитать строку из файла                         // получена строку  "C 50.00 BYN 933 809"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "END AUDIT", " ", D_ENDED_Q, POZ))
			{
				break;                                           // выход если    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // строка разобрана на лексемы  "C" "50.00" "BYN" "933" "809"

			i = 0;      // хождение по массиву
			while (!D_ENDED_Q.empty())                          // выкинуть  "933"        // закинуть  "809"
			{
				D_ENDED_Q.pop_front();
				D_ENDED_Q.pop_front();
				D_ENDED_Q.pop_front();
				D_ENDED_Q.pop_front();

				TABL_NCR_V[i][4] = D_ENDED_Q.front();
				D_ENDED_Q.pop_front();
				break;

				++i;

			}


			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "END AUDIT", " ", D_ENDED_Q, POZ));  // <---------------- TRUE
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// прочитать строку из файла
		S_WORLD = "TYPE 1";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// первая часть таблицы выгрузки NCR
		size_t j = 1;
		do                                                       // пока не DIV
		{
			// прочитать строку из файла                         // получена строку  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ))
			{
				break;                                           // выход если    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // строка разобрана на лексемы  "C" "00809" "00090"

			i = 0;      // хождение по массиву  первые две строчки
			D_ENDED_Q.pop_front();

			while (!D_ENDED_Q.empty())                          // выкинуть  "933"        // закинуть  "809"
			{
				TABL_NCR_V[i][j] = D_ENDED_Q.front();
				D_ENDED_Q.pop_front();
				++i;
			}

			++j;
			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ));  // <---------------- TRUE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// вторая часть таблицы выгрузки NCR

		j = 1;
		do                                                       // пока не DIV
		{
			// прочитать строку из файла                         // получена строку  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "LAST", " ", D_ENDED_Q, POZ))
			{
				break;                                           // выход если    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // строка разобрана на лексемы  "C" "00809" "00090"

			i = 2; // хождение по массиву    вторые две строчки
			D_ENDED_Q.pop_front();
			while (!D_ENDED_Q.empty())                          // выкинуть  "933"        // закинуть  "809"
			{
				TABL_NCR_V[i][j] = D_ENDED_Q.front();
				D_ENDED_Q.pop_front();
				++i;
			}

			++j;
			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "LAST", " ", D_ENDED_Q, POZ));  // <---------------- TRUE

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//  дальше таблица загрузки NCR
// последовательно найти строки
	//	"CASSETTE INSERTED"
	//		"DATE-TIME"
	//		"TYPE 1"
			// прочитать строку из файла
		S_WORLD = "CASSETTE INSERTED";
		 RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);





		//if (!RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block))
		//{
		//	//cout << "  Метод LOGIC::READ_LOGIC." << endl;
		//	cout << "  В файле журнала нет загрузки !" << endl;
		//	cout << "  " << FUL_PATH << endl;

		//	throw LOGIC_RANGE_TU();

		//}



		//try
		//{



		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// прочитать строку из файла
		S_WORLD = "DATE-TIME";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// прочитать строку из файла
		S_WORLD = "TYPE 1";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// первая часть таблицы загрузки NCR
		//пока не   TYPE 3
		//size_t j = 1;
		j = 1;
		do                                                       // пока не DIV
		{
			// прочитать строку из файла                         // получена строку  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ))
			{
				break;                                           // выход если    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // строка разобрана на лексемы  "C" "00809" "00090"

			i = 0;      // хождение по массиву  первые две строчки
			D_ENDED_Q.pop_front();

			while (!D_ENDED_Q.empty())                          // выкинуть  "933"        // закинуть  "809"
			{
				TABL_NCR_Z[i][j] = D_ENDED_Q.front();
				D_ENDED_Q.pop_front();
				++i;
			}

			++j;
			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ));  // <---------------- TRUE
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// вторая часть таблицы загрузки NCR

		j = 1;
		do                                                       // пока не DIV
		{
			// прочитать строку из файла                         // получена строку  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "LAST", " ", D_ENDED_Q, POZ))
			{
				break;                                           // выход если    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // строка разобрана на лексемы  "C" "00809" "00090"

			i = 2; // хождение по массиву    вторые две строчки
			D_ENDED_Q.pop_front();
			while (!D_ENDED_Q.empty())                          // выкинуть  "933"        // закинуть  "809"
			{
				TABL_NCR_Z[i][j] = D_ENDED_Q.front();
				D_ENDED_Q.pop_front();
				++i;
			}

			++j;
			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "LAST", " ", D_ENDED_Q, POZ));  // <---------------- TRUE

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// замена A B C D E NCR
	/*	}
		catch (LOGIC::LOGIC_RANGE_TU)
		{

		}*/


		for (size_t i = 0; i < 4; i++)
		{
			STRING_TO_CHAR(TABL_NCR_T[i][0], A);

			if ((strcmp("A", A) == 0) ? true : false)
				STRING_TO_CHAR("20", A);
			if ((strcmp("B", A) == 0) ? true : false)
				STRING_TO_CHAR("10", A);
			if ((strcmp("C", A) == 0) ? true : false)
				STRING_TO_CHAR("5", A);
			if ((strcmp("D", A) == 0) ? true : false)
				STRING_TO_CHAR("50", A);
			if ((strcmp("E", A) == 0) ? true : false)
				STRING_TO_CHAR("100", A);

			TABL_NCR_V[i][0] = A;
			TABL_NCR_Z[i][0] = A;
		}
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// замена A B C D E  после END WINCOR




	



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// Заполнение таблицы для WINCOR
		for (size_t i = 0; i < 4; i++)
		{
			//for (size_t j = 0; j < 4; j++)
			//{
			BAN_STR.count_str_VYG[i][0] = TABL_NCR_V[i][0];
			BAN_STR.count_str_ZAG[i][0] = TABL_NCR_Z[i][0];
			//}
		}
		for (size_t i = 0; i < 4; i++)
		{
			//for (size_t j = 0; j < 4; j++)
			//{
			BAN_STR.count_str_VYG[i][1] = TABL_NCR_V[i][4];
			BAN_STR.count_str_ZAG[i][1] = TABL_NCR_Z[i][4];
			//}
		}
		for (size_t i = 0; i < 4; i++)
		{
			//for (size_t j = 0; j < 4; j++)
			//{
			BAN_STR.count_str_VYG[i][2] = TABL_NCR_V[i][1];
			BAN_STR.count_str_ZAG[i][2] = TABL_NCR_Z[i][1];
			//}
		}
		for (size_t i = 0; i < 4; i++)
		{
			//for (size_t j = 0; j < 4; j++)
			//{
			BAN_STR.count_str_VYG[i][3] = TABL_NCR_V[i][2];
			BAN_STR.count_str_ZAG[i][3] = TABL_NCR_Z[i][2];
			//}
		}


	

		}///////////////////// END NCR  ////////////////////////////////////////






		
//создать и перенести всё в объект BANKOMAT
		return BAN_STR;

}////////////////////////////////////END LOGIC//////////////////////////////////////////////////////////



