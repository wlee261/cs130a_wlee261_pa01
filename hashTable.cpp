//hashTable.cpp
//Winston Lee

#include <iostream>
#include <utility>
#include "hashTable.h"

Node::Node(string word, int key, Node* n){
    data.first = word;
    data.second = 1;
    key = 0;
    next = n;
}



Node* BST::search(string word){
	return(table[hashFunction(word)]);
    
}

Node* hashTable::insert(string word){
	int index = hashFunction(word);
	if(table[index] == NULL){
		table[index]->data.first = word;
		table[index]->data.second = 1;
	}
	
	else
		table[index]->data.second++;
}


Node* BST::remove(string word) {
    int index = hashFunction(word);
    if(table[index]->data.second > 1)
    	table[index]->data.second--;
    else
    	table[index] == NULL;
    
}

vector<string> rangeSearch(string word1, string word2, Node* n){
	int difference = word2[1] - word1[1];
	vector<string> list;
	for(i = word1[1]; i < word2[1]; i++){
		list.push_back(table[hashFunction(i)])
	}
	return list;
    
}