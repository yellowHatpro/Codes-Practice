#include <iostream>
class Node {
   public:
    int data;
    Node *next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

using namespace std;

int length(Node *head) {
    // Write your code here
	int count=0;
    Node *temp= head;
    if (temp==NULL){
return count;}
    temp= head->next;
  
    return 1+length(temp);
    
}

Node* takeInputNaive() {
    Node* head = NULL;
    int data;cin>>data;
    while(data!=-1){

        Node* newNode = new Node(data);

        if (head==NULL)
        {
            head = newNode;
        }else {
            Node* temp = head;
            while(temp->next!=NULL){
                temp=temp->next;
            }
            temp->next = newNode;
        }
        cin>>data;
    }
    return head;
}

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        cin >> data;
    }
    return head;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        Node *head = takeinput();
        cout << length(head) << "\n";
    }
}