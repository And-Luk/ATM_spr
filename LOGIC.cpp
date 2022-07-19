#include "stdafx.h"

#include "LOGIC.h"


///////////////////////////////////////////////////////////////////////////////////////////
//     LOGIC()
LOGIC::LOGIC()       
{
	//cout << "  ����������� LOGIC  = " << this << endl; 
}

///////////////////////////////////////////////////////////////////////////////////////////
LOGIC::~LOGIC()
{
	//cout  << "  ����������  LOGIC = " << this << endl;  
}

///////////////////////////////////////////////////////////////////////////////////////////
//     BANKOMAT_STRUCT READ_LOGIC();              
BANKOMAT_STRUCT LOGIC::READ_LOGIC(string FUL_PATH )   
{
	BANKOMAT_STRUCT BAN_STR;


	const int MAX = 100;             // static const int MAX = 200;
	char TEMP_line[MAX];             // ���� � ���� �������
	char* block = " ";
	char* S_WORLD;                  // ������� ����� 
	deque<string> D_ENDED_Q(0);      // ������������ ������� �� ������ �� ������ ������ READ_FILE
	string TEMP_str;
	size_t POZ;                      // PARSING_STRING
	const size_t MIN = 20;
	char A[MIN];
	char B[MIN];
	//string Input, Output;

	//string FILE_NAME;              // ("D:\\ATM_IN\\*.jrn")
	





	READ_FILE RJrnF(FUL_PATH);          // ("D://ATM_IN/*.jrn");
	READ_FILE RIniF("ATM_spr.ini");      //   "D://ATM_IN/ATM_spr.ini"



	//  ������ ������� �������� WINCOR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_WIN_V[4][4] = { { "0", "0", "0", "0" }, { "0", "0", "0", "0" },
                             	{ "0", "0", "0", "0" }, { "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  ������ ������� �������� WINCOR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_WIN_Z[4][4] = { { "0", "0", "0", "0" }, { "0", "0", "0", "0" },
	                            { "0", "0", "0", "0" }, { "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  ������ ������� TEMP  WINCOR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_WIN_T[4][2] = { { "0", "0" }, { "0", "0" },
	                            { "0", "0" }, { "0", "0" } };
	
    /////////////////////////////////////////////////////////////////////////////////////
	//  ������ ������� �������� NCR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_NCR_V[4][6] = { { "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" },
	                            { "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  ������ ������� �������� NCR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_NCR_Z[4][6] = { { "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" },
                            	{ "0", "0", "0", "0", "0", "0" }, { "0", "0", "0", "0", "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////
	//  ������ ������� TEMP NCR
	/////////////////////////////////////////////////////////////////////////////////////
	string TABL_NCR_T[4][2] = { { "0", "0" }, { "0", "0" },
	                            { "0", "0" }, { "0", "0" } };
	/////////////////////////////////////////////////////////////////////////////////////

    /////////////////////////////////////////////////////////////////////////////////////	
	S_WORLD = "AUDIT";
	
	if (RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block))
	{
		//cout << "  ����� LOGIC::READ_LOGIC." << endl;
		cout << "  � ����� ������� ��� ����� !" << endl;
		cout << "  " << FUL_PATH<< endl;
	
	    throw LOGIC_RANGE();
	
	}
	
	/////////////////////////////////////////////////////////////////////////////////////	
	// �������� ���� ������   time  date
	S_WORLD = NULL;
	RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
	TEMP_str = S_WORLD;

	PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);

	BAN_STR.DATE= D_ENDED_Q.front();       // �����   date
	D_ENDED_Q.pop_front();
	BAN_STR.TIME = D_ENDED_Q.front();      // �����  time 
	D_ENDED_Q.pop_front();

	/////////////////////////////////////////////////////////////////////////////////////	
	S_WORLD = "ATM";
	RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
	
	BAN_STR.ATM = D_ENDED_Q.front();       // �����   ATM
	TEMP_str = D_ENDED_Q.front();

    /////////////////////////////////////////////////////////////////////////////////////	
	STRING_TO_CHAR(TEMP_str, TEMP_line);
	S_WORLD = TEMP_line;
	D_ENDED_Q.clear();    // �������� �������
	RIniF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);      //TEMP_line       S_WORLD


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
	if (D_ENDED_Q.front()=="Wincor")  // WINCOR     ������������ � ������
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
		//���� � �������
		
		                                           //<-----------------  ������� ������ � ����������� �� ����������� �����
		
// ��������� ������
		S_WORLD = NULL;
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		BAN_STR.ADRES_ASCII = S_WORLD;              // �����   ADRES
//������� �� �������
		PARSING_STRING(S_WORLD,"", " ", D_ENDED_Q, POZ );

/////////////////////////////////////////////////////////////////////////////////////////////////////////
//�����  CARD: 911299******7318
		// ��������� ������
		S_WORLD = "CARD:";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);

		TEMP_str = D_ENDED_Q.front();
		STRING_TO_CHAR(TEMP_str, TEMP_line);
		S_WORLD = TEMP_line;

		RIniF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);      //       S_WORLD
		//cout << "           ";
		
		while (!D_ENDED_Q.empty())                                // ����� ������� �� CARD:
		{
			BAN_STR.FAMALY_ASCII += D_ENDED_Q.front();
			D_ENDED_Q.pop_front();
		}

