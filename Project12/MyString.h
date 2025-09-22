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
};

