#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * next,*prev;
        node(int val){
            this->data = val;
            this->prev = NULL;
            this->next = NULL;
        }
};
class queue{
    node * head;
    int size;
    int count;
    public:
        queue(int val){
            this->head = NULL;
            this->size = val;
            this->count = 0;
        }
        void insert(int);
        int deletF();
        int deletB();
        void display(){
            if(!this->head){
                cout<<"Queue is empty."<<endl;
                return;
            }
            node * ptr = this->head;
            while(ptr){
                cout<<ptr->data<<" ";
                ptr = ptr->next;
            }
            cout<<endl;
        }
};
void queue :: insert(int key){
    if(this->count >= this->size){
        cout<<"Queue is full."<<endl;
        return;
    }
    node * newNode = new node(key);
    if(this->head == NULL){
        this->head = newNode;
        this->count++;
        return;
    }
    if(this->head->next == NULL){
        if(this->head->data > newNode->data){
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
            this->count++;
            return;
        }
        else if(this->head->data < newNode->data){
            this->head->next = newNode;
            newNode->prev = this->head;
            this->count++;
            return;
        }
    }
    node * ptr = this->head;
    while (ptr->next)
    {
        if(ptr->data > newNode->data){
            node * temp = ptr;
            ptr = ptr->next;
            ptr->prev = NULL;
            delete temp;
        }
        else if(ptr->data == newNode->data){
            this->head = ptr;
            return;
        }
        else break;
    }
    if(ptr==NULL){
        this->head = newNode;
        this->count++;
    }
    newNode->next = ptr;
    ptr->prev = newNode;
    this->head = newNode;
    this->count++;
}
int queue :: deletF(){
    if(this->count < 1)return -1;
    if(!( this->head->next )){
        node * ptr = this->head;
        this->head = NULL;
        int ret = ptr->data;
        delete ptr;
        this->count--;
        return ret;
    }
    node * ptr = this->head;
    this->head = this->head->next;
    this->head->prev = NULL;
    int ret = ptr->data;
    delete ptr;
    this->count--;
    return ret;
}
int queue :: deletB(){
    if(this->count < 1)return -1;
    if(!( this->head->next )){
        node * ptr = this->head;
        this->head = NULL;
        int ret = ptr->data;
        delete ptr;
        this->count--;
        return ret;
    }
    node * ptr = this->head;
    while(ptr->next->next){
        ptr = ptr->next;
    }
    int ret = ptr->next->data;
    delete ptr->next;
    this->count--;
    ptr->next = NULL;
    return ret;
}
int main(){
    queue q(4);
    q.insert(4);
    q.insert(5);
    // q.insert(5);
    q.insert(1);
    q.insert(1);
    q.display();
    q.deletB();
    q.display();
    q.deletB();
    q.display();
    q.insert(1);
    q.display();
    return 0;
}
/*
Allows efficient insetion and deletion of elements from both the ends of the the deque
There are two types of monotonic queues:
    1. Increasing monotonic queues: Only keeps the ascending order of the elements.Any element smaller than current minimum is removed.
    2. Decreasing monotonic queues: Only keeps decreasing order of the elements.Any element greater than the current maximum is removed.
--Applications of Monotonic queues
    >> Finding the maximum and the minimum of a sliding window
--Advantages
    >> Efficient in terms of time and space complexity
    >> Easy to implement
*/ 