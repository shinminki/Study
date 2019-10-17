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
		cout << "복사 생성자 호출" << endl;
	}


	void showSimpleData()
	{
		cout << num1 << endl;
		cout << num2 << endl;
	}

	~Simple(){
		cout << "소멸자 호출" << endl;
	}
};


int main()
{
	Simple sim1(5, 10);
	cout << "생성 및 초기화 직전" << endl;
	Simple sim2 = sim1;
	cout << "생성 및 초기화 직후" << endl;
	sim2.showSimpleData();

	system("pause");
	return 0;
}