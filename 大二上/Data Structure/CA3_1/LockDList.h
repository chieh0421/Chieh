/**
 * Briefly explain the function of this class.
 *
 * @author 			Ming Chieh Chen
 * @ID 				B06505047
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 */

#ifndef LOCKDLIST_H
#define LOCKDLIST_H
#include "DList.h"
#include "LockDListNode.h"

template <typename T>
class LockDList: public DList<T> {
public:
	void lockNode(DListNode<T>* node);
	DListNode<T>* newNode(const T& item, DListNode<T>* prev, DListNode<T>* next);
	void remove(DListNode<T>* node);
	LockDList() { DList<T>(); }
};

#endif // !LOCKDLIST_H
