#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString() :str(nullptr), length(0)
{
	length = 80;
	str = new char[length] {};
}
MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
}
MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
}
MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);

} 
MyString::~MyString()
{
	delete[] str;
	length = 0;
}

void MyString::Print()
{
	cout << str << endl;
	cout << length << endl;
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
	if (strlen(obj.str) + 1 > length)
	{
		delete[] str;
		length = strlen(obj.str) + 1;
		str = new char[length];
	}
	strcpy_s(this->str, length, obj.str);
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
	int catSize = this->length + b.length + 1;
	char* cat = new char[catSize];
	for (int i = 0; i < this->length; i++)
	{
		cat[i] = this->str[i];
	}
	for (int i = 0; i < b.length; i++)
	{
		cat[this->length + i] = b.str[i];
	}
	cat[catSize - 1] = '\0';
	delete[] this->str;
	this->str = cat;
	this->length = catSize - 1;
}
void MyString::MyDelChr(char c)
{
	int charIndex = 0;
	for (int i = 0; i < length; i++)
	{
		if (str[i] == c)
		{
			charIndex = i;
			break;
		}
	}
	if (charIndex == -1)
	{
		return;
	}
	int size = this->length - 1;
	char* newStr = new char[size + 1];
	for (int i = 0; i < charIndex; i++)
	{
		newStr[i] = this->str[i];
	}
	for (int i = charIndex; i < size; i++)
	{
		newStr[i] = this->str[i +1 ];
	}
	newStr[size] = '\0';
	delete[] this->str;
	this->str = newStr;
	this->length = size + 1;
}

int MyString::MyStrCmp(MyString& b)
{
	int minLen = 0;
	if (this->length < b.length)
	{
		minLen = this->length;
	}
	else
	{
		minLen = b.length;
	}
	for (int i = 0; i < minLen; i++)
	{
		if (this->str[i] > b.str[i])
		{
			return 1;
		}
		else if (this->str[i] < b.str[i])
		{
			return -1;
		}
		else
		{
			return 0;
		}
	}
	if (this->length > b.length)
	{
		
	}
	else if (this->length < b.length)
	{
		return -1;
	}
	return 0;
}

