#include <iostream>
#include "tree.h"
#include <stdlib.h>
using namespace std;

Node::Node() {
	data = 0;
	left_ptr = NULL;
	right_ptr = NULL;
	parent = NULL;
}


Node::Node(int kk) {
	data = kk;
	left_ptr = NULL;
	right_ptr = NULL;
	parent = NULL;
}

Node::Node(Node * kk) {
	this->data = kk->data;
	this->left_ptr = kk->left_ptr;
	this->right_ptr = kk->right_ptr;
	parent = kk->parent;
}

/*
Node * Node::operator=(Node *p) {
	p = new Node();
	p->data = this->data;
	p->left_ptr = this->left_ptr;
	p->right_ptr = this->right_ptr;
	p->parent = this->parent;
	return p;
}
*/

Tree::Tree() {
	root = NULL;
	number_of_node = 0;
}

void Tree::AddNodeToTree(int data) {
	Node * _ptr = new Node();
	_ptr->data = data;
	if (root == NULL ) { 
		root = _ptr;
		_ptr->parent = root;}
	else addNode(_ptr,root);
	number_of_node++;
}

Node * Tree::findNode(const int data, Node * p) {
	if (p == NULL) return NULL;
	else if (p->data == data ) return p;
	else if (p->data <= data ) { 
		return findNode(data,p->right_ptr);
	}
	else {
		return findNode(data,p->left_ptr);
	}
}

void Tree::addNode (Node * _ptr, Node * leafNode){ 
	if ( leafNode->data <= _ptr->data ) {
		 if (leafNode->right_ptr == NULL ) {
			leafNode->right_ptr = _ptr;
			_ptr->parent = leafNode;
		}
		else addNode( _ptr, leafNode->right_ptr);
	}
	else {
                 if (leafNode->left_ptr == NULL ) {
                        leafNode->left_ptr = _ptr;
			_ptr->parent = leafNode;
		}
                else addNode( _ptr, leafNode->left_ptr);

	}

	return;
}

void Tree::preOrderTraversal(Node  * _ptr) {
	if (_ptr != NULL ) {
		if (_ptr->left_ptr != NULL ) this->preOrderTraversal(_ptr->left_ptr);
	 	cout << _ptr->data << "\n";
		if (_ptr->right_ptr != NULL ) this->preOrderTraversal(_ptr->right_ptr);
	}
	return;
}

void Tree::Tree2Array(Node *_ptr, Node * kk[]) {
	static unsigned int counter = 0; 
	if (counter < 20 ) {
		if (_ptr->left_ptr != NULL )  this->Tree2Array(_ptr->left_ptr, kk);
	 	kk[counter++] = _ptr;
		if (_ptr->right_ptr != NULL ) this->Tree2Array(_ptr->right_ptr, kk);
	}
	return;
}

int Tree::ITreeSize(Node *node)
{
	if(node == NULL) return 0;
	else
	    return ITreeSize(node->left_ptr) + 1 + ITreeSize(node->right_ptr);
}

int Tree::getLevel (const Node * leaf, const int& data, unsigned short level)
{
	if (leaf == NULL) return level;
	else if (leaf->data == data) return level;
	else if ( leaf->data < data) { return getLevel(leaf->left_ptr,data, level+1);}
	else if (leaf->data >= data) { return getLevel(leaf->right_ptr,data, level+1);}  
}

void Tree::deleteNode(const int data) {
	static int kk = 0;
	cout << "entering function delete node " << kk++ <<  "\n";
	Node *p = findNode(data, root);
	Node *temp_parent;

	if (p == NULL ) {
		cout << "no data with the fiven data, hence nothing can be deleted" ;
		return;
	}
	else {
		cout << "value of parent pointer" << p->parent << "\n";
 		if (p->parent->left_ptr == p) p->parent->left_ptr = NULL;
		else p->parent->right_ptr = NULL;	
	}

 	if (p->left_ptr != NULL) {
		this->addNode(p->left_ptr, p->parent);
	}
 	else if (p->right_ptr != NULL) {
		this->addNode(p->right_ptr, p->parent);
	}

	delete p;
}

unsigned int Tree::LeftTreeHight(Node * tnode) {
	if (tnode == NULL) return 0;
	else {
		return LeftTreeHight(tnode->left_ptr) + 1;
	}
}

