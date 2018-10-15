/*
 Briefly explain the purpose and functionality of this file (program).
 @author Ming Chieh Chen
 @ID     B06505047
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/

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

int* showPrime(int p)
{
	static int result[] = { 0,0 };
	if (isPrime(p)) //p is prime
	{
		result[0] = p;
		return result;
	}
	else //p not a prime
	{
		int ps=p, pl=p;
		do //find nearst prime smaller than p
		{
			ps--;
		} while (!isPrime(ps));
		do //find nearst prime larger than p 
		{
			pl++;
		} while (!isPrime(pl));
		result[0] = ps;
		result[1] = pl;
	}
	return result;
}

/*int main()
{
	int p,*ans;
	cin >> p;
	ans = showPrime(p);
	cout << ans[0] << " ," << ans[1] << endl;
	system("PAUSE");
	return 0;
}*/