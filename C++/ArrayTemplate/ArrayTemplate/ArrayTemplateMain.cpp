#include <iostream>
#include "ArrayTemplate.h"
#include "Point.h"

using namespace std;

int main()
{
	/* int�� ���� ���� */
	BoundCheckTArray<int> iArr(5);
	for (int i = 0; i < 5; i++)
	{
		iArr[i] = (i + 1) * 11;
	}
	for (int i = 0; i < 5; i++)
	{
		cout << iArr[i] << endl;
	}

	/* Point ��ü ���� */
	BoundCheckTArray<Point> pArr(3);
	pArr[0] = Point(3, 4);
	pArr[1] = Point(5, 6);
	pArr[2] = Point(7, 8);
	for (int i = 0; i < pArr.getArrLen(); i++)
	{
		cout << pArr[i];
	}

	/* Point ��ü�� �ּҰ� ���� */
	typedef Point* POINT_PTR;
	BoundCheckTArray<POINT_PTR> ppArr(3);
	ppArr[0] = new Point(33, 44);
	ppArr[1] = new Point(55, 66);
	ppArr[2] = new Point(77, 88);
	for (int i = 0; i < ppArr.getArrLen(); i++)
	{
		cout << *(ppArr[i]);
	}

	delete ppArr[0];
	delete ppArr[1];
	delete ppArr[2];

	return 0;
}