#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

struct Node{
	int data;
	Node* left, *right;
	Node(int n_data){
		left= nullptr;
		data= n_data;
		right= nullptr;
	}
};

Node* insert(Node* &root, int index,const vector<int>& vi){
	if(index< vi.size()){
		root= new Node(vi[index]);
		root->left= insert(root->left, index*2+1, vi);
		root->right = insert(root->right, index*2+2, vi);
	}
	return root;
}

bool checkParent(Node* root){
	if(root==nullptr) return false;
	queue<Node*> q;
	q.push(root);
	while(not q.empty()){
		Node* temp= q.front();
		q.pop();
		int sum_value=0;
		if(temp->left){
			sum_value += temp->left->data;
			q.push(temp->left);
		}
		if(temp->right){
			sum_value += temp->right->data;
			q.push(temp->right);
		}
		if(sum_value != temp->data) return false;
	}
	return true;
}

void level_insert(Node* &root, int data){
	if(root==nullptr){
		root= new Node(data);
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* current= q.front();
		q.pop();
		if(current->left ==nullptr){
			current->left= new Node(data);
			break;
		}
		else q.push(current->left);
		if(current->right ==nullptr){
			current->right= new Node(data);
			break;
		}
		else q.push(current->right);
	}
}

void char_insert(Node* root, char val){
	if(root ==nullptr) return;
	int xval= static_cast<int>(val);
	if((val == 'a') or (val=='e') or (val=='i') or (val=='o') or (val=='u')) level_insert(root->left, xval);
	else level_insert(root->right, xval);
}

void positionInsert(Node* &root, int data, int value){
	if(root==nullptr){
		root= new Node(data);
		return;
	}
	queue<Node*> q;
	q.push(root);
	while(!q.empty()){
		Node* current= q.front();
		q.pop();
		if(current->data== data){
			level_insert(current, value);
			return;
		}
		q.push(current->left);
		q.push(current->right);
	}
	level_insert(root, value);
}

void inorder(Node* root){
	if(root==nullptr) return;
	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
	
}

void postorder(Node* root){
	if(root==nullptr) return;
	inorder(root->left);
	inorder(root->right);
	cout<<root->data<<" ";
	
}

void preorder(Node* root){
	if(root==nullptr) return;
	cout<<root->data<<" ";
	inorder(root->left);
	inorder(root->right);
	
	
}

void bfs(Node* root){
	queue<Node*> q;
	q.push(root);
	while(q.size()){
		Node* current= q.front();
		char a= static_cast<char>(current->data);
		//cout<<q.front()->data<<" ";
		cout<<a<<" ";
		if(current->left != nullptr)q.push(current->left);
		if(current->right !=nullptr)q.push(current->right);
		q.pop();
	}
}

void preorder_count(Node* root, int& count, int key){
	if(root==nullptr) return;
	if(count<=key){
		count++;
		if(count == key){
			cout<<"Found : ";
			cout<<root->data<<endl;
		}
		preorder_count(root->left, count, key);
		preorder_count(root->right, count, key);
	}
}

void delete_node(Node* root, int data){
	if(root==nullptr) return;
	queue<Node*> q;
	q.push(root);
	Node* data_node, *swap_node;
	Node* last_parent;
	bool left_child= true;
	while(!q.empty()){
		Node* temp= q.front();
		q.pop();
		if(temp->left){
			q.push(temp->left);
			last_parent= temp;
			left_child= true;
		}
		if(temp->right){
			q.push(temp->right);
			last_parent = temp;
			left_child= false;
		}
		if(temp->data == data) data_node= temp;
		if(q.empty()) swap_node= temp;
	}
	cout<<"Data to delete: "<<data_node->data<<" Data to swap: "<<swap_node->data<<endl;
	data_node->data = swap_node->data;
	if(left_child)last_parent->left= nullptr;
	else last_parent->right= nullptr;
	delete swap_node;
}

vector<string> outputs;
void fun(Node* root, string str){
	if(root->left ==nullptr and root->right ==nullptr){
		str +=  to_string(root->data);
		cout<<str<<endl;
		outputs.push_back(str);
		return;
	}
	str  +=to_string(root->data);
	if(root->left) fun(root->left, str);
	if(root->right) fun(root->right, str);
}

void sahil_fun(Node* root, string& str){
	if(root==nullptr){
		return;
	}
	str+= to_string(root->data);
	if(root->left ==nullptr and root->right ==nullptr){
		reverse(str.begin(), str.end());
		outputs.push_back(str);
		return;
	}
	sahil_fun(root->left, str);
	sahil_fun(root->right, str);
	str.erase(str.end()-1);
}

int main(){
	vector<int> vi{1,2,3,4,5,6};
//	Node* root=nullptr;
//	inorder(root);
//	cout<<endl;
//	bfs(root);
//	level_insert(root, 1);
//	level_insert(root, 2);
//	level_insert(root, 3);
//	level_insert(root, 4);
//	positionInsert(root, 3,5);
//	Node* root= nullptr;	
//	root= insert(root, 0, vi);
//	inorder(root);
//	cout<<endl;
//	string opt="";
//	sahil_fun(root, opt);
//	for(auto i: outputs){
//		cout<<i<<" ";
//	}
//	delete_node(root, 4);
//	inorder(root);
//	int count=0;
//	int key=3;
//	preorder_count(root, count, key);
	Node* root_ptr = new Node(1);
	string input= "sahil sinha";
	for(int i=0; i<input.size(); i++){
		char_insert(root_ptr, input[i]);	
	}
	bfs(root_ptr);
}

