#include "BinaryTree.h"
using namespace std;

template<typename K, typename V>
BinaryTree<K, V>::BinaryTree() {
  makeEmpty();
}

/**
 *  Returns the number of entries stored in the dictionary.  Entries with
 *  the same key (or even the same key and value) each still count as
 *  a separate entry.
 *  @return number of entries in the dictionary.
 **/
template<typename K, typename V>
int BinaryTree<K, V>::size() {
  return tsize;
}

/**
 *  Tests if the dictionary is empty.
 *
 *  @return true if the dictionary has no entries; false otherwise.
 **/
template<typename K, typename V>
bool BinaryTree<K, V>::isEmpty() {
  return size() == 0;
}

template<typename K, typename V>
void BinaryTree<K, V>::insertHelper(Entry<K, V>* entry, const K& key, BinaryTreeNode<K, V>* node) {
  if (key.compareTo(node->entry->getkey()) <= 0) {
    if (node->leftChild == NULL) {
      node->leftChild = new BinaryTreeNode<K, V>(entry, node);
    } else {
      insertHelper(entry, key, node->leftChild);
    }
  } else {
    if (node->rightChild == NULL) {
      node->rightChild = new BinaryTreeNode<K, V>(entry, node);
    } else {
      insertHelper(entry, key, node->rightChild);
    }
  }
}

/**
 *  Create a new Entry object referencing the input key and associated value,
 *  and insert the entry into the dictionary.
 *  Multiple entries with the same key (or even the same key and
 *  value) can coexist in the dictionary.
 *
 *  @param key the key by which the entry can be retrieved.
 *  @param value an arbitrary object.
 **/
template<typename K, typename V>
void BinaryTree<K, V>::insert(const K& key, const V& value) {
  Entry<K, V>* entry = new Entry<K, V>(key, value);
  if (root == NULL) {
    root = new BinaryTreeNode<K, V>(entry);
  } else {
    insertHelper(entry, key, root);
  }
  tsize++;
}

/**
 *  Search for a node with the specified key, starting from "node".  If a
 *  matching key is found (meaning that key1.compareTo(key2) == 0), return
 *  a node containing that key.  Otherwise, return null.
 *
 *  Be sure this method returns null if node == null.
 **/
template<typename K, typename V>
BinaryTreeNode<K, V>* BinaryTree<K, V>::findHelper(const K& key, BinaryTreeNode<K, V>* node) {
  // Replace the following line with your solution.
	if (node == NULL)
		return NULL;
	else
	{
		if (key.compareTo(node->entry->getkey()) == 0) {
			return node;
		}
		else if (key.compareTo(node->entry->getkey()) < 0) {
			if (node->leftChild == NULL) {
				return NULL;
			}
			else {
				findHelper(key, node->leftChild);
			}
		}
		else {
			if (node->rightChild == NULL) {
				return NULL;
			}
			else {
				findHelper(key, node->rightChild);
			}
		}
	}
}

/**
 *  Search for an entry with the specified key.  If such an entry is found,
 *  return true; otherwise return false.
 *
 *  @param key the search key.
 *  @return an entry containing the key and an associated value, or null if
 *          no entry contains the specified key.
 **/
template<typename K, typename V>
Entry<K, V>* BinaryTree<K, V>::find(const K& key) {
  BinaryTreeNode<K, V>* node = findHelper(key, root);
  if (node != NULL) {
    return node->entry;
  } else {
    return NULL;
  }
}

/**
 *  Remove an entry with the specified key.  If such an entry is found,
 *  remove it from the table.
 *  If several entries have the specified key, choose one arbitrarily, then
 *  remove it.
 *
 *  @param key the search key.
 */
template<typename K, typename V>
void BinaryTree<K, V>::remove(const K& key) {
  // Your solution here.
	BinaryTreeNode<K, V>* node = findHelper(key, root);
	if (node == NULL)
		return;
	bool left, right, root_ornot, LorR; //LorR mean the node is parent's leftchild(0) or rightchild(1)
	left = !(node->leftChild == NULL);
	right = !(node->rightChild == NULL);
	root_ornot = (node == root);
	if (!root_ornot) {
		if (key.compareTo(node->parent->entry->getkey())<=0)
			LorR = false;
		else
			LorR = true;
	}
	if (left == false && right == false) { //nochild
		if (root_ornot) {
			root = NULL;
			delete node;
		}
		else {
			if (LorR){
				node->parent->rightChild = NULL;
				delete node;
			}
			else {
				node->parent->leftChild = NULL;
				delete node;
			}
		}
	}
	else if(left == true && right == false) {//one child(left)
		if (root_ornot) {
			root = node->leftChild;
			node->leftChild->parent = NULL;
			delete node;
		}
		else {
			if (LorR) {
				node->parent->rightChild = node->leftChild;
				node->leftChild->parent = node->parent;
				delete node;
			}
			else {
				node->parent->leftChild = node->leftChild;
				node->leftChild->parent = node->parent;
				delete node;
			}
		}
	}
	else if (left == false && right == true) {//one child(right)
		if (root_ornot) {
			root = node->rightChild;
			node->rightChild->parent = NULL;
			delete node;
		}
		else {
			if (LorR) {
				node->parent->rightChild = node->rightChild;
				node->rightChild->parent = node->parent;
				delete node;
			}
			else {
				node->parent->leftChild = node->rightChild;
				node->rightChild->parent = node->parent;
				delete node;
			}
		}
	}
	else {//two children
		BinaryTreeNode<K, V>* subNode = node->rightChild;
		while (subNode->leftChild != NULL)
			subNode = subNode->leftChild;

		if (subNode->parent == node) {
			if (node == root) {
				root = subNode;
			}
			else {
				if (LorR) {
					node->parent->rightChild = subNode;
				}
				else {
					node->parent->leftChild = subNode;
				}
				subNode->parent = node->parent;
			}
			subNode->leftChild = node->leftChild;
			if (node->leftChild != NULL)
				node->leftChild->parent = subNode;
		}
		else {
			subNode->parent->leftChild = subNode->rightChild;
			if (subNode->rightChild != NULL)
				subNode->rightChild->parent=subNode->parent;
			if (node == root) {
				root = subNode;
			}
			else {
				if (LorR) {
					node->parent->rightChild = subNode;
				}
				else {
					node->parent->leftChild = subNode;
				}
				subNode->parent = node->parent;
			}
			subNode->leftChild = node->leftChild;
			subNode->rightChild = node->rightChild;
			if (node->leftChild != NULL)
				node->leftChild->parent = subNode;
			if (node->rightChild != NULL)
				node->rightChild->parent = subNode;
		}
		delete node;
	}
	tsize--;
}

/**
 *  Remove all entries from the dictionary.
 */
template<typename K, typename V>
void BinaryTree<K, V>::makeEmpty() {
  // Your solution here.
	while (tsize != 0) {
		remove(root->entry->getkey());
	}
}

/**
 *  Convert the tree into a string.
 **/
template<typename K, typename V>
std::string BinaryTree<K, V>::toString() {
  if (root == NULL) {
    return "";
  } else {
    return root->toString();
  }
}
