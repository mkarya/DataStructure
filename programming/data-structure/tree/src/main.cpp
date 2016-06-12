#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

//string * tree_item[10] = {"mukesh","syama","rama","hanuman","siva","mansal", "ramjidas","ravi", "kabir","todo"};
int int_tree_item[10] = {10,2,3,11,-3,-9,20,21,20,12};

void check_find_function(Tree *);
void check_tree2array_function(Tree *);

main ()
{
	Tree  * btree = new Tree();
	Node kk(10),ll;
	ll = kk;

	cout << ll.data << "\n";

	for(unsigned short int counter=0;counter<10;counter++) {
		btree->AddNodeToTree(int_tree_item[counter]);
	}

	
	check_find_function(btree);
	btree->RightTraverse();
	cout << btree->treeSize() << "\n";
	cout << "level of element 21 is " << btree->getLevel(btree->getRoot(), 21, 0) << "\n";
	Node * p = btree->findNode(20,btree->getRoot());
	if (p != NULL ) cout << "found node " << p->data << "\n";
	btree->deleteNode(11);
	btree->RightTraverse();
	cout << "tree size after deletion " << btree->treeSize() << "\n";
	check_tree2array_function(btree);
	
	
}

void check_find_function (Tree * tree) {
	for (unsigned short i = 0; i < 10 ; i++){
		Node *temp = tree->findNode(int_tree_item[i], tree->getRoot());
		if (temp != NULL) cout << "element " << int_tree_item[i] << " found at pointer" << temp << "\n";
		else cout << "element " << int_tree_item[i] << " not found \n";
	}
	return;
}

void check_tree2array_function(Tree *tree) {
	int kk[10];
	tree->Tree2Array(tree->getRoot(), kk);
	for (unsigned short i = 0; i < 10 ; i++){
		cout << "element " << kk[i] << "  \n";
	}
	return;
}
