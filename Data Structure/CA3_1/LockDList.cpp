/**
 * Briefly explain the function of this class.
 *
 * @author 			Ming Chieh Chen
 * @ID 				B06505047
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 */
#include "LockDList.h"
#include "DListNode.h"
#include "LockDListNode.h"
#include "DList.h"

template <typename T>
void LockDList<T>::lockNode(DListNode<T>* node){
	LockDListNode<T>*Lnode = dynamic_cast<LockDListNode<T>*>(node);
	Lnode->lockon();
}

template <typename T>
DListNode<T>* LockDList<T>::newNode(const T& item, DListNode<T>* prev, DListNode<T>* next) {
	return new LockDListNode<T>(item, prev, next);
}

template <typename T>
void LockDList<T>::remove(DListNode<T>* node) {
	if(dynamic_cast<LockDListNode<T>*>(node)->lockornot())
		return;
	DList<T>::remove(node);
}