// ATM_spr.cpp: ���������� ����� ����� ��� ����������� ����������.
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


string* TEMP_ARR;  // ��������� ARRAY

int _tmain(int argc, _TCHAR* argv[])   
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "Russian");
	//setlocale(LC_CTYPE, "RUS");

	

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� ������� ARGUMENTS comand string
	ARG_COMAND ARG_COMD(argc, argv);

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������� ������� � ������� ������� ������ ������ � ���� � ���
	ARG_COMD.READ_DIRECTORY();

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���� ��� ������ �����   � MPTY_DOB_ARR(TRUE ��� FALSE)  TRUE  ����� �����
   if (!ARG_COMD.EMPTY_DOB_ARR(FALSE))
	{

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� ������� LOGIC
   LOGIC RFlog;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� ������� ��������    static                                     
   MODEL_BANKOMAT   BANKOMAT;  // ATM_spr

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� ������� DOUBLE_ARRAY
   DOUBLE_ARRAY DOUB_AR;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� OUT_RTF_PATH_NAME
//	string* TEMP_ARR;  // ��������� ARRAY
   OUT_RTF_PATH_NAME OUT_RTF_P_N;     //12752_2017.04.06_UN.rtf    // 12752_2017.04.06_LOAD.rtf

///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� ������� READ_RTF RD_RTF("D://ATM_IN/Report.RTF");
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
// �������� ��� ���� � ����� ��������� �������� � ������ ���������  � ��������� �� ������ �����
// ARG_COMD.READ_DIRECTORY(BANKOMAT)  		
	   BANKOMAT.PUSH_STRUCT_BANKOMAT(RFlog.READ_LOGIC(ARG_COMD.OUT_DOB_ARR(TRUE)));
	   }
	   catch (LOGIC::LOGIC_RANGE)  //  const std::exception& Range   // LOGIC::Range
	   {
		  // cout << "  ��������� ���������� LOGIC::LOGIC_RANGE. � ���-����� ���-�� �� ������� !" << endl;
		   cout << "  � ���-����� ���-�� �� ������� !" << endl;
		  // ARG_COMD.EMPTY_DOB_ARR(TRUE);

		   if (ARG_COMD.EMPTY_DOB_ARR(FALSE))
		   {
			   cout << "  ����� �� ���������� LOGIC::LOGIC_RANGE." << endl;
			   cout << endl << "          END" << endl;
			   system("pause");
			   exit(0);
		   }
		   continue;
	   }
	   catch (READ_FILE::Range)  //  const std::exception& Range   // LOGIC::Range
	   {
		  // cout << "  ��������� ���������� READ_FILE::READ_FILE_FUNCTION. � ���-����� ����-�� �� ������� !" << endl;
		   cout << "  � ���-����� ����-�� �� ������� !" << endl;
		   if (ARG_COMD.EMPTY_DOB_ARR(FALSE))
		   {
			   cout << "  ����� �� ���������� READ_FILE::READ_FILE_FUNCTION." << endl;

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
	   // ��������� �������� MODEL_BANKOMAT
	   BANKOMAT.TRANS_STRUCT_BANKOMAT();






	   TEMP_ARR = OUT_RTF_P_N.OUT_P_N(BANKOMAT, ARG_COMD);



	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   // ������� �������� ����� � ������� �������� ��������
	   BANKOMAT.PUSH_DOUBLE_ARRAY_STRUCTUR(DOUB_AR);

	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   // ������������������ � ������� �������� ���� D:\\ATM_OUT\\12752_2017.04.06_UN.rtf
	   RD_RTF.READ_FILE_RTF(DOUB_AR, "Report_UN.RTF", TEMP_ARR[0]);  //  ARG_COMD.READ_DIRECTORY(BANKOMAT)




///////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������� �������� ����� � ������� �������� ��������
	   BANKOMAT.PUSH_DOUBLE_ARRAY_STRUCTUR_LOAD(DOUB_AR);
	   ///////////////////////////////////////////////////////////////////////////////////////////////////////////////
	   // ������������������ � ������� �������� ���� D:\\ATM_OUT\\12752_2017.04.06_LOAD.rtf
	   RD_RTF.READ_FILE_RTF(DOUB_AR, "Report_LOAD.RTF", TEMP_ARR[1]);  //  ARG_COMD.READ_DIRECTORY(BANKOMAT)

	

	   
	   

	 

   }


   }
   cout << endl << "          END" << endl;
   system("pause");
	return 0;
}//////////////////////////// END //////////////////////////////////////////////////////////////////////////////