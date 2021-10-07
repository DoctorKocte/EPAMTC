#pragma once
#include <iostream>
#include <string>

using namespace std;

class MyString {
private:
	string m_str;
public:
	MyString();
	MyString(string);
	string getStr();
	void setStr(string);
	void replace();
	void replaceC();
	void multiplicity();
	~MyString();
};
