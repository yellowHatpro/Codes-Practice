#include <bits/stdc++.h>
using namespace std;
int main(){
cout<<endl;
	return 0;
}

class TrieNode{
public:
	char data;
	TrieNode **children;
	bool isTerminal;

	TrieNode(char data){
		this->data = data;
		children =new TrieNode*[26];
		for (int i = 0; i < 26; ++i)
		{
		children[i] = NULL;
		}
		isTerminal= false;
	}
};

class Trie{
	TrieNode *root;
public:
	Trie(){
		root = new TrieNode('\0');
	}
	void insertWord(TrieNode *root ,string word){
		//Base Case
		if(word.size()==0){
			root->isTerminal = true;
			return;
		}
		// Small Calculation
		int index = word[0] - 'a';
		TrieNode *child;
		if (root->children[index]!=NULL)
		{
			child = root ->children[index];
		}
		else{
			child = new TrieNode(word[0]);
			root->children[index] = child;
		}
		//Recusive call
		insertWord(child , word.substr(1));

	}
	//For user
	void insertWord(string word){
		insertWord(root,word);
	}
	bool searchhelp(string word , TrieNode *root){
		if(word.size()==0 &&  root->isTerminal==true){
			return false;
		}  //Base Case
		int index = word[0] - 'a';
		if(root->children[index]==NULL) return false;
		
		else return searchhelp(word.substr(1),root->children[index]);
	}
	bool search(string word){
		return searchhelp(word,root);
	}
	

};