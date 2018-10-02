#include <iostream>
using namespace std;
int dotProduct(int a[],int b[],int n)
{
	int result = 0;
	return result;
}

int main() {
	int a[] = { -1,0,2,15,7,6,-4,8,21,-13 }; 
	int b[] = { 5,9,-18,16,0,1,-4,18,-2,12 };
	int c[5];
	int n;
	if (sizeof(a) >= sizeof(b))
		n = sizeof(a)/sizeof(int);
	else
		n = sizeof(b)/sizeof(int);
	cout << dotProduct(a, b, n) << endl;
	system("PAUSE");
	return 0;
}