#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString obj1("Hello World!");
	cout << "#1" << endl;
	obj1.Print();
	cout << endl;

	MyString obj2 = obj1;
	cout << "#2" << endl;
	obj2.Print();
	cout << endl;

	MyString obj3("Bye World!");
	cout << "#3" << endl;
	obj3.Print();
	cout << endl;

	cout << "Move constructor: " << endl;
	MyString obj4("My World!");
	MyString obj5 = move(obj4);
	obj5.Print();
	cout << endl;

	MyString::PrintCount();

	cout << "--- STR ---" << endl;
	cout << "- Strstr: " << endl;
	cout << obj2.MyStrStr("wo") << endl;

	cout << "- Strcpy: " << endl;
	obj1.MyStrcpy(obj3);
	obj1.Print();

	cout << "- Chr: " << endl;
	cout << obj1.MyChr('h');
	cout << endl;

	cout << "- Strlen: " << endl;
	cout << obj1.MyStrLen();
	cout << endl;

	cout << "- Strcat: " << endl;
	obj2.MyStrCat(obj3);
	obj2.Print();

	cout << "- DelChr: " << endl;
	obj3.MyDelChr('l');
	obj3.Print();

	cout << "- StrCmp: " << endl;
	cout << obj3.MyStrCmp(obj2);
	cout << endl;

	cout << endl << "--- OPERATORS ---" << endl;
	cout << "+" << endl;
	MyString n("Hello to the ");
	n.Print();
	MyString result1 = n + "world!";
	result1.Print();

	MyString a("Hello");
	MyString b("world");
	
	cout << endl << "a += b" << endl;
	a += b;
	a.Print();

	cout << endl << "a -=" << endl;
	a -= "lo";
	a.Print();

	cout << endl << "a++" << endl;
	a++;
	a.Print();

	cout << endl << "b--" << endl;
	b--;
	b.Print();
}
