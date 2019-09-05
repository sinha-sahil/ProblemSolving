#include<iostream>
#include<vector>
using namespace std;


struct TrieNode{
	int val;
	vector<TrieNode*> ptrs;
	int count;

	TrieNode(int data): val(data), count(0){
		vector<TrieNode*> temp(26, nullptr);
		ptrs = temp;
	}
};

void insert(string input, TrieNode* &head){
	for(int i=0; i<input.size(); i++){
		
	}
}