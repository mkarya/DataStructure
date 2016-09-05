#include <iostream>
#include <string>
#include "tree.h"
using namespace std;

//string * tree_item[10] = {"mukesh","syama","rama","hanuman","siva","mansal", "ramjidas","ravi", "kabir","todo"};
int int_tree_item[10] = {10,2,3,11,-3,-9,20,21,20,12};
int int_tree_item1[10] = {11,4,100,200,-30,-19,201,211,202,123};

void check_find_function(Tree *);
//void check_tree2array_function(Tree *);

main ()
{
	Tree  * btree = new Tree();
	Node kk(10),ll;
	ll = kk;

	cout << ll.data << "\n";

	for(unsigned short int counter=0;counter<10;counter++) {
		btree->AddNodeToTree(int_tree_item[counter]);
	}

	for(unsigned short int counter=0;counter<10;counter++) {
		btree->AddNodeToTree(int_tree_item1[counter]);
	}

	
	check_find_function(btree);
	btree->RightTraverse();
	cout << btree->treeSize() << "\n";
	cout << "Tree Hight :" << btree->TreeHight( btree->getRoot()) << "\n";

	//btree->WreadthFirst();

	//cout << "Tree balace factor :" << btree->IsTreeBalanced(btree->getRoot()) << "\n";
	btree->PerformTreeBalance();
	cout << "Tree balace factor :" << btree->IsTreeBalanced(btree->getRoot()) << "\n";
}

void check_find_function (Tree * tree) {
	for (unsigned short i = 0; i < 10 ; i++){
		Node *temp = tree->findNode(int_tree_item[i], tree->getRoot());
		if (temp != NULL) cout << "element " << int_tree_item[i] << " found at pointer" << temp << "\n";
		else cout << "element " << int_tree_item[i] << " not found \n";
	}
	return;
}

/*
void check_tree2array_function(Tree *tree) {
	int kk[10];
	tree->Tree2Array(tree->getRoot(), kk);
	for (unsigned short i = 0; i < 10 ; i++){
		cout << "element " << kk[i] << "  \n";
	}
	return;
}
*/
