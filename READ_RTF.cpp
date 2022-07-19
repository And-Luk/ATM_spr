#include"stdafx.h"

#include "READ_RTF.h"


READ_RTF::READ_RTF() : DOUBLE_ARRAY()   //  : DOUBLE_ARRAY()  ���� ���������
{
	//cout << "  ����������� READ_RTF ��� ���������� = " << this << endl;   // �������� �� ����������� ����� TEST.jrn
	file_name_IN  = "Report.RTF";
	file_name_OUT = "D://ATM_OUT/OUT_FILE.RTF";             // ("D://ATM_IN/OUT_FILE.RTF")
}


//in.open(File_NAME_IN);                
READ_RTF::READ_RTF(string File_NAME_IN) : DOUBLE_ARRAY()
{   
	//cout << "  ����������� READ_RTF � ���������� " << " =  " << this << endl;   // �������� �� ����������� ����� TEST.jrn
	file_name_IN  = File_NAME_IN;
	file_name_OUT = "D://ATM_OUT/OUT_FILE.RTF";
}


READ_RTF::~READ_RTF()
{	
	//cout << "  ����������  READ_RTF = " << this->file_name_IN << " = " << this << endl;
}

//////////////////////////////////////////////////////////////////////////////////
//bool READ_RTF::READ_FILE_RTF(DOUBLE_ARRAY&)
// ������� ���� RTF ��� ������������
bool READ_RTF::READ_FILE_RTF(DOUBLE_ARRAY &DOUB_ARR, string PATH_NAME_IN, string PATH_NAME_OUT) //(DOUBLE_ARRAY &DOUB_ARR)
{
	string IN_GET_CHAR;              // ������ ��� ��������� ������ �� �����
	size_t END_RTF ;                  // ������� ������ "{"   "}"
	char ch;                         // ������ ��� ���������� �� �����
	char BUFER[MAX];                 // ����� ����� ������� � ����

//////////////////////////////////////////////////////////////////////////////////////////////////
// ������� ���� RTF ��� ������������
	in.open(PATH_NAME_IN);

	if (!in)
	{
		cout << "    ��� RTF ����� " << file_name_IN << " ��� ������" << endl;   // �������� �� ����������� ����� TEST.jrn
	}

// ���������� ���������� ������� ������ � ������ 
// ������� ��������� ������ � ������
	ostrstream Object_Memory(BUFER, MAX);   

											

		
//////////////////////////////////////////////////////////////////////////////////////////////////
//  ��������� ������ ���������� ����������� �� ������� "}"

	END_RTF = 0;

	// ���� �� ����� RTF � !END_RTF = 0;
	do
	{

		do
		{
			IN_GET_CHAR.erase();
			do
			{
				in.get(ch);
				if (ch == '{')          // ��������  ������� ������� �� ����� ������
				{
					++END_RTF;
				}
				if (ch == '}')          // ��������  ������� ������� �� ����� ������
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

					
					int POZ;    //������� � ������� ������ � ����������� �� �����
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
// ������� � ����� ����� ������� � ����
			Object_Memory << IN_GET_CHAR;
			
			IN_GET_CHAR.clear();

		} while (!IN_GET_CHAR.empty() && END_RTF!=0);


	} while (END_RTF!=0);/////////////////////  ����� ������ ����� RTF
/////////////////////////////////////////////////////////////////////////////////////////


/////////////////////////////////////////////////////////////////////////////////////////
// ������� RTF
	in.close();

/////////////////////////////////////////////////////////////////////////////////////////
//   ��������� ����� "\0"
	Object_Memory << '\0';
/////////////////////////////////////////////////////////////////////////////////////////
// ������� �������� ����  "ATM_11571_DATE_OUT.RTF"
	file_name_OUT = PATH_NAME_OUT;

	
	ofstream   out (file_name_OUT);          
	out << BUFER;
	out.close();





// �������� ���������� ������
	while (!DOUB_ARR.DOB_END_QUE_ARR.empty())
	{
		delete[] DOUB_ARR.DOB_END_QUE_ARR.front();
		DOUB_ARR.DOB_END_QUE_ARR.pop_front();
	}


	

	return false;

/////////////////////////////////////////////////////////////////////////////////////////
}//////////  END  //////// bool READ_RTF::READ_FILE_RTF() ///////////////////////////////