#include "MyString.h"
#include <iostream>
using namespace std;

MyString::MyString() :str(nullptr), length(0)
{
	length = 80;
	str = new char[length] {};
	count++;
}
MyString::MyString(int size)
{
	length = size;
	str = new char[length] {};
	count++;
}
MyString::MyString(const char* st)
{
	length = strlen(st);
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
	count++;
}
MyString::MyString(const char* st, int size)
{
	length = size;
	str = new char[length + 1];
	strcpy_s(str, length + 1, st);
	str[length] = '\0';
	count++;
}
MyString::~MyString()
{
	delete[] str;
	length = 0;
	count--;
}

MyString::MyString(const MyString& obj)
{
	length = obj.length;
	str = new char[length + 1];
	strcpy_s(str, length + 1, obj.str);
	count++;
}
MyString& MyString::operator=(const MyString& obj)
{
	if (this == &obj)
	{
		return *this;
	}
	if (str != nullptr)
	{
		delete[] str;
	}
	str = new char[strlen(obj.str) + 1];
	strcpy_s(str, strlen(obj.str) + 1, obj.str);
	length = obj.length;
	return *this;
}

MyString::MyString(MyString&& obj)
{
	str = obj.str;
	obj.str = nullptr;
	length = obj.length;
	obj.length = 0;
	count++;
}
MyString& MyString::operator=(MyString&& obj)
{
	if (str != nullptr)
	{
		delete[] str;
	}
	str = obj.str;
	obj.str = nullptr;
	length = obj.length;
	obj.length = 0;
	return *this;
}

void MyString::Print()
{
	cout << str << endl;
	cout << length << endl;
}
bool MyString::MyStrStr(const char* st)
{
	const char* s = strstr(this->str, st);
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
void MyString::MyStrCat(const MyString& b)
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
	int count = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] == c)
		{
			count++;
		}
	}
	int size = length - count;
	char* newStr = new char[size + 1];
	int charIndex = 0;
	for (int i = 0; i < length + 1; i++)
	{
		if (str[i] != c)
		{
			newStr[charIndex] = str[i];
			charIndex++;
		}
	}
	delete[] str;
	str = newStr;
	length = size + 1;
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

int MyString::count = 0;
void MyString::PrintCount()
{
	cout << "Count: " << count << endl << endl;
}

MyString MyString::operator+(const char* b)
{
	MyString result(length + strlen(b) + 2);
	strcpy_s(result.str, length + 1, str);
	strcat_s(result.str, length + strlen(b) + 2, b);
	return result;
}

MyString MyString::operator++(int)
{
	MyString temp(str, length);
	char* newStr = new char[length + 1 + 1];
	strcpy_s(newStr, length + 1 + 1, this->str);
	delete[] str;
	str = newStr;
	length++;
	str[length] = '\0';
	return temp;
}

MyString MyString::operator--(int)
{
	MyString temp(str, length);
	char* newStr = new char[length];
	for (int i = 0; i < length - 1; i++)
	{
		newStr[i] = str[i];
	}
	newStr[length - 1] = '\0';
	delete[] str;
	str = newStr;
	length--;
	return temp;
}

MyString MyString::operator+=(MyString& b)
{
	char* newStr = new char[length + b.length + 1];
	strcpy_s(newStr, length + 1, str);
	strcat_s(newStr, length + b.length + 1, b.str);
	delete[] str;
	str = newStr;
	length += b.length;
	return *this;
}

MyString MyString::operator-=(const char* c)
{
	char* newStr = new char[length + 1];
	int charIndex = 0;
	for (int i = 0; i < length; i++)
	{
		bool check = false;
		for (int j = 0; c[j] != '\0'; j++)
		{
			if (str[i] == c[j])
			{
				check = true;
				break;
			}
		}
		if (!check)
		{
			newStr[charIndex++] = str[i];
		}
	}
	newStr[charIndex] = '\0';
	delete[] str;
	str = newStr;
	length = charIndex;
	return *this;
}

