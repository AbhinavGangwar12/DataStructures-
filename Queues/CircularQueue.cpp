#include<iostream>
#include<stdbool.h>
using namespace std;
class node{
    public:
        int data;
        node * next;
        node(int key){
            this->data=key;
            this->next = NULL;
        }
};
class circularQueue{
    private:
        node * head;
        int size;
        int count;
    public:
        circularQueue(int val){head=NULL;this->size = val;count = 0;}
        int front();
        int rear();
        void en_q(int);
        int d_q();
        bool isEmpty();
        bool isFull();
        int waiting(){
            return this->count;
        }
        void display(){
            node * flow = this->head->next;
            cout<<head->data<<" ";
            while(flow != this->head){
                cout<<flow->data<<" ";
                flow = flow->next;
            }
            cout<<endl;
        }
};
int circularQueue::front(){
    if(head==NULL)return -1;
    return this->head->data;
}
int circularQueue::rear(){
    if(head==NULL)return -1;
    node * ptr = this->head;
    while(ptr->next != this->head){
        ptr = ptr->next;
    }
    return ptr->data;
}
void circularQueue::en_q(int key){
    if(this->count >= this->size){
        cout<<"Queue is full"<<endl;
        return;
    }
    node * newNode = new node(key);
    if(this->head == NULL){
        this->head = newNode;
        head->next = this->head;
        this->count++;
        return;
    }
    node * ptr = head;
    while(ptr->next != this->head){
        ptr = ptr->next;
    }
    ptr->next = newNode;
    newNode->next = this->head;
    this->count++;
}
int circularQueue :: d_q(){
    if(head == NULL){
        cout<<"Queue is empty."<<endl;
        return -1;
    }
    if(this->head->next == this->head){
        int x = this->head->data;
        node * ptr = this->head;
        delete ptr;
        head = NULL;
        this->count--;
        return x;
    }
    node * front = this->head;
    node * rear = this->head;
    while(rear->next != this->head){
        rear = rear->next;
    }
    this->head = this->head->next;
    int x = front->data;
    delete front;
    this->count--;
    rear->next = this->head;
    return x;
}
bool circularQueue :: isEmpty(){
    if(this->head==NULL && this->count == 0)return true;
    return false;
}
bool circularQueue :: isFull(){
    if(this->count == this->size)return true;
    return false;
}

int main(){
    circularQueue q(4);
    q.en_q(1);
    q.en_q(2);
    q.en_q(3);
    q.en_q(4);
    // q.en_q(4);//This should give the message "Queue is full"
    q.display();
    cout<<q.waiting()<<endl;
    q.d_q();
    q.display();
    cout<<q.waiting()<<endl;
    cout<<q.isFull()<<endl;
    cout<<q.isEmpty()<<endl;
    while(!(q.isEmpty())){q.d_q();}
    if(q.isEmpty())cout<<"Empty"<<endl;
    // circularQueue a(0);
    // a.en_q(1);//Should display the message of being full
    return 0;
}

/*
-- A circular queue is a data structure which works on FIFO fashion 
-- It is also known as circular buffer as the last postion of the queue is circled back to the first element of the queue
-- Applications
    + Used in Page Replacement Algorithm
    + CPU Scheduling
    + Inter process communication between the processes
    + In Operating System, circular queues are used to maintain the resources
-- Advantages 
    + Allows a quick way to store FIFO data
    + Does not use dynamic memory
    + Efficient use of memory
    + All the operations are done in O(1) time
    + Simple Implementation
-- Disadvantages
    + Some operations such as deletion and insertion can be complex in a circular queue
    + It has a fixed size,when the max elements are achieved then there are some chances of overflow if not managed properly
    
                                -->( A )-->( B )-->( C )-->( D )-->( E )-->( F )-->( A ) 
                                    ||                                       ||
                                   Front                                    Rear
*/ 