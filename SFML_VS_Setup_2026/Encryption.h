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
	long long int input(string&);
	string converter(long long number);
	string decryption(string& pass);
};

