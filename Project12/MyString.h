#pragma once
class MyString
{
	char* str;
	int lenght;
public:
	MyString();
	MyString(int size);
	MyString(const char* st);
	MyString(const MyString& obj);
	~MyString();

	void Print();
	bool MyStrStr(const char* st);
	void MyStrcpy(MyString& obj);
};

