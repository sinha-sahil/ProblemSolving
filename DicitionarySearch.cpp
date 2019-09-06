#include<iostream>
#include<vector>
using namespace std;


struct TrieNode{
	char val;
	vector<TrieNode*> ptrs;
	int count;

	TrieNode(char data): val(data), count(0){
		vector<TrieNode*> temp(26, nullptr);
		ptrs = temp;
	}
};

void insert(TrieNode* &root,string input, int index){
	if(root == nullptr) return;
	if(index == input.size()) return;
	int asc = static_cast<int>(input[index]) -97;
	TrieNode* charPtr = root->ptrs[asc];
	if(charPtr == nullptr){
		TrieNode* newNode = new TrieNode(input[index]);
		newNode->count = 1;
		root->ptrs[asc] = newNode;
		insert(root->ptrs[asc], input, ++index);
	}
	else{
		root->ptrs[asc]->count++;
		cout<<root->ptrs[asc]->val<<" "<<root->ptrs[asc]->count<<endl;
		insert(charPtr, input, ++index);
	}
	return;
}

void findPrefix(TrieNode* &root, string temp, vector<string> &prefix){
	if(root == nullptr) return;
	if(root->val != '$') {
		temp += root->val;
	}
	if(root->val != '$' && root->count == 1){
		prefix.push_back(temp);
		return;
	}

	for(int i=0; i<26; i++){
		if(root->ptrs[i]){
			findPrefix(root->ptrs[i], temp, prefix);
		}
	}
}
string findPrefixForString(TrieNode* root, string input){
    // cout<<"Input "<<input<<endl;
    string answer = "";
    int asc = static_cast<int>(input[0])-97;
    int index = 1;
    TrieNode* cptr = root->ptrs[asc];
    while(cptr && cptr->count !=1){
        answer += cptr->val;
        int as = static_cast<int>(input[index]) -97;
        index++;
        cptr = cptr->ptrs[as];
    }
    if(cptr) answer += cptr->val;
//     cout<<"answer: "<<answer<<endl;
    return answer;
 
}


void printNodeData(TrieNode* ptr){
	if(ptr == nullptr) return;
	cout<<ptr->val<<" ";
	for(int i=0; i<26; i++){
		if(ptr->ptrs[i]) cout<<ptr->ptrs[i]->val<<" \n";
		else {
			cout<<'a'+i<<" is nullptr"<<endl;
		}
	}
}

int main(){
	string input = "sahil";
	TrieNode* head = nullptr;
	head = new TrieNode('$');
	insert(head, input, 0);
	insert(head, "sinha", 0);
	vector<string> temp;
	findPrefix(head, "", temp);
	for(auto i: temp){
		cout<<i<<" ";
	}
}

