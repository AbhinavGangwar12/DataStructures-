#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * nxt;
        node(int key){
            this->data = key;
            this->nxt = NULL;
        }
};

class Queue{
    private:
        node * head;
        int size,count;
    public:
        Queue(){this->head = NULL;this->count=0;}
        Queue(int val){this->head = NULL;this->size = val;this->count=0;}
        void en_q(int);
        void display_q();
        int d_q();
        int peek(int);
        int membersLeft();
        int isEmpty();
        int isFull();
};

void Queue :: en_q(int key){
    node * newNode = new node(key);
    if(head == NULL){
        this->head = newNode;
        this->head->nxt = NULL;
        this->count++;
        return;
    }
    node * ptr = head;
    while(ptr->nxt){ptr= ptr->nxt;}
    ptr->nxt = newNode;
    this->count++;
}

int Queue :: d_q(){
    if(head == NULL){
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
    node * ptr = head;
    int x = ptr->data;
    head = head->nxt;
    delete ptr;
    this->count--;
    return x;
}

int Queue :: peek(int index){
    if(head == NULL){
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
    if(index >= this->count){
        cout<<"Enter a valid index."<<endl;
        return -1;
    }
    node * ptr = this->head;
    for(int i=0;i<index;i++){
        ptr = ptr->nxt;
    }
    int x = ptr->data;
    return x;
}

int Queue :: membersLeft(){
    if(head == NULL){
        cout<<"Queue is empty!"<<endl;
        return -1;
    }
    node * ptr = this->head;
    int count=0;
    while(ptr){
        ptr = ptr->nxt;
        count++;
    }
    return count;
}

int Queue :: isEmpty(){
    if(head == NULL)return 1;
    return 0;
}

int Queue :: isFull(){
    node * ptr = this->head;
    int count=0;
    while(ptr){count++;}
    if(count == this->size)return 1;
    return 0;
}

void Queue :: display_q(){
    if(this->head == NULL){
        cout<<"Queue is empty!"<<endl;
        return;
    }
    node * ptr = this->head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->nxt;
    }
    cout<<endl;
}

int main(){
    Queue q(4);

    q.en_q(1);
    q.en_q(2);
    q.en_q(3);
    q.en_q(4);
    q.display_q();
    q.d_q();
    cout<<q.peek(2)<<endl;
    q.display_q();
    cout<<q.membersLeft()<<endl;
    return 0;

}