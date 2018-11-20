#include "Entry.h"

template<typename K,typename V>
class DListNode {
public:
	Entry<K,V> item;
	DListNode(const Entry<K,V>& i, DListNode<K, V>* p, DListNode<K, V>* n);
	DListNode<K,V>* prev;
	DListNode<K,V>* next;
};

template<typename K,typename V>
class DList {

private:
	DListNode<K,V>* head;
	int listsize;
	DListNode<K,V>* newNode(const Entry<K,V>& item, DListNode<K,V>* prev, DListNode<K,V>* next);

public:
	DList();
	bool isEmpty();
	int length();
	void insertBack(const Entry<K,V>& item);
	Entry<K,V>* find(const K key);
};