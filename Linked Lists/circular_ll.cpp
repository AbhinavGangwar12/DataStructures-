#include<iostream>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
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
            cout<<"Node with data "<<value<<" is deleted"<<endl;
        }
};

// Insert in at the begining
void insertAtStart(Node* &tail,int key){
    Node* new_node = new Node(key);
    if(tail == NULL){
        tail->next = new_node;
        tail = new_node;
        return;
    }
    new_node->next = tail->next;
    tail->next = new_node;
}

// Insert at tail
void insertAtEnd(Node* &tail,int key){
    Node* new_node = new Node(key);
    if(tail == NULL){
        tail = new_node;
        tail->next = tail;
        return;
    }
    new_node->next = tail->next;
    tail->next = new_node;
    tail = new_node;
}

// insert in between
void insertAfter(Node* &tail,int value,int key){
    Node* new_node = new Node(key);
    
    if(tail == NULL){
        insertAtEnd(tail,key);
        return;
    }
    Node* curr = tail;
    while(curr->data != value){
        curr = curr->next;
    }
    new_node->next = curr->next;
    curr->next = new_node;
}


// delete in between
void deleteAt(Node* &tail,int value){
    
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Deleted : ";
    Node* curr = tail->next;
    Node* prev = tail;
    while(curr->data != value){
        prev = curr;
        curr = curr->next;
    }
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

// delete tail
// void deleteTail(Node* &tail){
//     if(tail == NULL){
//         cout<<"List is empty"<<endl;
//     }
//     Node* temp = tail;
//     tail = tail->next;
//     temp->next = NULL;
//     delete temp;
// }

// delete head
void deleteTail(Node* &tail){
    if(tail == NULL){
        cout<<"List is empty"<<endl;
        return;
    }
    cout<<"Deleted : ";
    Node* temp = tail->next;
    tail->next = temp->next;
    temp->next = NULL;
    delete temp;
}

// Print list
void print(Node* &tail){

    Node* temp = tail;
    do{
        cout<<temp->data<<" ";
        temp = temp->next;
    }while(temp != tail);
    cout<<endl;
}


int main(){
    // Node* n1 = new Node(5);
    Node* tail = NULL;
    insertAtEnd(tail,5);
    print(tail);
    insertAtEnd(tail,6);
    print(tail);
    insertAtStart(tail,11);
    print(tail);
    insertAtStart(tail,13);
    print(tail);
    insertAfter(tail,11,23);
    print(tail);
    deleteAt(tail,13);
    print(tail);
    return 0;
}