#include <iostream>
#include <string>
int StrLength(char* str);
void StrUpper(char* str);
bool is_palindrome(char* str);
void shrink(char* str);
void remove_symbol(char* str, char symbol);
bool is_in_number(char* str);
int main()
{
    using namespace std;
    const int n = 250;
    char str[n];
    cout << "Enter the string: ";
    cin.getline(str, n);
    cout << "String: " << str << endl;
    if (is_palindrome(str))
        cout << "This is palindrome!" << endl;
    else
        cout << "This is not palindrome!" << endl;
    if (is_in_number(str))
        cout << "String is a number" << endl;
    else
        cout << "String is not a number" << endl;
    return 0;
}



void StrUpper(char* str)
{
    int i = 0;
    size_t length = strlen(str);
    while (i < length)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] -= 32;
        }
        i++;
    }
}
void shrink(char* str)
{
    for (int i = 0; str[i]; ++i)
    {
        while (str[i] != ' ' && str[i + 1] == ' ')
            for (int j = i + 1; str[j]; ++j)
            {
                str[j] = str[j + 1];
            }
    }
}

bool is_palindrome(char* str)
{
    size_t n = 250;
    char* buffer = new char[n + 1]{}; // инициализируют выделенную память значениями по умолчанию
    //зануляет выделенную память
    n = strlen(buffer); // возвращает длинну строки в символах
    StrUpper(buffer);
    shrink(buffer);
    strcpy(buffer, str); //копирует одну строку в другую
    // strcpy(dst, scr); // dst(destination) - строка получатель, scr(source) - строка источник
    // strcpy(куда
    for (int i = 0; i < n / 2; i++)
    {
        if (str[i] != str[n - 1 - i])
        {
            delete[] buffer;
            return false;
        }
    }


    delete[] buffer;
    return true;
}


int StrLength(char* str)
{
    int length = 0;
    while (*str++)
    {
        length++;
    }
    return length;
}


void remove_symbol(char* str, char symbol)
{
    for (int i = 0; str[i]; i++)
    {
        while (str[i] == symbol)
        {
            for (int j = i; str[j]; j++)
                str[j] = str[j + 1];
        }
    }
}
bool is_in_number(char* str)
{
    for (int i = 0; str[i]; ++i)
    {
        if (!(str[i] >= '0' && str[i] <= '9')) // Если элемент не цифра
            return false;
    }
    return true;
}