/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ��������� ������ �� �����
		S_WORLD = "RETAINED CARDS:";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		cout << "  " << FUL_PATH << endl;
		cout  << "  RETAINED CARDS: " << D_ENDED_Q.front() << endl;
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ��������� ������ �� �����
		S_WORLD = NULL;                              //"DISPENSED:"   ��������� � ����� �����         <-------------����� � 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);                                            //READ_FILE_FUNCTION
/////////////////////////////////////////////////////////////////////////////////////////////////////////


////////////////////////////////////////////////////////////////////////////////////////////////////////////
		do                                                       // ���� �� END AUDIT
		{
			// ��������� ������ �� �����                         // �������� ������  "C 50.00 BYN 933 809"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "END AUDIT", " ", D_ENDED_Q, POZ))
			{
				break;                                           // ����� ����    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // ������ ��������� �� �������  "C" "50.00" "BYN" "933" "809"

	
			const size_t MAX = 10;
			char A[MAX];
			char B[MAX];


			i = 0;      // �������� �� �������
			while (!D_ENDED_Q.empty())                          // ��������  "933"        // ��������  "809"
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
//����� ID BILLS REMAIN
			// ��������� ������ �� �����
			S_WORLD = "ID BILLS";          //"ID BILLS REMAIN"   ��������� � ����� �����         <-------------����� � 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
/////////////////////////////////////////////////////////////////////////////////////////////////////////
		
		do                                                       // ���� �� DIV
		{
			// ��������� ������ �� �����                         // �������� ������  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "DIV", " ", D_ENDED_Q, POZ))
			{
				break;                                           // ����� ����    END AUDIT
			}
/////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////
			// ���� � �������� ������ ������                     <---------------------------------
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
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // ������ ��������� �� �������  "C" "00809" "00090"
			
			const size_t MAX = 10;
			char A[MAX];
			char B[MAX];

			i = 0;      // �������� �� �������
			while (!D_ENDED_Q.empty())                          // ��������  "933"        // ��������  "809"
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
		// ������� ������ 
		STRING_TO_CHAR(TEMP_str, S_WORLD);
		PARSING_STRING(S_WORLD, "DIV", " ", D_ENDED_Q, POZ);
		D_ENDED_Q.pop_front();
		cout  << "  REJECTS: " << D_ENDED_Q.front()<<endl;
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////		

		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//����� CASH COUNTERS AFTER
		// ��������� ������ �� �����
		S_WORLD = "CASH COUNTERS AFTER";          //"ID BILLS REMAIN"   ��������� � ����� �����         <-------------����� � 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		//����� CASH COUNTERS AFTER
		// ��������� ������ �� �����
		S_WORLD = "   BYN";          //"ID BILLS REMAIN"   ��������� � ����� �����         <-------------����� � 
		
		
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);                            //    "20"   "1499"	

		//          ���� �� --------->    RETRACTS: 

		while ("RETRACTS:"!=D_ENDED_Q.front())
		{

			i = 0;      // �������� �� �������
			while ("RETRACTS:" != D_ENDED_Q.front())                          // ��������  "933"        // ��������  "809"
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
				// ���� � �������� ������ ������
				if (D_ENDED_Q.size()< 2 )
				{
					S_WORLD = NULL;
					RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
					PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);
					break;
				}
////////////////////////////////////////////////////////////////
				// ghjdthbnm ��������� 08-04-2017

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

				
				//����� ��� ��������  11841
				//if (true)  // 100  ���� �� ����� ����� ������ � ������� ���������
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
// ������ A B C D E WINCOR

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
// ���������� ������� ��� WINCOR
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
		////  ������ ������� �������� NCR
		///////////////////////////////////////////////////////////////////////////////////////
		///////////////////////////////////////////////////////////////////////////////////////
	if (D_ENDED_Q.front() == "NCR")  // NCR     ������������ � ������
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
		//���� � �������



		//  ������� ������ � ����������� �� ����������� �����

		//// ��������� ������
		//S_WORLD = NULL; 		//D_ENDED_Q.clear();    // �������� �������
		//RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		//PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);//������� �� �������


		// ��������� ������
		S_WORLD = NULL;
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		BAN_STR.ADRES_ASCII = S_WORLD;              // �����   ADRES
		PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);//������� �� �������

		/////////////////////////////////////////////////////////////////////////////////////////////////////////








		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		//�����  CARD: 911299******7318
		// ��������� ������
		S_WORLD = "CARD:";
		//D_ENDED_Q.clear();    // �������� �������
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);

		TEMP_str = D_ENDED_Q.front();
		STRING_TO_CHAR(TEMP_str, TEMP_line);
		S_WORLD = TEMP_line;

		//D_ENDED_Q.clear();    // �������� �������
		RIniF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);      //       S_WORLD
		//cout << "           ";
		//TEMP_str.clear();
		while (!D_ENDED_Q.empty())                                // ����� ������� �� CARD:
		{
			BAN_STR.FAMALY_ASCII += D_ENDED_Q.front();
			D_ENDED_Q.pop_front();
		}
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ��������� ������ �� �����
		S_WORLD = "RETAINED CARDS:";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		cout << "  " << FUL_PATH << endl;
		cout << "  RETAINED CARDS: " << D_ENDED_Q.front() << endl;
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ��������� ������ �� �����
		S_WORLD = NULL;                              //"DISPENSED:"   ��������� � ����� �����         <-------------����� � 
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);                                            //READ_FILE_FUNCTION
		/////////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		do                                                       // ���� �� END AUDIT
		{
			// ��������� ������ �� �����                         // �������� ������  "C 50.00 BYN 933 809"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "END AUDIT", " ", D_ENDED_Q, POZ))
			{
				break;                                           // ����� ����    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // ������ ��������� �� �������  "C" "50.00" "BYN" "933" "809"

			i = 0;      // �������� �� �������
			while (!D_ENDED_Q.empty())                          // ��������  "933"        // ��������  "809"
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
		// ��������� ������ �� �����
		S_WORLD = "TYPE 1";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////


//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������ ����� ������� �������� NCR
		size_t j = 1;
		do                                                       // ���� �� DIV
		{
			// ��������� ������ �� �����                         // �������� ������  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ))
			{
				break;                                           // ����� ����    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // ������ ��������� �� �������  "C" "00809" "00090"

			i = 0;      // �������� �� �������  ������ ��� �������
			D_ENDED_Q.pop_front();

			while (!D_ENDED_Q.empty())                          // ��������  "933"        // ��������  "809"
			{
				TABL_NCR_V[i][j] = D_ENDED_Q.front();
				D_ENDED_Q.pop_front();
				++i;
			}

			++j;
			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ));  // <---------------- TRUE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������ ����� ������� �������� NCR

		j = 1;
		do                                                       // ���� �� DIV
		{
			// ��������� ������ �� �����                         // �������� ������  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "LAST", " ", D_ENDED_Q, POZ))
			{
				break;                                           // ����� ����    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // ������ ��������� �� �������  "C" "00809" "00090"

			i = 2; // �������� �� �������    ������ ��� �������
			D_ENDED_Q.pop_front();
			while (!D_ENDED_Q.empty())                          // ��������  "933"        // ��������  "809"
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
//  ������ ������� �������� NCR
// ��������������� ����� ������
	//	"CASSETTE INSERTED"
	//		"DATE-TIME"
	//		"TYPE 1"
			// ��������� ������ �� �����
		S_WORLD = "CASSETTE INSERTED";
		 RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);





		//if (!RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block))
		//{
		//	//cout << "  ����� LOGIC::READ_LOGIC." << endl;
		//	cout << "  � ����� ������� ��� �������� !" << endl;
		//	cout << "  " << FUL_PATH << endl;

		//	throw LOGIC_RANGE_TU();

		//}



		//try
		//{



		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ��������� ������ �� �����
		S_WORLD = "DATE-TIME";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ��������� ������ �� �����
		S_WORLD = "TYPE 1";
		RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
		/////////////////////////////////////////////////////////////////////////////////////////////////////////


		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ������ ����� ������� �������� NCR
		//���� ��   TYPE 3
		//size_t j = 1;
		j = 1;
		do                                                       // ���� �� DIV
		{
			// ��������� ������ �� �����                         // �������� ������  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ))
			{
				break;                                           // ����� ����    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // ������ ��������� �� �������  "C" "00809" "00090"

			i = 0;      // �������� �� �������  ������ ��� �������
			D_ENDED_Q.pop_front();

			while (!D_ENDED_Q.empty())                          // ��������  "933"        // ��������  "809"
			{
				TABL_NCR_Z[i][j] = D_ENDED_Q.front();
				D_ENDED_Q.pop_front();
				++i;
			}

			++j;
			STRING_TO_CHAR(TEMP_str, S_WORLD);
		} while (!PARSING_STRING(S_WORLD, "TYPE 3", " ", D_ENDED_Q, POZ));  // <---------------- TRUE
		//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ������ ����� ������� �������� NCR

		j = 1;
		do                                                       // ���� �� DIV
		{
			// ��������� ������ �� �����                         // �������� ������  " C 00809 00090"
			S_WORLD = NULL;
			RJrnF.READ_FILE_FUNCTION(D_ENDED_Q, S_WORLD, block);
			TEMP_str = S_WORLD;
			if (PARSING_STRING(S_WORLD, "LAST", " ", D_ENDED_Q, POZ))
			{
				break;                                           // ����� ����    END AUDIT
			}
			STRING_TO_CHAR(TEMP_str, S_WORLD);
			PARSING_STRING(S_WORLD, "", " ", D_ENDED_Q, POZ);    // ������ ��������� �� �������  "C" "00809" "00090"

			i = 2; // �������� �� �������    ������ ��� �������
			D_ENDED_Q.pop_front();
			while (!D_ENDED_Q.empty())                          // ��������  "933"        // ��������  "809"
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
// ������ A B C D E NCR
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
		// ������ A B C D E  ����� END WINCOR




	



		//////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ���������� ������� ��� WINCOR
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






		
//������� � ��������� �� � ������ BANKOMAT
		return BAN_STR;

}////////////////////////////////////END LOGIC//////////////////////////////////////////////////////////



