#include<iostream>
#include<stdbool.h>
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
class IRQueue{
    private:
        node * head;
        int size,count;
    public:
        IRQueue(int val){this->head=NULL;this->size = val;this->count = 0;}
        void insert(int);
        int d_qfront();
        int d_qrear();
        int get_front();
        int get_rear();
        bool isEmpty();
        bool isFull();
        void display();
};
void IRQueue :: insert(int key){
    if(this->count >= this->size ){
        cout<<"Queue is full"<<endl;
        return;
    }
    node * newNode = new node(key);
    if(this->head == NULL){
        this->head = newNode;
        this->count++;
        return;
    }
    node * ptr = this->head;
    while(ptr->nxt != NULL){
        ptr = ptr->nxt;
    }
    ptr->nxt = newNode;
    this->count++;
}
int IRQueue :: d_qfront(){
    if(this->count < 1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    if(this->head->nxt == NULL){
        node * ptr = this->head;
        head= NULL;
        int x = ptr->data;
        delete ptr;
        this->count--;
        return x;
    }
    node * ptr = this->head;
    this->head = this->head->nxt;
    int ret = ptr->data;
    delete ptr;
    this->count--;
    return ret;
}
int IRQueue :: d_qrear(){
    if(this->count < 1){
        cout<<"Queue is empty"<<endl;
        return -1;
    }
    if(this->head->nxt == NULL){
        node * ptr = this->head;
        head= NULL;
        int x = ptr->data;
        delete ptr;
        this->count--;
        return x;
    }
    node * ptr = this->head;
    while(ptr->nxt->nxt != NULL){
        ptr = ptr->nxt;
    }
    int ret = ptr->nxt->data;
    node * del = ptr->nxt;
    delete del;
    this->count--;
    ptr->nxt = NULL;
    return ret;

}
int IRQueue :: get_front(){
    if(this->head == NULL) return -1;
    return this->head->data;
}
int IRQueue :: get_rear(){
    if(this->head == NULL) return -1;
    node * flow = this->head;
    while(flow->nxt!=NULL){
        flow = flow->nxt;
    }
    return flow->data;
}
bool IRQueue :: isFull(){
    if(this->count>= this->size)return true;
    return false;
}
bool IRQueue :: isEmpty(){
    if(this->count < 1)return true;
    return false;
}
void IRQueue :: display(){
    node * ptr = this->head;
    while (ptr)
    {
        cout<<ptr->data<<" ";
        ptr = ptr->nxt;
    }
    cout<<endl;
}
int main(){
    IRQueue queue(4);
    queue.insert(1); 
    queue.insert(2); 
    queue.insert(3); 
    queue.insert(4); 
    queue.display();
    queue.d_qrear();
    queue.display();
    queue.d_qfront();
    queue.display();
    cout<<queue.get_front()<<endl;
    cout<<queue.get_rear()<<endl;
    return 0;
}
/*
An Input restricted queue is a form of doubly-ended queue in which data can be inserted from rear and can be deleted from both the ends
-- Does not follow FIFO
-- Implemented where the data is stored in FIFO fashion but due to variety of reasons the recently added data is descarded
-- Used in Job scheduling algorithms
-- Abstract Data Types of Input Restricted Queues
    + Insert Rear
    + Delete Rear
    + Delete Front
    + Get Front
    + Get Rear
    + Is Empty
    + Is Full
-- Similar to this we have OUTPUT restricted queue where we have the option of removing an element from both of the sides of the queue 
    and insertion can be done from the front only.
*/ 