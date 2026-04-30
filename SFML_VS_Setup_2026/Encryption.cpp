#include "Encryption.h"
#include<sstream>
using namespace std;
string Encryption::converter(long long number)
{
	ostringstream stronger;
	stronger << hex << uppercase << setfill('0') << setw(16) << number;
	return stronger.str();
}
string Encryption::input(const string & pass)
{
	int max = pass.length();
	long long int final_int = 0;
	int assign = 0;
	while (assign < max)
	{
		char current = pass[assign];
		int number = (int)current;
		final_int = (final_int * multiple) + number;
		assign++;
	}
	string final = converter(final_int);
	return final;
}