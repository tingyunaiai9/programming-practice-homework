#pragma once

#include <string>
#include <iostream>

using namespace std;

class Member
{
private:
	const string m_name;
	const int m_age;

public:
	Member(string name = "?", int age = 0);
	~Member();

	friend ostream& operator<<(ostream& os, const Member& m);
};

