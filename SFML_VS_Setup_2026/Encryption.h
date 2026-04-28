#pragma once
#include<string>
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
	string converter(long long number);
	string decryption(string& pass);
};

