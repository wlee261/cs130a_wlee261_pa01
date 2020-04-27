// BST.h
// Winston Lee

#ifndef BST_H
#define BST_H

#include <iostream>
#include <string>

using namespace std;

class Node{

public:

	Node(string word, Node *l = NULL, Node *r = NULL, Node *p = NULL);
	~Node() { delete left; delete right; }
	Node *left, *right, *parent;
	pair<string,int>data;

};
class BST{

public:

	Node *root;

	BST() : root(nullptr){ }
	~BST() { delete root; }

	Node* search(string word);
	Node* search(string word, Node *n);

	Node* insert(string word);
	Node* insert(string word, Node *n); //helper

	Node* remove(string word);
	Node* remove(string word, Node *t);

	/*bool rangeSearch(string word1, string word2);
	bool rangeSearch(string word1, string word2, Node* n);*/

};
#endif