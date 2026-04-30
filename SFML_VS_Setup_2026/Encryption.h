#pragma once
#include<string>
#include<iomanip>
using namespace std;
class Encryption
{
	int multiple;
	string password;
public:
	Encryption()
	{
		multiple = 31;
		password = "";
	}
	string input(const string&);
	string converter(long long number);
};

