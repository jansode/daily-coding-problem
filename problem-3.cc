#include <iostream>
#include <string>
#include <vector>

// Problem:
// Given the root to a binary tree, implement serialize(root), 
// which serializes the tree into a string, and deserialize(s), 
// which deserializes the string back into the tree.

// For example, given the following Node class
//
// class Node:
// 		def __init__(self, val, left=None, right=None):
//			self.val = val
//			self.left = left
//			self.right = right
//
// The following test should pass:
//
// node = Node('root', Node('left', Node('left.left')), Node('right'))
// assert deserialize(serialize(node)).left.left.val == 'left.left'



// Solution:
// My idea for this one is to store the serialization as 
// a string in the following format:
//
// A node is represented by opening and closing brackets.
// The value of the node and its children are separated by
// commas (left,value,right). This idea is then applied 
// recursively where the '-' character marks a non-existing
// child node. 
//
//        (5)	
//       /   \
//     (3)   (4)
//    /     /   \
//  (1)   (10)  (12)
//
//
// This binary tree above would be converted to the string:
// (((-,1,-),3,-),5,((-,10,-),4,(-,12,-)))

struct Node
{
	Node *left;
	Node *right;
	int value;

	Node(int v):value(v),left(nullptr),right(nullptr){}
};

void traverse_in_order(Node *curr, std::string *s)
{
	if(curr == nullptr) 
	{
		s->append("-");
		return;
	}

	s->append("(");
	traverse_in_order(curr->left,s);
	s->append(std::string("," + curr->value + ","));
	traverse_in_order(curr->right,s);
	s->append(")");
}

std::string serialize(Node *root)
{	
	std::string serialized;
	traverse_in_order(root,&serialized);
	return serialized;
}


Node *deserialize(std::string encoding)
{
	return nullptr;
}

int main()
{
	Node root(5), left(2), right(1);	

	Node right2(10);

	right.right = &right2;

	root.left = &left;
	root.right = &right;
	std::string s = serialize(&root);
	std::cout<<s;	
	return 0;
}
