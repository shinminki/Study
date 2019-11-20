#include <iostream>
#include <cstdlib>

using namespace std;

void swap(int a, int b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swapRef(int& a, int& b)
{
	int temp;
	temp = a;
	a = b;
	b = temp;
}

int main()
{
	int a = 5; 
	int* b = &a;
	cout << a << endl << b << endl;

	a = 10;
	int& aa = a;
	int& aaa = a;
	int* bb = &aaa;
	cout << aaa << endl << bb << endl;

	cout << "================================" << endl;

	int c = 10;
	int* ptrc = &c;
	cout << ptrc << endl;
	ptrc += 1;
	cout << ptrc << endl;
	int& cc = *ptrc;
	cout << &c << endl;
	cout << &cc << endl;

	int d = 20;
	int* ptrd = &d;
	cout << ptrd << endl;
	ptrd += 2;
	cout << ptrd << endl;
	int& dd = *ptrd;
	cout << &d << endl;
	cout << &dd << endl;

	cout << "================================" << endl;

	int one = 1;
	int two = 2;
	int thr = 3;
	int fou = 4;
	int* ptrone = &one;
	int* ptrtwo = &two;
	int* ptrthr = &thr;
	int* ptrfou = &fou;

	cout << one << two << endl;
	cout << ptrone << " " << ptrtwo << endl;
	swap(one, two);
	cout << one << two << endl;
	cout << ptrone << " "<< ptrtwo << endl;
	cout << "================================" << endl;
	cout << thr << fou << endl;
	cout << ptrthr << " " << ptrfou << endl;
	swapRef(thr, fou);
	cout << thr << fou << endl;
	cout << ptrthr << " " << ptrfou << endl;

	return 0;
}

