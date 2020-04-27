//prog1.cpp
//Winston Lee

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include "BST.h"
#include "hashTable.h"

int main(){
	string word;
	ifstream wordList;
	BST tree;
	hashTable table;
	Node* root = NULL;

	wordList.open("dataset.txt");
	while (wordList >> word){
		tree.insert(word);
		table.insert(word);
	}

	string single;
	int counter = 0;
	vector<string> singleCommand;
	vector<string> commands;
	stringstream s_stream(my_str);
	while(s_stream.good()){
		string substr;
		getline(s_stream, substr, ',');
		commands.push_back(substr);
	}
	for(int i = commands.size(); i > 0; i--){
		for(auto x : commands[i]){
			if(x = ' '){
				singleCommand[counter] = single;
				single = "";
				counter++;
			}
			else{
				single = single + x;
			}

		}
		singleCommand[counter] = single;
		if(singleCommand[0] == "search"){
			cout << singlecommand[1] <<" found, count = "<<tree.search(singlecommand[1])->data.second;
			cout << singlecommand[1] <<" found, count = "<<table.search(singlecommand[1])->data.second;
		}
		else if(singleCommand[0] == "insert"){
			cout << singlecommand[1] <<" inserted, new count = "<<tree.insert(singlecommand[1])->data.second;
			cout << singlecommand[1] <<" inserted, new count = "<<table.insert(singlecommand[1])->data.second;
		}
		else if(singleCommand[0] == "delete"){
			if(tree.remove(singecommand[1]) == NULL)
				cout << singlecommand[1] <<" deleted";
			cout << singlecommand[1] <<" deleted, new count = "<<tree.remove(singlecommand[1])->data.second;
			if(table.remove(singecommand[1]) == NULL)
				cout << singlecommand[1] <<" deleted";
			cout << singlecommand[1] <<" deleted, new count = "<<table.remove(singlecommand[1])->data.second;
		}
		else if(singleCommand[0] == "range"){
			cout << tree.bandSearch(singleCommand[2], singleCommand[4]);
			cout << table.bandSearch(singleCommand[2], singleCommand[4]);
		}
	}
	

}
