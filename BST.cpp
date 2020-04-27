//BST.cpp
//Winston Lee

#include <iostream>
#include <utility>
#include "BST.h"

Node::Node(string word, Node* l, Node* r, Node* p){
    data.first = word;
    data.second = 1;
    left = l;
    right = r;
    parent = p;
}

Node* BST::search(string word){
    return search(word, root);
}

Node* BST::search(string word, Node* n){
    while(n){
        if (word == n->data.first)
            return n;
        else if (n->data.first < word)
            return search(word, n->right);
        else 
            return search(word, n->left);
    }
    return 0;
}

Node* BST::insert(string word){
    if (!root){
        root = new Node(word);
        return root;
    }
    return insert(word, root);
}

Node* BST::insert(string word, Node *n){
    if (word == n->data.first)
        n->data.second++;
    if (word < n->data.first){
        if (n->left){
            return insert(word, n->left);
        }
        else{
            n->left = new Node(word);
            n->left->parent = n;
            return n->left;
        }
    } else{
        if (n->right){
            return insert(word, n->right);
        }
        else{
            n->right = new Node(word);
            n->right->parent = n;
            return n->right;
        }
    }
}



Node* BST::remove(string word) {
    Node* t = search(word);
    return remove(word, t);
}

Node* BST::remove(string word, Node* t){
    Node* temp;
    if(t == NULL)
        return NULL;
    else if(word < t->data.first)
        remove(word, t->left);
    else if(word > t->data.first)
        remove(word, t->right);
    else
    {
        if(t->data.second > 1)
            t->data.second--;
        else{
            temp = t;
            if(t->left == NULL)
                t = t->right;
            else if(t->right == NULL)
                t = t->left;
            delete temp;
        }
    }

    return search(word);
}
/*bool rangeSearch(string word1, string word2){

}
bool rangeSearch(string word1, string word2, Node* n){
    
}*/
