#ifndef TREE_NODES_H
#define TREE_NODES_H

class Node {
	public:
		Node();
		Node(int);
		Node(Node *);
		//Node * operator=(Node *);
		int data;
		Node *left_ptr;
		Node *right_ptr;
		Node *parent;
}; 

class Tree {
	public:
		Tree();
		void AddNodeToTree(int);
		inline int treeSize() { return this->ITreeSize(root); }
		void PreOrder();
		int getLevel(const Node * leaf, const int& data, unsigned short level); 
		void deleteNode (const int data);
		Node * findNode(const int data, Node *);
		void Tree2Array (Node *, int kk[]);
		//void Post();
	//	void InOrder();
		inline void RightTraverse() { this->preOrderTraversal(root) ;}
		inline int getNumberOdNode() { return number_of_node; }
		inline Node * getRoot() const { return root ;} 
		unsigned int LeftTreeHight(Node *);
		unsigned int RightTreeHight(Node *);
		unsigned int TreeHight(Node *);
		void WreadthFirst();
		void WreadthFirstPrint(Node *, int);
		int IsTreeBalanced();

	private:
		Node *root;
		void preOrderTraversal(Node * _ptr);
		int ITreeSize(Node *);
		void addNode (Node * _ptr, Node * _leafNode );
		unsigned int number_of_node;
};

/*
void add_node_to_tree (NODE *_ptr, NODE **_tptr);
void delete_node_from_tree (INT_NODE *, int);
void traverse_tree( NODE *_ptr );

void add_intnode_to_tree (INT_NODE *_ptr, INT_NODE **_tptr);
void int_traverse_tree( INT_NODE *_ptr );
void find_node(INT_NODE * root, int data, INT_NODE  ** containing_node);
*/

#endif
