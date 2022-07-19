#include "stdafx.h"

#include "MODEL_BANKOMAT.h"



MODEL_BANKOMAT::MODEL_BANKOMAT()
{
	//cout << "  ����������� MODEL_BANKOMAT  = " << this << endl;  
}

MODEL_BANKOMAT::~MODEL_BANKOMAT()
{
	//cout << "  ����������  MODEL_BANKOMAT = " << this << endl;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
//�� ����� ����� ���� string IN_STRING -> �� ������ int �����
unsigned int MODEL_BANKOMAT::STRING_TO_INT(string IN_STRING)
{
	const short MAX = 10;
	char ARRY_STRING[MAX];
	size_t i = STRING_TO_CHAR(IN_STRING, ARRY_STRING);
	int  OUT_INT = atoi(ARRY_STRING);
	return OUT_INT;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// �������������� string IN_STRING � ASCII ������������������
string MODEL_BANKOMAT::STRING_TO_ASCII(string IN_STRING)
{
	const short MAX = 300;
	char BUFER[MAX];
	size_t i = 0;
	string OUT_STRING;

	char ARRY_STRING[MAX];
	size_t size_IN_STRING = STRING_TO_CHAR(IN_STRING, ARRY_STRING);
	
//   ���������� ���������� ������� ������ � ������ 
	ostrstream ObjMem(BUFER, MAX);   // ������� ��������� ������ � ������

	i = 0;
	while (i < size_IN_STRING)
	{
		if (ARRY_STRING[i] == ' ')
		{
			ObjMem << ' ' ;  // �������� ������� � ����� ASCII ��������
		}
		else
		{
			ObjMem << '\\' << '\'' << std::hex << ((static_cast<int>(ARRY_STRING[i]) - 4294967040));  // static_cast<int>(   << setw(20)   %X
		}
		++i;
	}
	ObjMem << '\0';            // <----------------���������
	OUT_STRING = BUFER;        // <----------------���������
	return OUT_STRING;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// �������������� string IN_STRING � string ������������������ ����   ������ �����
string MODEL_BANKOMAT::INT_TO_STRING_OF_WORLDS(unsigned int IN_INT)
//string TranslatePart(const int IN_INT, short p)

{
	long m = 1;
	short k = 0;
	int x = 1;
	string rez = "";

	if ((IN_INT < 0) || (IN_INT > 100000000))  //"������� ����� �� 0 �� 100000000: "
	{
		IN_INT=111111;
	}

	while (k <= 6)
	{
		x = IN_INT / m % 1000;
		rez.insert(0, TranslatePart(x, k));
		m *= 1000;
		k += 3;
	}
	
	return rez;

}

//////////////////////////////////////////////////////////////////////////////////////////////////
// �������������� string IN_STRING � string ������������������ ����  ������ �����
string MODEL_BANKOMAT::TranslatePart(int x, short p)
{
	string third[] = { "", "���", "������", "������", "���������", "�������", "��������", "�������", "���������", "���������" };
	string second[] = { "", "", "��������", "��������", "�����", "���������", "����������", "���������", "�����������", "���������" };
	string second_1[] = { "������", "�����������", "����������", "����������", "������������", "����������", "�����������",
		"����������", "������������", "������������" };
	string first[] = { "", "����", "���", "���", "������", "����", "�����", "����", "������", "������" };
	string first_r[] = { "", "����", "���" };

	string result = "";
	int f;
	bool stop = false;
	int d = x / 100 % 10;

	if (x == 0) return "";

	switch (d) {
	case 0:
		break;
	default:
		result += third[d];
		result += " ";
		break;
	}
	d = (int)(x / 10 % 10);
	if (d != 0) {
		switch (d) {
		case 1:
			f = x % 10;
			result += second_1[f];
			stop = true;
			break;
		default:
			result += second[d];
			break;
		}
		result += " ";
	}
	d = x % 10;
	if (!stop && (d != 0)) {
		switch (d) {
		case 1:
		case 2:
			if (p == 3) result += first_r[d];
			else result += first[d];
			break;
		default:
			result += first[d];
			break;
		}
		result += " ";
	}

	//add some more words
	if (((int)(x / 10 % 10) == 1) || (d >= 5)) {
		switch (p) {
		case 6:
			result += "��������� ";
			break;
		case 3: result += "����� "; break;
		}
	}
	else if (p == 3) {
		switch (d) {
		case 1:
			result += "������ ";
			break;
		case 2:
		case 3:
		case 4:
			result += "������ ";
			break;
		default:
			result += "����� ";
			break;
		}
	}
	else if (p == 6) {
		switch (d) {
		case 1:
			result += "������� ";
			break;
		case 2:
		case 3:
		case 4:
			result += "�������� ";
			break;
		default:
			result += "��������� ";
			break;
		}
	}

	return result;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ���������� ����� �� ����� 1990 -> 2000
unsigned int MODEL_BANKOMAT::INT_ROUND(const unsigned int IN_INT)
{
	double TEMP;
	TEMP = static_cast<double>(IN_INT);
	TEMP = round(TEMP / 100) * 100;
	return static_cast<int>(TEMP);
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ��������� ��������� � ������
void MODEL_BANKOMAT::PUSH_STRUCT_BANKOMAT(BANKOMAT_STRUCT  &BAN_STR)              // ��������� ��������� � ��� ������� 
{
	B_STRUCT = BAN_STR;
}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ���������� = ��� ��������
void MODEL_BANKOMAT::operator =(const BANKOMAT_STRUCT S2)
{
	this->B_STRUCT.DATE = S2.DATE;
	this->B_STRUCT.TIME = S2.TIME;
	this->B_STRUCT.ATM = S2.ATM;
	this->B_STRUCT.ADRES_ASCII = S2.ADRES_ASCII;
	this->B_STRUCT.FAMALY_ASCII = S2.FAMALY_ASCII;

	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			this->B_STRUCT.count_str_VYG[i][j] = S2.count_str_VYG[i][j];
			this->B_STRUCT.count_str_ZAG[i][j] = S2.count_str_ZAG[i][j];
		}
	}

	//return ;


}

//////////////////////////////////////////////////////////////////////////////////////////////////
// ��������� ��������  MODEL_BANKOMAT � ������ ������� ������� �� ��������� ��������
void MODEL_BANKOMAT::TRANS_STRUCT_BANKOMAT()                       
{
	unsigned int TEMP_INT;   // �������� INT
	string TEMP_STRING;      // �������� ������
	
// ADRES_ASCII
	//TEMP_STRING = STRING_TO_ASCII(B_STRUCT.ADRES_ASCII);
	//(B_STRUCT.ADRES_ASCII).clear();
	//B_STRUCT.ADRES_ASCII = TEMP_STRING;

	// FAMALY_ASCII
	//TEMP_STRING = STRING_TO_ASCII(B_STRUCT.FAMALY_ASCII);
	//(B_STRUCT.FAMALY_ASCII).clear();
	//B_STRUCT.FAMALY_ASCII = TEMP_STRING;

// ���������� ������� ��� ������� ���������
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			B_STRUCT.count_int_VYG[i][j] = STRING_TO_INT(B_STRUCT.count_str_VYG[i][j]) ;
			B_STRUCT.count_int_ZAG[i][j] = STRING_TO_INT(B_STRUCT.count_str_ZAG[i][j]) ;
		}
	}

// ������� �� ��������� ��������  ��������
	TEMP_INT = 0;
	for (size_t i = 0; i < 4; i++)
	{
		// ������� �� ��������� ��������  [3]= [1]+[2]
		TEMP_INT = B_STRUCT.count_int_VYG[i][1] + B_STRUCT.count_int_VYG[i][2];
		// ���������� ����� �� ����� 1990 -> 2000
		TEMP_INT = INT_ROUND(TEMP_INT);
		B_STRUCT.count_int_VYG[i][3]= TEMP_INT- (B_STRUCT.count_int_VYG[i][1] + B_STRUCT.count_int_VYG[i][2]);
	}



////////////////////// <<<<<<<<<<<-----------------------------------------------------

	// ������� �� ��������� ��������  ��������
	TEMP_INT = 0;
	for (size_t i = 0; i < 4; i++)
	{
		// ������� �� ��������� ��������  [3]= [1]+[2]
		TEMP_INT = B_STRUCT.count_int_ZAG[i][1] + B_STRUCT.count_int_ZAG[i][2];
		// ���������� ����� �� ����� 1990 -> 2000
		TEMP_INT = INT_ROUND(TEMP_INT);
		B_STRUCT.count_int_ZAG[i][3] = TEMP_INT - (B_STRUCT.count_int_ZAG[i][1] + B_STRUCT.count_int_ZAG[i][2]);
	}
	////////////////////// <<<<<<<<<<<-----------------------------------------------------



	



// ������� ���������� ����� � ��������� 
	TEMP_INT = 0;
	for (size_t i = 0; i < 4; i++)
	{
		TEMP_INT += (B_STRUCT.count_int_VYG[i][2] + B_STRUCT.count_int_VYG[i][3])*B_STRUCT.count_int_VYG[i][0];
	}
// �������� ����� � ��������� �������
	B_STRUCT.SUMMA = INT_TO_STRING(TEMP_INT);

// ������� ���������� ����� � ��������� � �����
	TEMP_STRING.clear();
	TEMP_STRING = INT_TO_STRING_OF_WORLDS(TEMP_INT);

// �������������� string TEMP_STRING � ASCII ������������������
//TEMP_STRING.clear();
	B_STRUCT.SUMMA_ASCII = STRING_TO_ASCII(TEMP_STRING);
	
	
	
	////////////////////// <<<<<<<<<<<-----------------------------------------------------


	// ������� ���������� ����� � ��������� 
	TEMP_INT = 0;
	for (size_t i = 0; i < 4; i++)
	{
		TEMP_INT += (B_STRUCT.count_int_ZAG[i][2] + B_STRUCT.count_int_ZAG[i][3])*B_STRUCT.count_int_ZAG[i][0];
	}
	// �������� ����� � ��������� �������
	B_STRUCT.SUMMA_ZAG = INT_TO_STRING(TEMP_INT);

	// ������� ���������� ����� � ��������� � �����
	TEMP_STRING.clear();
	TEMP_STRING = INT_TO_STRING_OF_WORLDS(TEMP_INT);

// �������������� string TEMP_STRING � ASCII ������������������
	//TEMP_STRING.clear();
	B_STRUCT.SUMMA_ZAG_ASCII = STRING_TO_ASCII(TEMP_STRING);


	////////////////////// <<<<<<<<<<<-----------------------------------------------------







/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// �������� �������������� � string ���� INT-���� �������� ������� 
	for (size_t i = 0; i < 4; i++)
	{
		for (size_t j = 0; j < 4; j++)
		{
			B_STRUCT.count_str_VYG[i][j] = INT_TO_STRING(B_STRUCT.count_int_VYG[i][j]);
			B_STRUCT.count_str_ZAG[i][j] = INT_TO_STRING(B_STRUCT.count_int_ZAG[i][j]);
		}
	}


};// End TRANS_STRUCT_BANKOMAT()


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������� �������� ����� � ������� �������� ��������
//  PUSH_DOUBLE_ARRAY_STRUCTUR (DOUBLE_ARRAY& D_ARRAY)
void MODEL_BANKOMAT::PUSH_DOUBLE_ARRAY_STRUCTUR(DOUBLE_ARRAY& D_ARRAY)
{
		
	D_ARRAY.PUSH_DOUBLE_ARRAY("####D1", B_STRUCT.DATE);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####D2", B_STRUCT.TIME);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####ATM", B_STRUCT.ATM);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####ADR", B_STRUCT.ADRES_ASCII);

	D_ARRAY.PUSH_DOUBLE_ARRAY("###S40", B_STRUCT.count_str_VYG[0][0]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###S41", B_STRUCT.count_str_VYG[1][0]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###S42", B_STRUCT.count_str_VYG[2][0]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###S43", B_STRUCT.count_str_VYG[3][0]);

	D_ARRAY.PUSH_DOUBLE_ARRAY("###C1", B_STRUCT.count_str_VYG[0][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C2", B_STRUCT.count_str_VYG[0][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C3", B_STRUCT.count_str_VYG[1][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C4", B_STRUCT.count_str_VYG[1][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C5", B_STRUCT.count_str_VYG[2][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C6", B_STRUCT.count_str_VYG[2][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C7", B_STRUCT.count_str_VYG[3][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C8", B_STRUCT.count_str_VYG[3][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c1", B_STRUCT.count_str_VYG[0][3]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c2", B_STRUCT.count_str_VYG[1][3]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c3", B_STRUCT.count_str_VYG[2][3]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c4", B_STRUCT.count_str_VYG[3][3]);

	D_ARRAY.PUSH_DOUBLE_ARRAY("####SUM1", B_STRUCT.SUMMA_ASCII);
	D_ARRAY.PUSH_DOUBLE_ARRAY("##SUMMA", B_STRUCT.SUMMA);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####F1", B_STRUCT.FAMALY_ASCII);

};



/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// ������� �������� ����� � ������� �������� ��������
//  PUSH_DOUBLE_ARRAY_STRUCTUR (DOUBLE_ARRAY& D_ARRAY)
void MODEL_BANKOMAT::PUSH_DOUBLE_ARRAY_STRUCTUR_LOAD(DOUBLE_ARRAY& D_ARRAY)
{
	D_ARRAY.PUSH_DOUBLE_ARRAY("####D1", B_STRUCT.DATE);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####D2", B_STRUCT.TIME);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####ATM", B_STRUCT.ATM);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####ADR", B_STRUCT.ADRES_ASCII);

	D_ARRAY.PUSH_DOUBLE_ARRAY("###S40", B_STRUCT.count_str_ZAG[0][0]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###S41", B_STRUCT.count_str_ZAG[1][0]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###S42", B_STRUCT.count_str_ZAG[2][0]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###S43", B_STRUCT.count_str_ZAG[3][0]);

	D_ARRAY.PUSH_DOUBLE_ARRAY("###C1", B_STRUCT.count_str_ZAG[0][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C2", B_STRUCT.count_str_ZAG[0][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C3", B_STRUCT.count_str_ZAG[1][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C4", B_STRUCT.count_str_ZAG[1][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C5", B_STRUCT.count_str_ZAG[2][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C6", B_STRUCT.count_str_ZAG[2][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C7", B_STRUCT.count_str_ZAG[3][1]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###C8", B_STRUCT.count_str_ZAG[3][2]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c1", B_STRUCT.count_str_ZAG[0][3]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c2", B_STRUCT.count_str_ZAG[1][3]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c3", B_STRUCT.count_str_ZAG[2][3]);
	D_ARRAY.PUSH_DOUBLE_ARRAY("###c4", B_STRUCT.count_str_ZAG[3][3]);

	D_ARRAY.PUSH_DOUBLE_ARRAY("####SUM1", B_STRUCT.SUMMA_ZAG_ASCII);
	D_ARRAY.PUSH_DOUBLE_ARRAY("##SUMMA", B_STRUCT.SUMMA_ZAG);
	D_ARRAY.PUSH_DOUBLE_ARRAY("####F1", B_STRUCT.FAMALY_ASCII);

};













