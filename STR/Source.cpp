#include<iostream>
#include<Windows.h>

/*
TODO:
�������� �������:
bool is_palindrome(char str[]);	//���������, �������� �� ������ ����������� (���, ���, 12321)
bool is_int_number(char str[]);	//���������, �������� �� ������ ����� ���������� ������
int  to_int_number(char str[]);	//���� ������ - ���������� �����, �� ������� ���������� ��� int-���� ��������.
bool is_bin_number(char str[]);	//���������, �������� �� ������ �������� ������
int  bin_to_dec(char str[]);	//���� ������ - �������� �����, �� ������� ���������� ��� ���������� ��������.
bool is_hex_number(char str[]);	//���������, �������� �� ������ ����������������� ������
int  hex_to_dec(char str[]);	//���� ������ - ����������������� �����, �� ������� ���������� ��� ���������� ��������.

*/

int StringLength(char str[]);
void to_upper(char str[]);
void remove_symbol(char str[], char sumbol);
void shrink(char str[]);		//������� ������ ������� ����� ������� � �����������
//������       ������   ��    �����     �����-���
//������ ������ �� ����� �����-���
//HELLO
bool is_palindrome(char str[]);	//�������� ������� (���������� ������� - Function declaration)

void main()
{
	using namespace std;
	/*for(;;)
	{
		cout << "Hello World";
	}*/
	//setlocale(LC_ALL, "Russian");
	//C char 
	//ASCII-������ � ����� 0 - '\0'
	//char str[] = { 'H', 'e', 'l', 'l', 'o', 0 };
	/*char str[] = "Hello World!";
	cout << str << endl;
	cout << sizeof(str) << endl;*/

	//for (int i = 0; i < 256; i++)cout << i << "\t" << (char)i << endl;

	/*cout << 'A' << "\t" << 'a' << endl;
	cout << (int)'A' << "\t" << (int)'a' << endl;
	cout << 'A' - 'a' << endl;*/

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	const int n = 256;
	char str[n] = "������       ������   ��    �����     �����-���";
	cout << "������� ������: "; //cin >> str;
	cin.getline(str, n);
	//SetConsoleCP(866);
	cout << str << endl;
	//cout << typeid(str).name() << endl;
	//cout << StringLength(str) << endl;
	//to_upper(str);
	shrink(str);
	cout << str << endl;

	//cout << is_palindrome(str) << endl;
	if (is_palindrome(str))
	{
		cout << "��������� ������ - ���������" << endl;
	}
	else
	{
		cout << "��������� ������ - �� ���������" << endl;
	}
	/*char* dynamic_string = new char[255];
	cout << "������� ������: ";
	cin >> dynamic_string;
	cout << dynamic_string << endl;
	delete[] dynamic_string;*/
}

int StringLength(char str[])
{
	std::cout << typeid(str).name() << std::endl;
	int i = 0;
	for (; str[i]; i++);
	return i;
}
void to_upper(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		if (
			str[i] >= 'a' && str[i] <= 'z' ||
			str[i] >= '�' && str[i] <= '�'
			)//���� ������� ������ - ��������� �����
			str[i] -= 32;	//�� ��������� ��� � ������� �������.
	}
}
void shrink(char str[])
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == ' ' && str[i + 1] == ' ')
		{
			for (int j = i + 1; str[j]; j++)
				str[j] = str[j + 1];
		}
	}
}
bool is_palindrome(char str[])	//���������� ������� (����������� ������� - Function definition)
{
	int n = StringLength(str);
	char* buffer = new char[n + 1]{};
	
	to_upper(str);
	remove_symbol(str, ' ');
for (int i = 0; i < n; i++)
	{
		buffer[i] = str[i];
	}
	for (int i = 0; i < n / 2; i++)
	{
		if (buffer[i] != buffer[n - 1 - i])
		{
			delete[] buffer;
			return false;
		}
	}
	delete[] buffer;
	return true;
}

void remove_symbol(char str[], char symbol)
{
	for (int i = 0; str[i]; i++)
	{
		while (str[i] == symbol)
		{
			for (int j = i; str[j]; j++)
			{
				str[j] = str[j + 1];
			}
		}
	}
}