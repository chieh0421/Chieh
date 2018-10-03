/*
 Briefly explain the purpose and functionality of this file (program).
 @author Ming Chieh Chen
 @ID     B06505047
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/

#include <iostream>
using namespace std;
int dotProduct(int a[],int b[],int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		result += a[i] * b[i];//矩陣元素相乘，並加入結果中
	}
	return result;
}

int main() {
	int a[] = { -1,0,2,15,7,6,-4,8,21,-13 }; 
	int b[] = { 5,9,-18,16,0,1,-4,18,-2,12 };
	int n;
	if (sizeof(a) >= sizeof(b))
		n = sizeof(b)/sizeof(int);
	else
		n = sizeof(a)/sizeof(int);
	cout << dotProduct(a, b, n) << endl;
	system("PAUSE");
	return 0;
}