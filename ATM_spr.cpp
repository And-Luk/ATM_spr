// ATM_spr.cpp: определяет точку входа для консольного приложения.
#include "stdafx.h"



#include "Header.h"
#include "LOGIC.h"
#include "READ_RTF.h"
#include "READ_FILE.h"
#include "ARG_COMAND.h"
#include "DOUBLE_ARRAY.h"
#include "MODEL_BANKOMAT.h"
#include "GLOBAL_FUNCTION.h"
#include "OUT_RTF_PATH_NAME.h"


string* TEMP_ARR;  // временный ARRAY

int _tmain(int argc, _TCHAR* argv[])   
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Russian");
	//setlocale(LC_CTYPE, "RUS");

	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создание объекта ARGUMENTS comand string
	ARG_COMAND ARG_COMD(argc, argv);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Прочитать каталог с файлами создать массив файлов с путём к ним
	ARG_COMD.READ_DIRECTORY();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// если нет файлов выйти   в MPTY_DOB_ARR(TRUE или FALSE)  TRUE  нафиг нужно
   if (!ARG_COMD.EMPTY_DOB_ARR(FALSE))
	{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создание объекта LOGIC
   LOGIC RFlog;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создание объекта банкомат    static                                     
   MODEL_BANKOMAT   BANKOMAT;  // ATM_spr

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// создание объекта DOUBLE_ARRAY
   DOUBLE_ARRAY DOUB_AR;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// создание OUT_RTF_PATH_NAME
//	string* TEMP_ARR;  // временный ARRAY
   OUT_RTF_PATH_NAME OUT_RTF_P_N;     //12752_2017.04.06_UN.rtf    // 12752_2017.04.06_LOAD.rtf

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Создание объекта READ_RTF RD_RTF("D://ATM_IN/Report.RTF");
   READ_RTF RD_RTF;




   while (!ARG_COMD.EMPTY_DOB_ARR(FALSE))
   {
	   //try
	   //{
	   
	   do
	   {
 

	   try
	   {
		   cout << endl;
///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Прочесть лог файл и через структуру передать в модель ванкомата  с удалением из списка файла
// ARG_COMD.READ_DIRECTORY(BANKOMAT)  		
	   BANKOMAT.PUSH_STRUCT_BANKOMAT(RFlog.READ_LOGIC(ARG_COMD.OUT_DOB_ARR(TRUE)));
	   }
	   catch (LOGIC::LOGIC_RANGE)  //  const std::exception& Range   // LOGIC::Range
	   {
		  // cout << "  Обработка исключения LOGIC::LOGIC_RANGE. В лог-файле что-то не найдено !" << endl;
		   cout << "  В лог-файле что-то не найдено !" << endl;
		  // ARG_COMD.EMPTY_DOB_ARR(TRUE);

		   if (ARG_COMD.EMPTY_DOB_ARR(FALSE))
		   {
			   cout << "  Выход из исключения LOGIC::LOGIC_RANGE." << endl;
			   cout << endl << "          END" << endl;
			   system("pause");
			   exit(0);
		   }
		   continue;
	   }
	   catch (READ_FILE::Range)  //  const std::exception& Range   // LOGIC::Range
	   {
		  // cout << "  Обработка исключения READ_FILE::READ_FILE_FUNCTION. В лог-файле чего-то не хватает !" << endl;
		   cout << "  В лог-файле чего-то не хватает !" << endl;
		   if (ARG_COMD.EMPTY_DOB_ARR(FALSE))
		   {
			   cout << "  Выход из исключения READ_FILE::READ_FILE_FUNCTION." << endl;

			   cout << endl << "          END" << endl;
			   system("pause");
			   exit(0);
		   }
		   continue;



	   }


	   break;

	   } while (true);





	   //}
	   //catch (LOGIC::LOGIC_RANGE_TU)
	   //{

	   //}
	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   // Изменения сруктуры MODEL_BANKOMAT
	   BANKOMAT.TRANS_STRUCT_BANKOMAT();






	   TEMP_ARR = OUT_RTF_P_N.OUT_P_N(BANKOMAT, ARG_COMD);



	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   // Загнать значения замен в очередь массивов Выгрузка
	   BANKOMAT.PUSH_DOUBLE_ARRAY_STRUCTUR(DOUB_AR);

	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   // Пересформатировать и создать выходной файл D:\\ATM_OUT\\12752_2017.04.06_UN.rtf
	   RD_RTF.READ_FILE_RTF(DOUB_AR, "Report_UN.RTF", TEMP_ARR[0]);  //  ARG_COMD.READ_DIRECTORY(BANKOMAT)




///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Загнать значения замен в очередь массивов Загрузка
	   BANKOMAT.PUSH_DOUBLE_ARRAY_STRUCTUR_LOAD(DOUB_AR);
	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   // Пересформатировать и создать выходной файл D:\\ATM_OUT\\12752_2017.04.06_LOAD.rtf
	   RD_RTF.READ_FILE_RTF(DOUB_AR, "Report_LOAD.RTF", TEMP_ARR[1]);  //  ARG_COMD.READ_DIRECTORY(BANKOMAT)

	

	   
	   

	 

   }


   }
   cout << endl << "          END" << endl;
   system("pause");
	return 0;
}//////////////////////////// END //////////////////////////////////////////////////////////////////////////////