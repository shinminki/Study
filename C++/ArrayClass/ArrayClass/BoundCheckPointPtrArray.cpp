#include <iostream>

using namespace std;

class Point {
private:
	int xpos;
	int ypos;
public:
	Point(int x=0, int y=0) : xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& p);
};

ostream& operator<<(ostream& os, const Point& p)
{
	os << '[' << p.xpos << " , " << p.ypos << ']' << endl;
	return os;
}

typedef Point* POINT_PTR;

class BoundCheckPointPtrArray {
private:
	POINT_PTR* arr;
	int arrlen;

	BoundCheckPointPtrArray(const BoundCheckPointPtrArray& ref) {}
	BoundCheckPointPtrArray& operator=(const BoundCheckPointPtrArray& ref) {}

public:
	
	BoundCheckPointPtrArray(int len) : arrlen(len) {
		arr = new POINT_PTR[len];
	}
	
	POINT_PTR& operator[](int idx) {
		if (idx < 0 || idx >= arrlen)
		{
			cout << "배열의 범위를 벗어남." << endl;
			exit(1);
		}
		return arr[idx];
	}

	POINT_PTR operator[](int idx) const {
		if (idx < 0 || idx >= arrlen)
		{
			cout << "배열의 범위를 벗어남." << endl;
			exit(1);
		}
		return arr[idx];
	}

	int getArrLen() {
		return arrlen;
	}

	~BoundCheckPointPtrArray() { delete []arr; }
};

int main()
{
	BoundCheckPointPtrArray arr(3);

	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.getArrLen(); i++)
	{
		cout << *(arr[i]);
	}

	for (int i = 0; i < arr.getArrLen(); i++)
	{
		delete arr[i];
	}

	return 0;
}