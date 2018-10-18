/**
 * Briefly explain the function of this class.
 *
 * @author 			Ming Chieh Chen
 * @ID 				B06505047
 * @Department 		Engineering Science and Ocean Engineering
 * @Affiliation 	National Taiwan University
 *
 */

#ifndef LOCKDLISTNODE_H
#define LOCKDLISTNODE_H
#include "DListNode.h"
#include "DList.h"
template <typename T>
class LockDListNode :public DListNode<T> {
private:
	bool lock;
public:
	LockDListNode(const T& i, DListNode<T>* p, DListNode<T>* n) :DListNode<T>(i, p, n) {
		lock = false;
	}
	void lockon() { lock = true; }
	bool lockornot() { return(lock == true ? true : false); }
};


#endif // !LOCKDLISTNODE_H

