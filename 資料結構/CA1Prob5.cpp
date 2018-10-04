/*
 Briefly explain the purpose and functionality of this file (program).
 @author Ming Chieh Chen
 @ID     B06505047
 @Department Engineering Science and Ocean Engineering
 @Affiliation National Taiwan University
*/

#include <iostream>
using namespace std;

class rectangle
{
private:
	double width;
	double length;
	double perimeter;
	double area;
public:
	rectangle(double wd, double lg)//Constructor, automatically compute the perimeter and area once it is OK.
	{
		width = wd; length = lg; perimeter = 2 * (wd + lg); area = wd * lg;
	}
	void setDimension(double wd, double lg)//Set the dimension and automatically update the perimeter and area.
	{
		width = wd; length = lg; perimeter = 2 * (wd + lg); area = wd * lg;
	}
	void setWidth(double wd)//Set the width and automatically update the perimeter and area.
	{
		width = wd; perimeter = 2 * (wd + length); area = wd * length;
	}
	void setLength(double lg)//Set the length and automatically update the perimeter and area.
	{
		length = lg; perimeter = 2 * (width + lg); area = width * lg;
	}
	double getWidth()//Return the width of the rectangle.
	{
		return width;
	}
	double getLength()//Return the length of the rectangle.
	{
		return length;
	}
	double getPerimeter()//Return the perimeter of the rectangle.
	{
		return perimeter;
	}
	double getArea()//Return the area of the rectangle.
	{
		return area;
	}
	bool isSquare()//True,if width = length.
	{
		if (length == width)
			return true;
		else
			return false;
	}
};

/*int main()
{
	rectangle a(3, 5);
	cout << a.getPerimeter() << " " << a.getArea() << " " << a.getLength() << " " << a.getWidth() << endl;
	a.setDimension(5, 9);
	cout << a.getPerimeter() << " " << a.getArea() << " " << a.getLength() << " " << a.getWidth() << endl;
	a.setLength(4);
	cout << a.getPerimeter() << " " << a.getArea() << " " << a.getLength() << " " << a.getWidth() << endl;
	a.setWidth(4);
	cout << a.getPerimeter() << " " << a.getArea() << " " << a.getLength() << " " << a.getWidth() << endl;
	if (a.isSquare())
		cout << "Y" << endl;
	else
		cout << "N" << endl;
	system("PAUSE");
	return 0;
}*/