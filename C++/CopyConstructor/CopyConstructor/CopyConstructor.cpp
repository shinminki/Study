#include<iostream>
#include<string>

using namespace std;

class Simple{
private:
	int num1;
	int num2;
public:
	Simple(int n1, int n2) : num1(n1), num2(n2){

	}
	Simple(const Simple &copy) : num1(copy.num1), num2(copy.num2)
	{
		cout << "���� ������ ȣ��" << endl;
	}


	void showSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}

	~Simple(){
		cout << "�Ҹ��� ȣ��" << endl;
	}
};


int main()
{
	Simple sim1(5, 10);
	cout << "���� �� �ʱ�ȭ ����" << endl;
	Simple sim2 = sim1;
	cout << "���� �� �ʱ�ȭ ����" << endl;
	sim2.showSimpleData();

	system("pause");
	return 0;
}