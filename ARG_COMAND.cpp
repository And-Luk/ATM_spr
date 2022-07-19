#include"stdafx.h"


#include"ARG_COMAND.h"



ARG_COMAND::ARG_COMAND()
{
	//cout << "  ����������� ARG_COMAND �� ��������� = " << this << endl;
}

                
ARG_COMAND::ARG_COMAND(const int argc, _TCHAR* const *argv )
{
	//cout << "  ����������� ARG_COMAND � ����������� = " << this << endl;
	arg = argc;
	if (argc<3)
	{
		cout<< "  ��� ���� ���������� � ��������� ������" << this << endl;
		exit(-1);
	}
	Input = argv[1];
	Output = argv[2];
}


ARG_COMAND::~ARG_COMAND()
{
	//cout << "  ����������  ARG_COMAND = " << this << endl;

}


string ARG_COMAND::Input_Directory()
{
	return INPUT_S;
}


string ARG_COMAND::Output_Directory()
{
	return OUTPUT_S;
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ���������� ���� �� ������� ������� ��������� ������  (TRUE - ������� ���� �� ������� FALSE - ���)
// ������� �����
string ARG_COMAND::OUT_DOB_ARR(bool DEL_OR_NO)
{
	string TEMP;
	TEMP = DOB_ARR.front();
	if (DEL_OR_NO)
	{
		DOB_ARR.pop_front();
	}
	return TEMP;
}



///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������� ������� ������� �� ��������� ������
// ����            D:\\ATM_IN\\EJ012163.999
void ARG_COMAND::READ_DIRECTORY()      
{
	string TEMP;
	static const int MAX = 200;
	char TEMP_CH[MAX];                 // ���� � ���� �������
	string TEMP_PATH;

	////////////////////////////////////////////////////////////////////
	//string TEMP;
	wstring bob_o(Output);
	string bill_o(bob_o.begin(), bob_o.end());
	TEMP = bill_o;

	//	static const int MAX = 200;
	//	char TEMP_CH[MAX];                 // ���� � ���� �������


	STRING_TO_CHAR(TEMP, TEMP_CH);
	replace(TEMP.begin(), TEMP.end(), _T('\\'), _T('/'));


	//	string TEMP_PATH;
	TEMP_PATH = TEMP;
	OUTPUT_S = TEMP;
	////////////////////////////////////////////////////////////////////

	


	wstring bob(Input);
	string bill(bob.begin(), bob.end());
	TEMP = bill;




	STRING_TO_CHAR(TEMP, TEMP_CH);
	replace(TEMP.begin(), TEMP.end(), _T('\\'), _T('/'));
	
	

	TEMP_PATH = TEMP;
	INPUT_S = TEMP;
	/////////////////////////////////////////////////////////////////////













///////////////////////////////////////////////////////////////////////////////


	_tcscat(Input, _T("*"));    //   ��������� "D:\\ATM_IN\\"    TEXT("*")

	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf = FindFirstFile(Input, &FindFileData); 

	if (hf != INVALID_HANDLE_VALUE)
	{
		size_t len;
		char buf[60];
		string FUL_PATH;
		do
		{
			
			FUL_PATH.clear();

			const wchar_t* str = (FindFileData.cFileName);
			
			 len = wcstombs(buf, str, wcslen(str));
			if (len > 0u)
				buf[len] = '\0';

			TEMP = buf;
			

			if (TEMP != "desktop.ini" && TEMP != "." && TEMP != "..")
			{
				FUL_PATH = TEMP_PATH;
				FUL_PATH += TEMP;
				DOB_ARR.push_back(FUL_PATH);
			}

		} while (FindNextFile(hf, &FindFileData) != 0);
		FindClose(hf);
	}

	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ����������  (TRUE - ���� ������� ������ ����� FALSE - ���)
// ������� �����
bool ARG_COMAND::EMPTY_DOB_ARR(bool EMPTY_YES_NO)
{
	if (DOB_ARR.empty())
	{

		return true;
	}


	if (EMPTY_YES_NO)
	{
		DOB_ARR.pop_back();
		return false;
	}

	{

		return false;

	}
	
}


///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ����������  ���� ����� � ������� ��������� ����� KONTEINER
// 
string* ARG_COMAND::PATH_IN_OUT()
{
	string KONTEINER_FOR(_TCHAR*&);
	string KONTEINER[2];

	KONTEINER[0]= KONTEINER_FOR(ARG_COMAND::Input);
	KONTEINER[1] = KONTEINER_FOR(ARG_COMAND::Output);


	return KONTEINER;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ��������������� ��� ����������� ����
// 
string KONTEINER_FOR(_TCHAR*& In)
{

	string TEMP;
	wstring bob(In);
	string bill(bob.begin(), bob.end());
	TEMP = bill;

	static const int MAX = 200;
	char TEMP_CH[MAX];                 // ���� � ���� �������


	STRING_TO_CHAR(TEMP, TEMP_CH);
	replace(TEMP.begin(), TEMP.end(), _T('\\'), _T('/'));


	string TEMP_PATH;
	TEMP_PATH = TEMP;


//	string TEMP_PATH;
//	TEMP_PATH = TEMP;

	return TEMP;


}