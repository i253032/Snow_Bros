#include "Encryption.h"
#include<sstream>
using namespace std;
string Encryption::converter(long long number)
{
	ostringstream stronger;
	stronger << hex << uppercase << setfill('0') << setw(16) << number;
	return stronger.str();
}
long long int Encryption::input(string & pass)
{
	int max = pass.length();
	long long int final = 0;
	int assign = 0;
	while (assign < max)
	{
		char current = pass[assign];
		int number = (int)current;
		final = (final * multiple) + number;
		assign++;
	}
	return final;
}
//string Encryption::decryption(string & pass)
//{
//
//}
