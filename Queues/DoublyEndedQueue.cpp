// Here Doubly Ended Queue is implimented using doubly Linked list

#include<iostream>
#include<stdbool.h>
using namespace std;

// Initialising a node

class node {
    public:
        node * nxt, * prev;
        int data;
        node(int val){
            this->prev = NULL;
            this->nxt = NULL;
            this->data = val;
        }
};

// Class for Doubly Ended Queue

class D_q{
    private:
        node * head;
        node * tail;
        int size;
        int count;
    public:
        D_q(int val){
            this->head = NULL;
            this->tail = NULL;
            this->size = val;
            this->count = 0;
        }
        void push_front(int);
        void push_back(int);
        int pop_front();
        int pop_back();
        int peek_front();
        int peek_back();
        int size_();
        bool isEmpty();
        void displayB();
        void displayF();
};


// Function bodies


void D_q :: push_front(int key){
    if(this->count >= this->size)return;
    node * newNode = new node(key);
    if(this->head == NULL){
        this->head = newNode;
        this->tail = this->head;
        this->count++;
        return;
    }
    newNode->nxt = this->head;
    this->head->prev = newNode;
    this->head = this->head->prev;
    this->count++;
    node * ptr1 = this->head;
    while(ptr1->nxt){ptr1 = ptr1->nxt;}
    this->tail = ptr1;
    return;
}


void D_q :: push_back(int key){
    if(this->count >= this->size)return;
    node * newNode = new node(key);    
    if(this->head == NULL ){
        this->head = newNode;
        this->tail = this->head;
        this->count++;
        return;
    }
    
    newNode->prev = this->tail;
    this->tail->nxt = newNode;
    this->tail = this->tail->nxt;
    this->count++;
    return;
}


int D_q :: pop_front(){
    if(this->count < 1)return -1;
    if(this->head->nxt == NULL || (this->head == this->tail) ){
        node * ptr = this->head;
        this->head = this->tail = NULL;
        int ret = ptr->data;
        delete ptr;
        this->count--;
        return ret;
    }
    node * del = this->head;
    this->head = this->head->nxt;
    this->head->prev = NULL;
    int ret = del->data;
    delete del;
    this -> count --;
    return ret;
}
int D_q :: pop_back(){
    if(this->count < 1)return -1;
    if(this->head->nxt == NULL || ( this->head == this->tail ) ){
        node * ptr = this->head;
        this->head = this->tail = NULL;
        int ret = ptr->data;
        delete ptr;
        this->count--;
        return ret;
    }
    node * ptr = this->tail;
    this->tail = this->tail->prev;
    int ret = ptr->data;
    this->tail->nxt = NULL;
    delete ptr;
    this->count--;
    return ret;
}
int D_q :: peek_front(){
    if(this->head == NULL)return -1;
    return this->head->data;
}
int D_q :: peek_back(){
    if(this->head == NULL)return -1;
    return this->tail->data;
}
int D_q :: size_(){
    return this->count;
}
bool D_q :: isEmpty(){
    if(this->head == NULL)return true;
    return false;
}
void D_q :: displayF(){
    node * ptr = this->head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->nxt;
    }
    cout<<endl;
}
void D_q :: displayB(){
    node * ptr = this->tail;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->prev;
    }
    cout<<endl;
}

// Main Function

int main(){
    D_q queue(4);
    queue.push_front(1);
    queue.push_front(2);
    queue.displayF();
    // queue.displayB();
    queue.push_back(4);
    queue.push_back(3);
    queue.displayF();
    queue.pop_front();
    queue.displayF();
    queue.pop_back();
    queue.displayF();
    cout<<queue.peek_front()<<endl;
    cout<<queue.peek_back()<<endl;
    cout<<queue.size_()<<endl;
    return 0;
}

// THEORY

/*
It is a queue data structure which implements queues and the merit of using it is; Insertion and deletion can be done on both the ends of the queue.
-- Advantages of De-queue
    + Applied on both Stack and Queues.
    + Storing Web Browers's history
    + Storing a software application's undo operations
    + Job scheduling algorithm
-- DeQueues can be monotonic too i.e. Either the elements are in ascending order or they are in descending order
    >> suppose a monotonic (Increasing dequeue) {1,2,5,7,10} no if we want to insert 3 in it so we have to delete the elements smaller than it and the result will be like {3,5,7,10}.Similar is for monotonic (Decreasing) dequeue.
    >> Applications of monotonic de_queues
        ~ Can be used to get next maximum in a subarray using monotonic decreasing dequeue, like-wise previous maximum can also be fetched by using monotonic increasing dequeue.
        ~ It is also used in sliding window problems.
-- Operations that are performable on De_queue
    >> push_front()     >> push_back() 
    >> pop_front()      >> pop_back() 
    >> front()          >> back() 
    >> empty()          >> size()
*/ 