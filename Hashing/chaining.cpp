#include<iostream>
using namespace std;

class node{
    public:
        int key;
        string value;
        node * next;
        node(int k,string s){
            this->key = k;
            this->value = s;
            this->next = NULL;
        }
};

int hashFunc(int vlu){return vlu % 10;}

class Chaining {
    private : 
        node * head[10];
    public:
        Chaining (){
            for(int i=0;i<10;i++){this->head[i] = NULL;}
        }
        void insert(int,string);
        void delete_(int);
        node * search(int);
};

void Chaining :: insert(int key,string value){
    int pos = hashFunc(key);
    node * newNode = new node(key,value);
    if(this->head[pos] == NULL){
        this->head[pos] = newNode;
    }
    else {
        node * ptr = this->head[pos];
        node * tptr = NULL;
        while(ptr && ptr->key < key ){
            tptr = ptr;
            ptr = ptr->next;
        }
        if (tptr == NULL) {
            newNode->next = ptr;
            this->head[pos] = newNode;
        }
        else {
            tptr->next = newNode;
            newNode->next = ptr;
        }
    }
}

void Chaining :: delete_(int key){
    int pos = hashFunc(key);
    if(this->head[pos] == NULL)return;
    node * ptr = this->head[pos];
    node * tptr = NULL;
    while(ptr){
        if (ptr->key == key) {
            if (tptr == NULL) {
                this->head[pos] = ptr->next;
            }
            else {
                tptr->next = ptr->next;
            }
            delete ptr;
            return;
        }
        tptr = ptr;
        ptr = ptr->next;
    }
}


node * Chaining :: search(int key){
    int pos = hashFunc(key);
    if(this->head[pos] == NULL)return NULL;
    node * ptr = this->head[pos];
    while(ptr){
        if(ptr->key == key)return ptr;
        ptr = ptr->next;
    }
    return NULL;
}

int main(){
    Chaining chain;
    chain.insert(23,"Sumit");
    chain.insert(2,"Anil");
    chain.insert(34,"han");
    chain.insert(11,"Hello");
    node * s = chain.search(34);
    if(s == NULL)cout<<"Not found"<<endl;
    else {
        cout<<"key : "<<s->key<<endl<<"Name : "<<s->value<<endl;
    }
    chain.delete_(34);
    node * s_ = chain.search(34);
    if(s_ == NULL)cout<<"Not found"<<endl;
    else {
        cout<<"key : "<<s_->key<<endl<<"Name : "<<s_->value<<endl;
    }
    return 0;
}