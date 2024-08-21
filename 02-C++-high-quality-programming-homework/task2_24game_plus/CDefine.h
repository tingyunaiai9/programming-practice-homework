#pragma once
class CDefine
{
};

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <cmath>

using namespace std;

template <typename T>
inline void SAFE_DELETE(T*& t)
{
	if (t)
	{
		delete t;
	}
	t = nullptr;
}