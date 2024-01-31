#include<iostream>
using namespace std;
// class for creating a node
class Node{
    public:
        int data;
        Node * next;
        Node(int key){
            this->data = key;
            this->next = NULL;
        }
        ~Node(){
            int value = this->data;
            if(this->next != NULL){
                this->next = NULL;
                delete this->next;
            }
            cout<<"Node with data "<<value<<" is successfully deleted"<<endl;
        }
};

// insertion at head
void insertAtHead(Node* &head,int key){
    Node * new_node = new Node(key);
    new_node->next = head;
    head = new_node;
}

// print
void print(Node* &head){
    Node* tmp = head;
    cout<<"List : ";
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}


// insertion at tail
void insertAtTail(Node* &tail,int key){
    Node* new_node = new Node(key);
    tail->next = new_node;
    tail = new_node;
}


// insert after a given value
void insertAt(Node* &head,int value,int key){
    // We are assuming that the given value is in the list
    Node * new_node = new Node(key);
    if(head == NULL){
        head = new_node;
        return;
    }
    
    Node* tmp = head;
    while(tmp -> data != value){
        tmp = tmp->next;
    }
    new_node->next = tmp->next;
    tmp->next = new_node;
}


// deletion after a node
void deleteAt(Node* &head,int value){
    // We are assuming that the given value is in the list
    
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Deleted : ";
    Node* curr = head;
    Node* prev = NULL;
    while(curr -> data != value){
        prev = curr;
        curr = curr->next;
    }

    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

int main(){
    Node* node1 = new Node(5);
    Node* head = node1;
    Node* tail = node1;
    insertAtHead(head,6);
    print(head);
    insertAt(head,6,2);
    print(head);
    insertAtTail(tail,4);
    print(head);
    deleteAt(head,2);
    print(head);
    return 0;
}
