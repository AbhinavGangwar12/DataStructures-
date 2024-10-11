#include<iostream>
using namespace std;
class node{
    public:
        int data;
        node *next, *prev;
        node(int key){
            this->data = key;
            this->prev = this->next = NULL;
        }
};
class queue{
    private:
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
        void display();
};
void queue :: insert(int key){
    if(this->count >= size){
        cout<<"Queue is full."<<endl;
        return;
    }
    node * newNode = new node(key);
    if(this->head == NULL){
        this->head = newNode;
        this->count++;
        return;
    }
    if(!(this->head->next)){
        if(this->head->data < newNode->data){
            this->head->next = newNode;
            newNode->prev = this->head;
            this->count++;
            return;
        }
        else if(this->head->data > newNode->data){
            newNode->next = this->head;
            this->head->prev = newNode;
            this->head = newNode;
            this->count++;
            return;
        }
    }
    node * ptr = this->head;
    while(ptr->next){ptr = ptr->next;}
    while(ptr){
        if(ptr->data > newNode->data){
            node * temp = ptr;
            if(ptr->prev){
                ptr = ptr->prev;
                ptr->next = NULL;
            }
            else {
                ptr = NULL;
                // ptr->next = ptr->prev = NULL;
            }
            delete temp;
            this->count--;
        }
        else if(ptr->data == newNode->data){
                return;
        }
        else break;
    }
    if(ptr == NULL){
        this->head = newNode;
        this->count++;
        return;
    }
    ptr->next = newNode;
    newNode->prev = ptr;
    while(ptr->prev){ptr = ptr->prev;}
    this->head = ptr;
    this->count++;
}
int queue :: deletB(){
    if(this->count < 1){
        cout<<"Queue is empty."<<endl;
        return -1;
    }
    if(!(this->head->next)){
        node * temp = this->head;
        this->head = NULL;
        int ret = temp->data;
        delete temp;
        this->count--;
        return ret;
    }
    node * ptr = this->head;
    while(ptr->next){ptr = ptr->next;}
    node * temp = ptr;
    ptr = ptr->prev;
    ptr->next = NULL;
    int ret = temp->data;
    delete temp;
    this->count--;
    return ret;
}
int queue :: deletF(){
    if(this->count < 1){
        cout<<"Queue is empty."<<endl;
        return -1;
    }
    if(this->head->next == NULL){
        node * temp = this->head;
        this->head = NULL;
        int ret = temp->data;
        delete temp;
        this->count--;
        return ret;
    }
    node * temp = this->head;
    this->head = this->head->next;
    this->head->prev = NULL;
    int ret = temp->data;
    delete temp;
    this->count--;
    return ret;
}
void queue :: display(){
    if(this->count < 1){
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
int main(){
    queue q(4);
    q.insert(1);
    q.insert(2);
    q.insert(4);
    q.insert(0);
    q.display();
    q.display();
    cout<<q.deletF()<<endl;
    // q.display();
    return 0;
}