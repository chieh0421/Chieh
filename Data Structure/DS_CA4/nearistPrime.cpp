#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int p)  //whether p is prime or not
{
	int i;
	bool TorF;
	for (i = 2; i < p; i++)
	{
		if (p%i == 0)
		{
			TorF = false;
			return TorF;
		}
	}
	TorF = true;
	return TorF;
}

int nearistPrime(int p)
{
	int ps;
	if (isPrime(p)) //p is prime
	{
		return p;
	}
	else //p not a prime
	{
		do //find nearist prime smaller than p
		{
			ps--;
		} while (!isPrime(ps));
	}
	return ps;
}
