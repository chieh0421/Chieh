/**
 *  HashTableChained extends a Dictionary as a hash table with chaining.
 *  All objects used as keys must have a valid hashCode() method, which is
 *  used to determine which bucket of the hash table an entry is stored in.
 *  Each object's hashCode() is presumed to return an int between
 *  Integer.MIN_VALUE and Integer.MAX_VALUE.  The HashTableChained class
 *  implements only the compression function, which maps the hash code to
 *  a bucket in the table's range.
 *
 **/

#include "HashTableChained.h"
#include <list>
#include "Double.h"
#include "String.h"
#include "Integer.h"
#include "CheckerBoard.h"
#include <iostream>
using namespace std;

/**
 *  Construct a new empty hash table intended to hold roughly sizeEstimate
 *  entries.  (The precise number of buckets is up to you, but we recommend
 *  you use a prime number, and shoot for a load factor between 0.5 and 1.)
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained(int sizeEstimate) {
    // Your solution here.
	int tablelength = sizeEstimate;
	for (int i = 2; i < tablelength; i++) {
		if (tablelength%i == 0) {
				tablelength--;
				i = 1;
				continue;
		}
	}
	hashtable = new list<Entry<K, V>>[tablelength];
	length = tablelength;
}

/**
 *  Construct a new empty hash table with a default size.  Say, a prime in
 *  the neighborhood of 100.
 **/
template<typename K, typename V>
HashTableChained<K, V>::HashTableChained() {
    // Your solution here.
	hashtable = new list<Entry<K, V>>[97];
	length = 97;
}

/**
 *  Converts a hash code in the range Integer.MIN_VALUE...Integer.MAX_VALUE
 *  to a value in the range 0...(size of hash table) - 1.
 *
 *  This function should have package protection (so we can test it), and
 *  should be used by insert, find, and remove.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::compFunction(int code) {
    // Replace the following line with your solution.
	int value;
	value = (int)abs(((code * 57 + 86) % 233) % length);
	return value;
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int HashTableChained<K, V>::size() {
    // Replace the following line with your solution.
    return entryNumber;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::isEmpty() {
    // Replace the following line with your solution.
	return entryNumber == 0 ? true : false;
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void HashTableChained<K, V>::insert(const K& key, const V& value) {
    // Replace the following line with your solution.
	Entry<K, V> item(key, value);
	K keyin = key;
	int hash = keyin->hashCode();
	int pos = compFunction(hash);
	list<Entry<K, V>>* here = &hashtable[pos];
	here->push_back(item);
	entryNumber++;
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 *  @return true if an entry containing the key is found, or false if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
bool HashTableChained<K, V>::find(const K& key) {
    // Replace the following line with your solution.
	K keyin = key;
	int hash = keyin->hashCode();
	int pos = compFunction(hash);
	list<Entry<K, V>>* here = &hashtable[pos];
	for (auto it = here->begin(); it != here->end(); ++it) {
		if (it->getkey()->equals(*key)) {
			return true;
		}
	}
    return false;
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  This method should run in O(1) time if the number of collisions is small.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void HashTableChained<K, V>::remove(const K&  key) {
    // Replace the following line with your solution.
	K keyin = key;
	int hash = keyin->hashCode();
	int pos = compFunction(hash);
	list<Entry<K, V>>* here = &hashtable[pos];
	for (auto it = here->begin(); it != here->end(); ++it) {
		if (it->getkey()->equals(*key)){
			here->erase(it);
			entryNumber--;
			return;
		}
	}
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void HashTableChained<K, V>::makeEmpty() {
    // Your solution here.
	int i;
	for (i = 0; i < length; i++) {
		list<Entry<K, V>>*here = &hashtable[i];
		here->clear();
		}
	entryNumber = 0;
}

template<typename K, typename V>
void HashTableChained<K, V>::print() {
	int i;
	for (i = 0; i < length; i++) {
		list<Entry<K, V>>*here = &hashtable[i];
		cout << "hashtable[" << i << "] : ";
		if (here->size() == 0) {
			cout << "nothing" << endl;
			continue;
		}			
		for (auto it = here->begin(); it != here->end(); ++it) {
			cout << "(" << it->getkey()->getvalue() << "," << it->getvalue() << ") ";
		}
		cout << endl;
	}
	cout << "print complete" << endl;
}