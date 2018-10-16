#include "LockDList.h"
#include "DListNode.h"
#include "LockDListNode.h"

template <typename T>
void LockDList<T>::lockNode(LockDListNode<T>* node){
	lock = true;
}