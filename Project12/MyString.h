#pragma once
#include <iostream>
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
	~MyString();

	MyString(const MyString& obj);
	MyString& operator=(const MyString& obj);

	MyString(MyString&& obj);
	MyString& operator=(MyString&& obj);

	friend std::ostream& operator<<(std::ostream& is, const MyString& obj);
	friend std::istream& operator>>(std::istream& is, MyString& obj);

	void Print() const;
	bool MyStrStr(const char* st);
	void MyStrcpy(MyString& obj);
	int  MyChr(char c);
	int MyStrLen();
	void MyStrCat(const MyString& b);
	void MyDelChr(char c);
	int MyStrCmp(MyString& b);

	static void PrintCount();
	MyString operator+(const char* b);
	MyString operator-(const char* c);

	MyString operator++(int);
	MyString operator--(int);
	MyString operator+=(MyString& b);
	MyString operator-=(const char* c);
	bool operator>(MyString& b);
	bool operator==(const MyString& b);

	int GetLength() const;
	char* GetStr() const;
	void SetStr(const char* s);
	void SetLength(int l);
	char operator[](int index);
};

