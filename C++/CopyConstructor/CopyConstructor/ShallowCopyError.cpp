#include <iostream>
#include <string>

using namespace std;


class Person{
private:
	string name;
	int age;
public:
	Person(string n, int a) : name(n), age(a)
	{

	}
	~Person(){}
};

int main()
{

	return 0;
}