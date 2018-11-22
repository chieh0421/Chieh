#include <stdlib.h>
#include <time.h>
#include "Integer.h"
#include "HashTableChained.h"
#include "CheckerBoard.h"
#include "HashTableChained.cpp"

int main() {
	//Test all method in HashTableChained
	HashTableChained<Integer, int>* Table = new HashTableChained<Integer, int>;

	int i; //Test insert() and print()
	for (i = 0; i < 97; i++) {
		Integer in(i);
		Table->insert(in,i);
	}
	Table->print();

	cout << "There are " << Table->size() << " entries in the table" << endl; //Test size()	

	Integer f(50); //Test find()
	if (Table->find(f))
		cout << "The entry whose key is 50 can be found." << endl;
	else
		cout << "The entry whose key is 50 can't be found." << endl;

	Table->remove(f); //Test remove()
	if (Table->find(f))
		cout << "The entry whose key is 50 still exists." << endl;
	else
		cout << "The entry whose key is 50 has been removed." << endl;

	if (Table->isEmpty()) //Test isEmpty()
		cout << "Table is empty." << endl;
	else
		cout << "Table is not empty." << endl;

	Table->makeEmpty(); //Test makeEmpty()
	Table->print();
	if (Table->isEmpty())
		cout << "Table is empty." << endl;
	else
		cout << "Table is not empty." << endl;
	
	
	system("PAUSE");
}