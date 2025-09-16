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
	cout << "String: " << str << endl;
	cout << "Lenght: " << lenght << endl;
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
	char* s = new char[obj.lenght];
	strcpy_s(this->str, obj.lenght, s);
}
