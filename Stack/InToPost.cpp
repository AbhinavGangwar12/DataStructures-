#include<iostream>
#include<stdlib.h>
using namespace std;
class Stack{
    int size;
    char * st,top;
    public:
        Stack(int sz){
            this->size = sz;
            st = new char[size];
            top = -1;
        }
        void push(char);
        char pop();
        char stackTop();
        int isEmpty();
};
void Stack :: push(char key){
    if(top > size)return;
    top++;
    st[top] = key;
}
char Stack :: pop(){
    if(top < 1){return '/';}
    return st[top--];
}
char Stack :: stackTop(){
    return st[top];
}
int Stack :: isEmpty(){
    if(top < 1)return 1;
    return 0;
}
int pre(char key){
    if(key == '+' || key == '-')return 1;
    if(key == '*' || key == '/')return 2;
    return 0;
}
int isOperand(char key){
    if(key == '+' || key == '-' || key == '*' || key == '/')return 0;
    return 1;
}
string InToPost(string str){
    Stack s(sizeof(str));
    s.push('#');
    string postfix = "";
    int i=0;
    while(str[i]!='\0'){
        if(isOperand(str[i])){
            postfix += str[i];
            i++;
        }
        else {
            if(pre(str[i])>pre(s.stackTop()))s.push(str[i++]);
            else {postfix += s.pop();}
        }
    }
    while(!(s.isEmpty())){
        postfix += s.pop();
    }
    postfix+='\0';
    return postfix;
}

int main(){
    string s = InToPost("a+b*c-d/e");
    cout<<s;
    return 0;
}