#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

using namespace std;

class String {
private:
	int len;
	char* str;
public:
	String() : len(0), str(NULL) {}
	String(const char* s) {
		len = strlen(s) + 1;
		str = new char[len];
		strcpy(str, s);
	}
	String(const String& s) : len(s.len) { // 깊은 복사 생성자
		//len = s.len;
		str = new char[len];
		strcpy(str, s.str);
	}

	String& operator=(const String& s) { // 대입연산자 깊은 복사
		if(str!=NULL)
		{
			delete[]str;
		}
		len = s.len;
		str = new char[len];
		strcpy(str, s.str);
		return *this;
	}

	String operator+(const String& s) {
		len += (s.len - 1);
		char* tmpStr = new char[len];
		strcpy(tmpStr, str);
		strcat(tmpStr, s.str);

		String temp(tmpStr); // tmpStr이 연산결과임. 그 결과를 새로운 String 객체 생성자로 전달
		delete tmpStr; //임시 str 삭제 
		return temp;
	}

	String& operator+=(const String& s) {
		len += (s.len - 1);
		char *tmpStr = new char[len];
		strcpy(tmpStr, str);
		strcat(tmpStr, s.str);
		
		if (str != NULL)
		{
			delete[]str;
		}
		str = tmpStr;

		return *this;
	}

	bool operator==(const String& s) {
		if (!strcmp(str,s.str))
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	friend ostream& operator<<(ostream& os, const String& s){
		os << s.str;
		return os;
	}

	friend istream& operator>>(istream& is, String& s) {
		char str[100];
		is >> str;
		s = String(str);
		return is;
	}

	~String() { 
		if (str != NULL)
			delete[]str;
	}

	
};

int main() {
	String myStr1 = "shin";
	String myStr2 = "minki";

	cout << myStr1 + myStr2 << endl;
	String tmp1 = myStr1 += myStr2;
	cout << tmp1 << endl;

	cin >> myStr1;
	cin >> myStr2;

	cout << myStr1 + myStr2 << endl;
	String tmp2 = myStr1 += myStr2;
	cout << tmp2 << endl;

	cout << tmp1 + tmp2 << endl;

	if (tmp1 == tmp2)
	{
		cout << " return true / equal String. " << endl;
	}else{
		cout << " return false / Not equal String. " << endl;
	}

	tmp1 = tmp2;
	cout << "tmp1 : " << tmp1 << " tmp2 : " << tmp2 << endl;

	if (tmp1 == tmp2)
	{
		cout << " return true / equal String. " << endl;
	}
	else {
		cout << " return false / Not equal String. " << endl;
	}
}