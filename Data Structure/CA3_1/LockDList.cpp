#include "LockDList.h"
#include "DListNode.h"
#include "LockDListNode.h"

template <typename T>
void LockDList<T>::lockNode(DListNode<T>* node){
	static_cast<LockDListNode<T>*>(node)->Lockon();
}