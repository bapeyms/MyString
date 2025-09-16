#include <iostream>
#include "MyString.h"
using namespace std;

int main()
{
	MyString obj1("Hello World!");
	cout << "#1" << endl;
	obj1.Print();

	MyString obj2 = obj1;
	cout << "#2" << endl;
	obj2.Print();

	MyString obj3("Bye World!");
	cout << "#3" << endl;
	obj3.Print();

	cout << "- Strstr: " << endl;
	cout << obj2.MyStrStr("wo") << endl;
	cout << "- Strcpy: " << endl;
	obj1.MyStrcpy(obj3);
	obj1.Print();
	cout << "- Chr: " << endl;
	cout << obj1.MyChr('d');
	cout << endl;
	cout << "- Strlen: " << endl;
	cout << obj1.MyStrLen();
}
