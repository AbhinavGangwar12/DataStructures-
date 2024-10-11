#include<iostream>
#include<stack>
#include<stdbool.h>
#include<string>
using namespace std;

bool is_num(char c ){
    if((c >= 'a') && (c <= 'z'))return true;
    else return false;
}

bool is_operator(char c ){
    return (c == '+' || c == '-' || c == '/' || c == '*') ? true : false;
}

int precedence(char c){
    if(c=='+' || c == '-')return 1;
    if(c == '*' || c == '/')return 2;
    else return -1;
}

string postFix(string x){
    stack<char> s;
    string ans = "";
    for(auto i : x){
        if(is_num(i))ans.push_back(i);
        
        if(i=='(')s.push(i);
        
        if(is_operator(i)){
            while((!s.empty()) && (precedence(s.top()) <= precedence(i))){
                char temp = s.top();
                ans.push_back(temp);
                s.pop();
            }
            s.push(i);
        }

        if(i == ')'){
            while((!s.empty()) && (s.top() != '(')){
                char temp = s.top();
                ans.push_back(temp);
                s.pop();
            }
            s.pop();
        }
    }
    while(!s.empty()){
        char temp = s.top();
        ans.push_back(temp);
        s.pop();
    }
    return ans;
}


int main(){
    string s = "a*b-(c+d)+e";
    // cout<<s<<endl;
    cout<<postFix(s)<<endl;

    return 0;
}
