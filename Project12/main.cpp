#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString obj1("Hello World!");
	obj1.Print();

	MyString obj2 = obj1;
	obj2.Print();

	MyString obj3("Bye World!");
	obj3.Print();

	cout << "Strstr: " << obj2.MyStrStr("wo") << endl;
	cout << "Strcpy: ";
	//obj3.MyStrcpy(obj1);
}
