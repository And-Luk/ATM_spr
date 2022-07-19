
#include "stdafx.h"

#include "GLOBAL_FUNCTION.h"




//////////////////////////////////////////////////////////////////////////////////////////////////////////
// ����������� ������� �������������� string IN_STRING � ������ -> char* ARRY_STRING 
// ���������� ������ �������
	size_t STRING_TO_CHAR(string IN_STRING, char* OUT_ARRY)           //char* &ARRY_STRING
	{
		size_t i, size_out;
		i = size_out = IN_STRING.size();
		OUT_ARRY[i] = '\0';
		while (i > 0)           //
		{
			--i;
			OUT_ARRY[i] = IN_STRING.back();
			IN_STRING.pop_back();
		}
		return size_out;
	}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// ����������� ������� �������������� PARSING_STRING
// ����������� ������ IN_STRING, ������� ����� SEARCH_WORLD, ������ �������� ������� MISSING_CHAR
// ������� ������ ����� ������� ������������ ������� &DOBLE_ENDED_QUEUE
// ������� ������� � ������� ���������� ����� size_t &OUT_POSITION
// ������� �������� TRUE ���� ������� ����� ����� FALSE
	bool PARSING_STRING(char* IN_STRING, char* SEARCH_WORLD, char* MISSING_CHAR, deque<string> &DOBLE_ENDED_QUEUE, size_t &OUT_POSITION)

	{
		bool PARSING_STRING_RETURN = false;  // ������������ �������� bool ������� ��� ���������� SEARCH_WORLD
		DOBLE_ENDED_QUEUE.clear();           // �������� ������� ����� ��������������
		if (!MISSING_CHAR)                   // ����  MISSING_CHAR = NULL
		{
			MISSING_CHAR = " ";
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
		// ������ ������������� ������ � ���� ������� ������� �����   ������� ����� ������� TRUE
		char* ptr;
		//////////////<----------------------------------------------------
		ptr = search(IN_STRING, IN_STRING + strlen(IN_STRING), SEARCH_WORLD, SEARCH_WORLD + strlen(SEARCH_WORLD));
		if (ptr != IN_STRING + strlen(IN_STRING))
		{
			PARSING_STRING_RETURN = true;
			//return PARSING_STRING_RETURN;
		}
		///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		//////////////////////////////////////////////////////////////////////////////////////////////////////
		// ������ ��������� ������ �� �������  ��� �����
		// ���� �� ����� ������
		bool NO_MISSING_CHAR = true;            // ���������� ������ �� ���������� �� ������� MISSING_CHAR
		string read_world;                      //
		size_t a = 0;
		size_t TEMP_POSITION = 0;
		while ((IN_STRING[a] != '\0') && (IN_STRING[a] != '\n'))             // ���� �� ����� ������  ��� ������� �������
		{

			// ���������� ����������� �� ������� MISSING_CHAR ���� �� ������
			while (IN_STRING[a] != '\0' && IN_STRING[a] != '\n' && NO_MISSING_CHAR)
			{
				for (size_t i = 0; i < strlen(MISSING_CHAR); i++)
				{
					NO_MISSING_CHAR = false;
					if (IN_STRING[a] == MISSING_CHAR[i])
					{
						NO_MISSING_CHAR = true;
						++a;
						break;
					}
				}
			}

			//  ���� �� ����� ������ � �� "line[a] != '\n' && � �� ������                    IN_STRING[a] != ' '
			//  ���������� ��� ���� ���� ��������� �������� ����� ������������� �� ��������    
			//<<<<<<<<<<------------------------------------------------------------------>>>>>>>>>>>
			// ������ ����� �� ������� �� �������
			while (IN_STRING[a] != '\0' && IN_STRING[a] != '\n' && IN_STRING[a] != ' ')

			{
				read_world.push_back(IN_STRING[a]);
				++a;
			}

			/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			// ���� � "read_world" ���� ����� ����� - ��������� �� ������� ����������� ������� "DOBLE_ENDED_QUEUE"
			if (!read_world.empty())
			{
				DOBLE_ENDED_QUEUE.push_back(read_world);
				++TEMP_POSITION;
				//read_world.clear();
			}



			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//////////////////////////////////////<---------  �� ���� ��� ��� ����� -------------//...//////////////////////////////////
			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			//  ���� � ������ ���� ������� ����� � (read_world != NULL)   /////////////////  ������������   
			if (!read_world.empty() && read_world == SEARCH_WORLD) //&& !SEARCH_WORLD  && SEARCH_WORLD == NULL 
			{
				//PARSING_STRING_RETURN = true;
				OUT_POSITION = TEMP_POSITION - 1;
			}

			read_world.clear();
			NO_MISSING_CHAR = true;  // ���� ����� ����������          <-----------------------------

		}

		return PARSING_STRING_RETURN;

	}

//////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������� INT � STRING    // ��� itoa   #pragma warning(disable : 4996)  
string INT_TO_STRING(const unsigned int INT_TS)
{
	string TEMP_STRING;
	char TEMP_CHAR[10];
	itoa(INT_TS, TEMP_CHAR, 10);
	TEMP_STRING = TEMP_CHAR;
	return TEMP_STRING;
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� �����
// DeleteFile(FILE_NAME);   //("D:dir")
// remove("D://ATM_IN/Report.RTF");        // ��� �������� !!!
void DELETE_FILE(const string file_name)
{
	//char* S_WORLD ="";                  // ������� ����� 

	const int MAX = 100;             // static const int MAX = 200;
	char S_WORLD[MAX];             // ���� � ���� �������


	string FILE_NAME;              // ("D:\\ATM_IN\\*.jrn")
								   //file_name = FILE_NAME;
//	FILE_NAME=file_name;

	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf = FindFirstFile(_T("D:\\ATM_IN\\*.jrn"), &FindFileData);  //(_T("D:\\ATM_IN\\*")
	if (hf != INVALID_HANDLE_VALUE)
	{
		do
		{
			const wchar_t* str = (FindFileData.cFileName);
			char buf[32];
			size_t len = wcstombs(buf, str, wcslen(str));
			if (len > 0u)
				buf[len] = '\0';
			//puts(buf);


			FILE_NAME = "D://ATM_IN/";
			FILE_NAME += buf;
			break;

		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}





	STRING_TO_CHAR(FILE_NAME, S_WORLD);
	if (remove(S_WORLD))                  // FILE_NAME
	cout << "   Error removing file !    " << FILE_NAME << endl;


}