unsigned int Tree::RightTreeHight(Node * tnode) {
	if (tnode == NULL) return 0;
	else {
		return RightTreeHight(tnode->right_ptr) + 1;
	}
}

bool Tree::IsTreeBalanced(Node * tnode) {
	if (tnode == NULL) return 1;
	unsigned int llength = LeftTreeHight(tnode);
	unsigned int rlength = RightTreeHight(tnode);
	int balDiff = rlength -  llength;

	if ( abs(balDiff) <= 1 && IsTreeBalanced(tnode->left_ptr) && IsTreeBalanced(tnode->right_ptr)) {
		return 1; 
	}
	return 0;
} 
		


unsigned int Tree::TreeHight(Node *tnode) {
	unsigned int llength = LeftTreeHight(tnode);
	unsigned int rlength = RightTreeHight(tnode);

	if (llength >= rlength)
 		return  llength;
	else return rlength;
}

void Tree::WreadthFirstPrint(Node * tnode, int length) {
	if (length == 1) {
		if (tnode != NULL) cout << tnode->data << "    ";
		return;
	}
	else {
		if ( tnode->left_ptr != NULL ) 
			WreadthFirstPrint( tnode->left_ptr, length - 1); 
		if ( tnode->right_ptr !=NULL ) 
			WreadthFirstPrint( tnode->right_ptr, length - 1); 
	}
}

void Tree::WreadthFirst() {
	Node * btree = this->getRoot();
	
	unsigned int length = this->TreeHight(btree);

	for (unsigned int counter = 1; counter <= length; counter ++) {
		cout << "level : " << counter  << "   ";
		WreadthFirstPrint( btree, counter);
		cout << "\n";
	}
}

void Tree::PerformTreeBalance() {
	int size = treeSize();
	Node * kk[size];

	Tree2Array(root, kk);
	
	for (int counter = 0 ; counter <= size ; counter++) {
		kk[counter]->left_ptr = NULL;
		kk[counter]->right_ptr = NULL;
	}

	int temp = (int) size/2; 
	root = kk[temp];

	TreeBalance(0,temp-1,kk);
	TreeBalance(temp+1,size,kk);
	return;
}
	
void Tree::TreeBalance(int first, int last, Node * kk[]) {
	if (first >= last) return;
	else {
		int temp = (int) (first + last)/2; 
		addNode(kk[temp],root);
		cout << "addNode done \n";
		TreeBalance(first,temp , kk);

		TreeBalance(temp+1, last,kk);
	}
}

void Tree::TreeMirror() {
	if (root == NULL) {
		cout << "No item in tree, no mirroring is performed \n";
	}
	else {
		TreeMirrorI(root);
	}
}

void Tree::TreeMirrorI(Node *tnode) {
	if (tnode == NULL) {
		return;
	}
	else {
		Node * temp;	
		temp = tnode->left_ptr;
		tnode->left_ptr = tnode->right_ptr;
		tnode->right_ptr = temp;
		TreeMirrorI(tnode->left_ptr);
		TreeMirrorI(tnode->right_ptr);
	}
}
	
void Tree::addNodeToMaxHeapTree(int data) {
	Node *temp = new Node(data);

	if (temp == NULL ) { cout << "system is out of memory, can not add any more node \n";
		exit(-1);
	}

	if (root == NULL ) {
		root = temp;
		return;
	}

	addNodeToLeaf(temp,root);
	return;
}

bool Tree::addNodeToLeaf(Node * temp, Node * leaf) {
		if ( leaf->left_ptr == NULL )  { 
			leaf->left_ptr = temp;
			leaf->left_ptr->parent = leaf; 
			//swap(leaf->left_ptr);
			return true;
		}
		else if ( leaf->right_ptr == NULL )  { 
			leaf->right_ptr = temp;
			leaf->right_ptr->parent = leaf;
			//swap(leaf->right_ptr);
			return true;
		} 
		else {
			addNodeToLeaf (temp, leaf->left_ptr);
			addNodeToLeaf(temp, leaf->right_ptr);
		}	
}

void Tree::swap(Node *_ptr) {
	if (_ptr->data > _ptr->parent->data) {
		int temp = _ptr->data;
		_ptr->data = _ptr->parent->data;
		_ptr->parent->data = temp; 
		swap (_ptr->parent);
	}
	return;
}
