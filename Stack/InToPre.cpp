#include<iostream>
#include<cstring>
using namespace std;
class Stack{
    private:
        int size;
        char * arr;
        int top;
    public:
        Stack(int size){
            this->size = size;
            arr = new char[this->size];
            top = -1;
        }
        char pop();
        char stackTop();
        void push(char);
        int isEmpty();
};
char Stack :: pop(){
    if(this->top<0)return '/';
    return this->arr[this->top--];
}

char Stack :: stackTop(){
    return this->arr[this->top];
    }
void Stack :: push(char key){
    if(top > this->size)return;
    this->top++;
    this->arr[this->top] = key;
}

int Stack :: isEmpty(){
    if(this->top < 1)return 1;
    return 0;
}

int precedence(char key){
    if(key == '+' || key == '-')return 1;
    if(key == '*' || key == '/')return 2;
    return 0;
}

int isOperand(char key){
    if(key == '+' || key == '-' || key == '*' || key == '/')return 0;
    return 1;
}

string prefix(string str){
    Stack st(str.length()+1);
    st.push('#');
    int i = str.length()-1;
    string pre="";
    while(i > 0){
        if(isOperand(str[i])){pre += str[i];i--;}
        else {
            if( precedence(str[i]) > precedence( st.stackTop() ) )st.push(str[i--]);
            else pre += st.pop();
        }
    }
    while(!(st.isEmpty())){
        pre += st.pop();
    }
    pre += '\0';
    return pre;
}
int main(){
    string infix = "a+b*c-d/e";
    string prefix_ = prefix(infix);
    cout<<"Infix : "<<infix<<endl<<"Prefix : ";
    for(int i = ( prefix_.length()-1 );i>=0;i--){cout<<prefix_[i];}
    cout<<endl;
    return 0;
}