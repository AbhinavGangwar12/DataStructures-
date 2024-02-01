#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int key){
            this->next = NULL;
            this->prev = NULL;
            this->data = key;
        }
        ~Node(){
            int value = this->data;
            if(this->next || this->prev){
                this->prev=NULL;
                this->next = NULL;
            }
            cout<<"Node for "<<value<<" is deleted"<<endl;
        }
};


// Insert at head
void insertAtHead(Node* &head,int key){
    Node* new_node = new Node(key);
    new_node->next = head;
    head->prev = new_node;
    head = new_node;
}


// Insert at the end
void insertAtEnd(Node* &tail,int key){
    Node* new_node = new Node(key);
    new_node->prev = tail;
    tail->next = new_node;
    tail = new_node;
}


// Insert after value
void insertAfter(Node* &head,Node* &tail,int value,int key){
    // Assuming that the value is in the list

    Node* new_node = new Node(key);
    if(head==NULL){
        head = new_node;
        return;
    }

    Node* temp = head;
    while(temp->data != value){
        temp = temp->next;
    }

    if(temp->next == NULL){
        new_node->prev = tail;
        tail->next = new_node;
        tail = new_node;
        return;
    }

    new_node->next = temp->next;
    temp->next->prev = new_node;
    new_node->prev = temp;
    temp->next = new_node;
}


// delete value
void deleteAt(Node* &head,Node* &tail,int value){
    if(head==NULL){
        cout<<"The list is already empty"<<endl;
        return;
    }
    cout<<"Deleted : ";
    Node* current = head;
    Node* previous = NULL;
    while(current->data != value){
        previous = current;
        current = current->next;
    }
    if(current->next == NULL){
        previous->next = NULL;
        current->prev = NULL;
        tail = previous;
        delete current;
        return;
    }
    current->next->prev = previous;
    previous->next = current->next;
    current->next = NULL;
    current->prev = NULL;
    delete current;
}


void print(Node* &head){
    Node* tmp = head;
    cout<<"List : ";
    while(tmp){
        cout<<tmp->data<<" ";
        tmp = tmp->next;
    }
    cout<<endl;
}

int main(){
    Node* n1 = new Node(5);
    Node* head = n1;
    Node* tail = n1;
    insertAtHead(head,10);
    print(head);
    insertAtEnd(tail,11);
    print(head);
    insertAfter(head,tail,5,1);
    print(head);
    deleteAt(head,tail,5);
    print(head);
    return 0;
}