#include "Entry.h"

template<typename K, typename V>
class SListNode {
public:
	Entry item;
	SListNode* next;
	SListNode(Entry newitem, SListNode* nextnode) {
		item = newitem;
		next = nextnode;
	}
};

template<typename K, typename V>
class SList {
private:
	SListNode* head;
	int listsize;
public:
	SList() {
		head = NULL;
		listsize = 0;
	}
	insertback(Entry newitem){
		if listsize == 0
			head = new SListNode(newitem, NULL);
		else {
			SListNode* now = head;
			do {
				now = now.next;
			} while (now != NULL);
			now = new SListNode(newitem, NULL);
		}
	}

};
