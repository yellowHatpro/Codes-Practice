#include <bits/stdc++.h>
using namespace std;

//Binary Search Tree Node
class Node {
public:
	int data;
	Node* left;
	Node* right;


	Node(int data){

	this->data = data;
	left = right = NULL;
	}};

// Queue
template <typename T>
class Queue {
	public:
	int rear;
	int front;
	int size;
	int capacity;
	T *arr;
	Queue(int capacity){
		this->capacity = capacity;
		rear =front = -1;
		size=0;
		 arr =  new T[capacity];
	}
	bool isempty(){
		return (size==0);
	}
	void enqueue(T data){
		if(size==capacity){
			cout<<"Queue is full"<<endl;
			return;
		}
		if(front==-1){
			front++;
		}
		rear++;
		arr[rear]=data;
		size++;

	}

	void dequeue(){
		if(size==0){
			cout<<"Queue empty\n";
			rear=front=-1;
			return;
		}
		front++;
		size--;
		
	}
	void display(){
		if(size==0){
			cout<<"Queue empty\n";
			return;
		}
		for(int i=front;i<=rear;i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
	}

	T peek(){
		if (size==0){
			cout<<"Queue empty\n";
			return NULL;
		}
		return arr[front];
	}

};

Node* root = NULL;
Queue<Node*> q(100);

//Binary Search Tree
void insert(int data){
	if (root==NULL){
		root = new Node(data);
		return;
	}
	Node* temp = root;
	while(temp!=NULL){
		if(data<temp->data){
			if(temp->left==NULL){
				temp->left = new Node(data);
				return;
			}
			temp = temp->left;
		}
		else{
			if(temp->right==NULL){
				temp->right = new Node(data);
				return;
			}
			temp = temp->right;
		}
	}
}

bool search(int data){
	if(root==NULL){
		return false;
	}
	Node* temp = root;
	while(temp!=NULL){
		if(data==temp->data){
			return true;
		}
		else if(data<temp->data){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	return false;
}


//Preorder Traversal
void preOrder(Node* root){
	if(root==NULL){
		return;
	}
	cout<<root->data<<" ";
	preOrder(root->left);
	preOrder(root->right);
}

//Inorder Traversal
void inOrder(Node* root){
	if(root==NULL){
		return;
	}
	inOrder(root->left);
	cout<<root->data<<" ";
	inOrder(root->right);
}

//Postorder Traversal
void postOrder(Node* root){
	if(root==NULL){
		return;
	}
	postOrder(root->left);
	postOrder(root->right);
	cout<<root->data<<" ";
}

Node* minValueNode(Node* node){
	Node* current = node;
	while(current->left!=NULL){
		current = current->left;
	}
	return current;
}

Node* deleteNode(Node* root,int data){
	if(root==NULL){
		return root;
	}
	if(data<root->data){
		root->left = deleteNode(root->left,data);
	}
	else if(data>root->data){
		root->right = deleteNode(root->right,data);
	}
	else{
		if (root->left==NULL && root->right==NULL){
			delete root;
			root = NULL;
			return root;
		}
		else if(root->left==NULL){
			Node* temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL){
			Node* temp = root->left;
			delete root;
			return temp;
		}
		else{
		Node* temp = minValueNode(root->right);
		root->data = temp->data;
		root->right = deleteNode(root->right,temp->data);
	}
	return root;
	}
		

}
int main(){
	cout<<"BINARY SEARCH TREE IMPLEMENTATION";
	cout<<"\n1.Insert\n2.Search\n3.Delete\n4.Preorder\n5.Inorder\n6.Postorder\n7.Exit\n";
	int choice,data;
	while(1){
		cout<<"Enter your choice: ";
		cin>>choice;
		switch(choice){
			case 1:
				cout<<"Enter data to be inserted: ";
				cin>>data;
				insert(data);
				break;
			case 2:
				cout<<"Enter data to be searched: ";
				cin>>data;
				if(search(data)){
					cout<<"Found\n";
				}
				else{
					cout<<"Not Found\n";
				}
				break;
				
			case 3:
				cout<<"Enter data to be deleted: ";
				cin>>data;
				root = deleteNode(root,data);
				break;
			case 4:
				cout<<"Preorder Traversal: ";
				preOrder(root);
				cout<<endl;
				break;
			case 5:
				cout<<"Inorder Traversal: ";
				inOrder(root);
				cout<<endl;
				break;
			case 6:
				cout<<"Postorder Traversal: ";
				postOrder(root);
				cout<<endl;
				break;
			case 7:
				exit(0);
			default:
				cout<<"Invalid choice\n";
		}
	}
}




