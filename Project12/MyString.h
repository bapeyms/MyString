#pragma once
class MyString
{
	char* str;
	int length;
	static int count;

public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	MyString(const char* st, int size);
	MyString(const MyString& obj);
	~MyString();

	MyString(MyString&& obj);

	void Print();
	bool MyStrStr(const char* st);
	void MyStrcpy(MyString& obj);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(const MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	static void PrintCount();
	MyString operator+(const char* b);
	MyString operator++(int);
	MyString operator--(int);
	MyString operator+=(MyString& b);
};

