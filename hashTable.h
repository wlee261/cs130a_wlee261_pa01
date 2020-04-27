// hashTable.h
// Winston Lee

#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <iostream>
#include <string>
#include <lists>
using namespace std;

class hashTable{

	int BUCKET;
	list<int> *table;
public:
	hashTable(int V);
	Node* insert(int x);
	Node* remove(int key);
	Node* search(string searchFor);
	Node* rangeSearch(string word1, string word2);
	int hashFunction(string input){return (input[1]+input[3])/2 + input[2]}



};
class Node{
	Node(string word, Node* n = NULL);
	~Node() { delete next; }
	Node *next;
	int key;
	pair<string,int>data;
}
#endif