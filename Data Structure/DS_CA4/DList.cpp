#include <iostream>
#include "DList.h"
#include "Entry.h"
using namespace std;

template<typename K,typename V>
DListNode<K,V>::DListNode(const Entry<K,V>& i, DListNode<K,V>* p, DListNode<K,V>* n) {
	item = i;
	prev = p;
	next = n;
}

template<typename K, typename V>
DListNode<K,V>* DList<K,V>::newNode(const Entry<K,V>& item,	DListNode<K,V>* prev, DListNode<K,V>* next) {
	return new DListNode<K,V>(item, prev, next);
}

template<typename K, typename V>
DList<K,V>::DList() {
	listsize = 0;
	DListNode<K,V>* sentinel = NULL;
	sentinel = newNode(NULL, sentinel, sentinel);
	sentinel->prev = sentinel;
	sentinel->next = sentinel;
	head = sentinel;
}

template<typename K, typename V>
bool DList<K, V>::isEmpty() {
	return listsize == 0;
}

template<typename K, typename V>
int DList<K, V>::length() {
	return listsize;
}

template<typename K, typename V>
void DList<K, V>::insertBack(const Entry<K, V>& item) {
	DListNode<K, V>* back = newNode(item, head->prev, head);
	head->prev->next = back;
	head->prev = back;
}

template<typename K, typename V>
Entry<K, V>* DList<K, V>::find(const K key) {
	DListNode<K, V>* now = head->next;
	do {
		if (now->item.getkey() != key)
			break;
		now = now.next;
	} while (now != head);
}