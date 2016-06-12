#include <iostream>
#include "tree.h"
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

/*
void Tree::addNode (Node * _ptr) {
	if (*_tptr != NULL ) {
		kk = strcmp ((*_tptr)->data, _ptr->data);
		if (kk > 0) {add_node_to_tree (_ptr, &(*_tptr)->right_ptr);}
		else {add_node_to_tree (_ptr, &(*_tptr)->left_ptr);}
	}
	else {
		*_tptr = _ptr;
		printf ("adding node to tree %s\n", (*_tptr)->data);
	}

	return;
}
*/

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

void Tree::Tree2Array(Node *_ptr, int kk[]) {
	static unsigned int counter = 0; 
	if (_ptr != NULL ) {
		if (_ptr->left_ptr != NULL )  this->Tree2Array(_ptr->left_ptr, kk);
	 	kk[counter++] = _ptr->data;
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
	

/*
void Tree<DType>::RightTraverse() {
	if (_ptr != NULL ) {
		traverse_tree(_ptr->right_ptr);
		traverse_tree(_ptr->left_ptr);
	 	cout << _ptr->data << "\n";
	}
	return;
}

void Tree <DType>::find_node(Node <DType> *start_ptr, DType data, Node <DType> ** containing_node) {
	if ( start_ptr == NULL ) { return; } 
	else if (start_ptr->data == data) { *containing_node = start_ptr; return; }
	else { find_node(start_ptr->left_ptr, data, &(*containing_node));
		find_node(start_ptr->right_ptr,data, &(*containing_node));
		return;
	}
}	 

void delete_node_from_tree (INT_NODE * root, int data){
	INT_NODE * containing_node = NULL;
        find_node(root, data, &containing_node);
	if ( containing_node != NULL ) {
		if (containing_node != root ) {
			add_intnode_to_tree(containing_node->right_ptr, &root);
			add_intnode_to_tree(containing_node->left_ptr, &root);
			free(containing_node);
		}
	}
	return;
}
*/ 
