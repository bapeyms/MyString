#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString() :str(nullptr), lenght(0)
{
	lenght = 80;
	str = new char[lenght] {};
}

MyString::MyString(int size)
{
	lenght = size;
	str = new char[lenght] {};
}

MyString::MyString(const char* st)
{
	lenght = strlen(st);
	str = new char[lenght + 1];
	strcpy_s(str, lenght + 1, st);
}

MyString::MyString(const MyString& obj)
{
	lenght = obj.lenght;
	str = new char[lenght + 1];
	strcpy_s(str, lenght + 1, obj.str);

} 

MyString::~MyString()
{
	delete[] str;
	lenght = 0;
}

void MyString::Print()
{
	cout << str << endl;
	cout << lenght << endl << endl;
}

bool MyString::MyStrStr(const char* st)
{
	const char* s = strstr(this->str, str);
	if (s != nullptr)
	{
		return true;
	}
	return false;
}

void MyString::MyStrcpy(MyString& obj)
{
	if (strlen(obj.str) + 1 > lenght)
	{
		delete[] str;
		lenght = strlen(obj.str) + 1;
		str = new char[lenght];
	}
	strcpy_s(this->str, lenght, obj.str);
}

int MyString::MyChr(char c)
{
	for (int i = 0; this->str[i] != '\0'; i++)
	{
		if (this->str[i] == c)
		{
			return i;
		}
	}
	return -1;
}

int MyString::MyStrLen()
{
	int len = 0;
	for (int i = 0; this->str[i] != '\0'; i++)
	{
		len++;
	}
	return len;
}

void MyString::MyStrCat(MyString& b)
{
	int catSize = this->lenght + lenght + 1;
	char* cat = new char[catSize];
	for (int i = 0; i < catSize; i++)
	{

	}
}
