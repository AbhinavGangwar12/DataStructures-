#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node * nxt;
        node * prev;
        node(int val){
            this->data = val;
            this->nxt = this->prev = NULL;
        }
};
class Stack{
    node * head;
    int size,count;
    public:
        Stack(int x){this->head = NULL;this->size = x;this->count = 0;}
        Stack(){this->head = NULL;}
        void push(int);
        int pop();
        int stackTop();
        int isEmpty();
        int isFull();
        void displayStack();
};
void Stack :: push(int key){
    if(this->count>=this->size){cout<<"Stack Overflow"<<endl;return;}
    node * newNode = new node(key);
    int count =0;
    if(head == NULL){
        head = newNode;
        head->nxt = head->prev = NULL;
        this->count++;
        return;
    }
    node * ptr = head;
    while(ptr->nxt){
        ptr = ptr->nxt;
    }
    ptr->nxt = newNode;
    newNode->prev = ptr;
    this->count++;
}
int Stack :: pop(){
    if(head == NULL || this->count < 1){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    node * ptr = head;
    node * tptr = NULL;
    while(ptr->nxt != NULL){
        tptr = ptr;
        ptr = ptr->nxt;
    }
    tptr->nxt = NULL;
    int ret = ptr->data;
    delete ptr;
    this->count--;
    return ret;
}
int Stack :: stackTop(){
    if(head == NULL){
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    if(head->nxt == NULL){
        node * ptr = head;
        head = NULL;
        int x = ptr->data;
        delete ptr;
        return x;
    }
    node * ptr = head;
    while(ptr->nxt){
        ptr = ptr->nxt;
    }
    return ptr->data;
}
int Stack :: isEmpty(){
    if(head == NULL)return 1;
    return 0;
}
int Stack :: isFull(){
    if(this->count >= this->size)return 1;    
    return 0;
}
void Stack :: displayStack(){
    if(head == NULL){
        cout<<"Stack is Empty"<<endl;
        return;
    }
    node * ptr = head;
    while(ptr){
        cout<<ptr->data<<" ";
        ptr = ptr->nxt;
    }
    cout<<endl;
}
int main(){
    Stack st(4);
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    // st.push(5);//This should return "Stack Overflow"
    // st.push(5);//This should return "Stack Overflow"
    st.displayStack();
    st.pop();
    st.displayStack();
    st.pop();
    st.displayStack();
    st.pop();
    st.displayStack();
    st.pop();
    return 0;
}