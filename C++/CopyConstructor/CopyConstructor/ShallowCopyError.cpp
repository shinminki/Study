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
	Person(const Person &man)
	{
		string copyName = man.name;
		int copyAge = man.age;
		name = copyName;
		age = copyAge;
	}
	~Person(){
		cout << "�Ҹ��� ȣ��" << endl;
	}
	
	void ShowPersonInfo(){
		cout << "�̸� : " << name << endl;
		cout << "���� : " << age << endl;
	}
};

int main()
{
	Person man1("Shin Min Ki", 27);
	Person man2(man1);
	man1.ShowPersonInfo();
	man2.ShowPersonInfo();
	
	system("pause");
	return 0;
}

/*
//----���� ����
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
~Person(){
cout << "�Ҹ��� ȣ��" << endl;
}

void ShowPersonInfo(){
cout << "�̸� : " << name << endl;
cout << "���� : " << age << endl;
}
};

int main()
{
Person man1("Shin Min Ki", 27);
Person man2 = man1;  // ���� ����
man1.ShowPersonInfo();
man2.ShowPersonInfo();

system("pause");
return 0;
}*/