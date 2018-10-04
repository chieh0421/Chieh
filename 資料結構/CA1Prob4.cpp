/*
 Briefly explain the purpose and functionality of this file (program).
 @author Ming Chieh Chen
 @ID     B06505047
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/

#include <iostream>
#include <sstream>
using namespace std;

class flower
{
private:
	string name;
	int petal;
	double price;
public:
	flower(string n, int pt, double pr)//Constructor.
	{
		name = n; petal = pt; price = pr;
	}
	void setName(string n)//Set the name of flower.
	{
		name = n;
	}
	void setPetal(int pt)//Set the petal number of flower.
	{
		petal = pt;
	}
	void setPrice(double pr)//Set the price of the flower.
	{
		price = pr;
	}
	string getName()//Return the name of the flower.
	{
		return name;
	}
	int getPetal()//Return the petal number of the flower.
	{
		return petal;
	}
	double getPrice()//Return the price of the flower.
	{
		return price;
	}
};

/*int main()
{
	flower a("Bluebell", 6, 85.0);
	cout << a.getName() << " " << a.getPetal() << " " << a.getPrice() << " " << endl;
	a.setName("A");
	a.setPetal(3);
	a.setPrice(1.0);
	cout << a.getName() << " " << a.getPetal() << " " << a.getPrice() << " " << endl;
	system("PAUSE");
	return 0;
}*/