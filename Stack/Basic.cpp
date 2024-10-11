#include<iostream>
#include<stdbool.h>
using namespace std;

class stack{
    int * arr;
    int top;
    int size;
    public:
        stack(int n){
            size = n;
            arr = new int[size];
            top = -1;
        }
        void push(int);
        int pop();
        int stackTop();
        bool isEmpty();
        bool isFull();
};

void stack :: push(int val){
    if(top >= size-1){
        cout<<"Stack overflow"<<endl;
        return;
    }
    arr[++top] = val;
}

int stack :: pop(){
    if(top<0){
        cout<<"Stack Underflow"<<endl;
        return -1;
    }
    return arr[top--];
}

int stack :: stackTop(){
    if(top < 0 || top >= size-1)return -1;
    return arr[top];
}

bool stack :: isEmpty(){
    if(top<0)return true;
    return false;
}

bool stack :: isFull(){
    if(top>=size-1)return true;
    return false;
}
// int main(){
//     return 0;
// }