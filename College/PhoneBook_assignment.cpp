#include<bits/stdc++.h>
using namespace std;

class TrieNode{ 
public: 
    unordered_map<char, TrieNode *> children; 
    bool isEnd; 
    unordered_set<string> phoneNum ; 
    TrieNode() 
    { 
        isEnd = false; 
    } 
    ~TrieNode(){ 
        for (unordered_map<char, TrieNode *>::iterator i = children.begin(); i != children.end(); i++){ 
            delete i->second; 
        } 
    } 
}; 
void insert_name(string &str, string &num ,TrieNode *root)
{ 
    int n = str.length(); 
    TrieNode *itr = root; 

    for (int i = 0; i < n; i++){ 
        TrieNode *next = itr->children[str[i]]; 
        if (next == NULL){ 
            next = new TrieNode(); 
            itr->children[str[i]] = next; 
        } 
        itr = next; 
        if (i==n-1){ 
            itr->isEnd = true; 
            itr->phoneNum.insert(num);
        } 
    } 
} 
void displayUtil(string name,TrieNode* root,string curr)
{
    if (root->isEnd){
        for(auto x : root->phoneNum){
            cout<<name<<" "<<x<<endl;
        }
    }
    for (char i = 'a'; i <= 'z'; i++)
    {
        TrieNode *nextNode = root->children[i];
        if (nextNode != NULL)
            displayUtil(name + (char)i,nextNode,curr+(char)i);
    }
}
void display(string name,TrieNode* root){
    TrieNode* dup= root;
    dup=root;
    string curr=name;
    for(int i=0;i<name.size();i++){
        dup=dup->children[name[i]];
    }
    displayUtil(name,dup,curr);
}
void delete_number(string name, string number,TrieNode* root)
{
    int len=name.size();
    for(int i=0;i<len;i++)
    {
        char ch=name[i];
        if(root->children[ch]==NULL)
        {
            cout<<"invalid"<<endl;
            return;
        }
        root=root->children[ch];
    }
    if(root->isEnd==true){
        root->phoneNum.erase(number);
    }
}
void update_number(string name,string p1,string p2,TrieNode* root){
    delete_number(name,p1,root);
    insert_name(name,p2,root);
}
int main(){
    char ch;
    TrieNode *root = new TrieNode();
    string name,phone_number,updated_num;

    cout<<"Press 1 for create contact"<<endl;
    cout<<"Press 2 for update"<<endl;
    cout<<"Press 3 for search"<<endl;
    cout<<"Press 4 for delete"<<endl;
    cout<<"Press 5 for Exit"<<endl;
    do{ 
        cout<<"Enter your choice"<<endl;
        cin>>ch;
        switch (ch){
            case '1':{ 
                cout<<"name of person: ";
                cin>>name;
                cout<<"phone number of person: ";
                cin>>phone_number;
                insert_name(name,phone_number,root);
                break;
            }
            case '2':{
                cout<<"name of person: ";
                cin>>name;
                cout<<"phone number of person: ";
                cin>>phone_number;
                cout<<"updated number of person: ";
                cin>>updated_num;
                update_number(name,phone_number,updated_num,root);
                break;
            }
            case '3':{
                cout<<"name of person: ";
                cin>>name;
                display(name,root);
                break;
            }
            case '4':{
                cout<<"name of person: ";
                cin>>name;
                cout<<"phone number of person: ";
                cin>>phone_number;
                delete_number(name,phone_number,root);
                break;
            }
            case '5':{
                cout<<"Exit"<<endl;
                break;
            }
            default:{
                cout<<"Invalid input"<<endl;
                break;
            }
        }   
    }while(ch!='5');
    return 0;
}