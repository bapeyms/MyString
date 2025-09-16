#pragma once
class MyString
{
	char* str;
	int length;
public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	MyString(const MyString& obj);
	~MyString();

	void Print();
	bool MyStrStr(const char* st);
	void MyStrcpy(MyString& obj);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);
};

