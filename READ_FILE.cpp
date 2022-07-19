// ���� ������ ������ ����� ������� ����� �� ������  � ����� ���������� NULL
// ������� ������ �����  SEARCH_WORLD ���� �� ��� ���� ��� ������ ������
#include "stdafx.h"

#include "READ_FILE.h"


READ_FILE::READ_FILE()
{}



READ_FILE::READ_FILE(string FILE_NAME)
{
	file_name = FILE_NAME;
	in.open(FILE_NAME);                // open for read
 	//cout << "  ����������� READ_FILE " << FILE_NAME << " =  "<<this << endl;   // �������� �� ����������� ����� TEST.jrn
}

READ_FILE::~READ_FILE()
{
	in.close();
	//cout << "  ����������  READ_FILE = " << this->file_name << " = " << this << endl;
}

// ������� ������ �����  SEARCH_WORLD ���� �� ��� ���� ��� ������ ������ deque<string> & DOBLE_ENDED_QUEUE
//	char* SEARCH_WORLD = "=REMAINING";   // ����� ����� �� ������ �������� ����� ��������� iterator a;
//	char* MISSING_CHAR = " -:";          // ������������ ������� ����� ���������� �����
//  ifstream in(file_name);              // ("TEST.jrn")
bool READ_FILE::READ_FILE_FUNCTION(deque<string> &DOBLE_ENDED_QUEUE, char* &SEARCH_WORLD, char* MISSING_CHAR)
{



	DOBLE_ENDED_QUEUE.clear();


	if (!MISSING_CHAR)         // ����  MISSING_CHAR �� ��������
	{
		MISSING_CHAR = " ";
	}


	if (!in)
	{    
		//cout << "  ����� READ_FILE::READ_FILE_FUNCTION." << endl;
		cout << "  ��� ����� ��� ������ ! " << endl;

		cout << "  " << (this->file_name) << endl;

		throw Range();

	}







	size_t n_poz = 0;
	size_t n_SEARCH_WORLD = 0;



	bool PUST_STROKA = true;
	bool NO_MISSING_FILE = true;                      // �������� �� �������� ����  ���� ���������  NO_MISSING_FILE
	string IN_GET_CHAR;  // ������ ��� ��������� ������� �� �����

	while (PUST_STROKA && !in.eof())
	{




		IN_GET_CHAR.erase();


		///size_t www;                         //     <--------�������
		///www = IN_GET_CHAR.size();          ///     <--------�������  IN_GET_CHAR.size()= = 0
	
		do
		{



			////////////////////////////////////////////////////////////////////////////////////////////////////////////////////	
			//��������� � ����� NO_MISSING_FILE

			while (!in.eof() && in.good() && NO_MISSING_FILE && IN_GET_CHAR.empty())
			{
				char ch;                              // ������ ��� ����������


				//////////////////////////////////////////////////////////////////////////////////////////////////
				//  ��������� ������ ���������� �����������
				n_poz = 0;
				do
				{
					in.get(ch);
					if (ch == '\r' || ch == '\n')          // ��������  ������� ������� �� ����� ������
					{
						ch = '\0';
						break;
					}
					++n_poz;
					IN_GET_CHAR.push_back(ch);

					if ((MAX - 3) < IN_GET_CHAR.size())   //  n_poz>199 ���� ����� ���� ������������ ��������� ������ "����"
					{
						//ch = '\0';
						IN_GET_CHAR.push_back(ch);
						NO_MISSING_FILE = false;         // ��������� ��� ���� �� ������
						break;
					}
				} while (ch != '\r' && ch != '\0'&&ch != '\n');



			}

		
		} while (IN_GET_CHAR.empty());





		//  ��������� ������ �� string IN_GET_CHAR � ������ line
		/////////////////////////////////////////////////////////////////////////////////////////
		STRING_TO_CHAR(IN_GET_CHAR, line);

		/////////////////////////////////////////////////////////////////////////////////////////

		// ������� ������ �����  SEARCH_WORLD ���� �� ��� ���� ��� ������ ������
		if (SEARCH_WORLD==NULL)   // ���� ������ ������ ����� NULL ������� ����� �� ������   //SEARCH_WORLD==NULL
		{
			SEARCH_WORLD = line;
			return false;
		}


		// ������ ������������� ������ � ���� ������� ������� ����� ������ �� ��� ������ �������  ��� �����
		char* ptr;
		size_t a = 0;                 //////////////<----------------------------------------------------
		ptr = search(line, line + MAX, SEARCH_WORLD, SEARCH_WORLD + strlen(SEARCH_WORLD));
		if (ptr != line + MAX)
		{
			PUST_STROKA = true;
			read_world.erase();

			a = static_cast<size_t> (ptr - line + strlen(SEARCH_WORLD));   // ��������� �� ������ �� ��������� ������



			bool NO_MISSING_CHAR = true;                    // ���������� ������ �� ���������� �� ������� MISSING_CHAR
			////////////////////////////////////////////////// ���� �� ����� ������ �������� � ���������� � ���������
			while (line[a] != '\0')                         // ���� �� ����� ������
			{


				while (line[a] != '\0' && line[a] != '\n'&& NO_MISSING_CHAR)  // ���������� ����������� �� ������� MISSING_CHAR
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


				//  ���������� ��� ���� ���� ��������� �������� ����� ������������� �� �������� ..&& line[a] != ' '
				//<<<<<<<<<<------------------------------------------------------------------>>>>>>>>>>>
				// ���� �� ����� ������ � �� "line[a] != '\n' && � �� ������ �� ������ ��������� ������ "
				while (line[a] != '\0' && line[a] != ' ')  // ������ ����� �� ������� �� �������
				{
					read_world.push_back(line[a]);
					++a;
				}

// ���� � "read_world" ���� ����� - ��������� �� ������� ����������� ������� "DOBLE_ENDED_QUEUE" � ��� ���������
				if (!read_world.empty())
				{
					DOBLE_ENDED_QUEUE.push_back(read_world);
					read_world.clear();
					PUST_STROKA = false;
				}
				NO_MISSING_CHAR = true;  // ���� ����� ����������
			}

			

		}

	}
	

// ����  ����� ����� ��� �������� � �������  ��� �������� �� �������� ����	"return true"    �����    "return false;"
	if (in.eof() && DOBLE_ENDED_QUEUE.empty() )  //&& !in.good() && !NO_MISSING_FILE
	{
		//cout << "  ����� READ_FILE::READ_FILE_FUNCTION." << endl;
		cout << "  " << this->file_name << endl;
		cout << "  ���� ������� ��������, ������� �� ������� !" << endl;
		throw Range();
		return true;
	}
	else
	{
		return false;
	}


}
