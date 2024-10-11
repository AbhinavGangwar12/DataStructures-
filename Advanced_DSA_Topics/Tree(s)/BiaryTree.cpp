
// Binary tree creation

#include<iostream>
#include<queue>
#include<stack>

using namespace std;

class node{
    public:
        int data;
        node * right;
        node * left;
        node (int val){
            this->data = val;
            this->right = this->left = NULL;
        }
};

class Tree{
    private:
        node * rootNode;
        node * traversingPointer;
    public:
        Tree(){this->rootNode = NULL;this->traversingPointer = this->rootNode;}
        void createBinT();
        void preOrder();
        void inOrder();
        void preOrderR(node *);
        void postOrderR(node *);
        int sum(node *);
        int height(node *);
        node * ptr(){
            return this->traversingPointer;
        }
        int count(node *);
};

void Tree :: createBinT(){
    cout<<"Enter -1 when no child."<<endl;
    queue <node *> q;
    node * ptr;
    int key;
    cout<<"Enter root value : ";
    cin>>key;
    node * newNode = new node(key);
    rootNode = newNode;
    q.push(rootNode);
    while(!q.empty()){
        ptr = q.front();
        q.pop();
        int x;
        cout<<"Enter left child for "<<ptr->data<<" : ";
        cin>>x;
        if(x!=-1){
            node * temp = new node(x);
            ptr->left = temp;
            q.push(temp);
        }
        cout<<"Enter right child for "<<ptr->data<<" : ";
        cin>>x;
        if(x!=-1){
            node * temp = new node(x);
            ptr->right = temp;
            q.push(temp);
        }
    }
    this->traversingPointer = this->rootNode;
}

void Tree :: preOrder(){
    node * ptr = this->rootNode;
    stack <node *> st;
    while(ptr!=NULL || !st.empty()){
        if(ptr){
            cout<<ptr->data<<" ";
            st.push(ptr);
            ptr = ptr->left;
        }
        else {
            ptr = st.top();
            st.pop();
            ptr = ptr->right;
        }
    }
    cout<<endl;
}

void Tree :: inOrder(){
    node * ptr = this->rootNode;
    stack <node *> st;
    while(ptr!=NULL || !st.empty()){
        if(ptr){
            st.push(ptr);
            ptr = ptr->left;
        }
        else {
            ptr = st.top();
            st.pop();
            cout<<ptr->data<<" ";
            ptr = ptr->right;
        }
    }
    cout<<endl;
}

void Tree :: preOrderR(node * ptr){
    if(ptr == NULL)return;
    cout<<ptr->data<<" ";
    preOrderR(ptr->left);
    preOrderR(ptr->right);
}

void Tree :: postOrderR(node * ptr){
    if(ptr == NULL)return;
    preOrderR(ptr->left);
    preOrderR(ptr->right);
    cout<<ptr->data<<" ";
}

int Tree :: count(node * ptr){
    if(ptr == NULL)return 0;
    return count(ptr->left) + count(ptr->right) + 1;
}

int Tree :: sum(node * ptr){
    if(ptr == NULL)return 0;
    return sum(ptr->left) + sum(ptr->right) + ptr->data;
}

int Tree :: height(node * ptr){
    if(ptr == NULL)return 0;
    if(height(ptr->left) > height(ptr->right))return height(ptr->left) + 1;
    else return height(ptr->right) + 1;
}

int main(){
    Tree t;
    t.createBinT();
    cout<<"Inorder : ";
    t.inOrder();
    cout<<"Preorder : ";
    t.preOrderR(t.ptr());
    cout<<endl;
    cout<<"Postorder : ";
    t.postOrderR(t.ptr());
    cout<<endl;
    cout<<"Number of nodes : "<<t.count(t.ptr());
    cout<<endl<<"Sum : "<<t.sum(t.ptr());
    cout<<endl<<"Height : "<<t.height(t.ptr());
    return 0;
}