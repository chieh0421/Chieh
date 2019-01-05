/*
 Briefly explain the purpose and functionality of this file (program).
 @author Ming Chieh Chen
 @ID     B06505047
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/

#include <iostream>
using namespace std;

bool isMultiple(long n, long m)
{
	bool result;
	if (n%m == 0) //n=mi
		result = true;
	else          //n!=mi
		result = false;
	return result;
}

/*int main()
{
	if (isMultiple(6, -3))
		cout << "Y" << endl;
	else
		cout << "N" << endl;
	system("PAUSE");
	return 0;
}*/