// ADT of BST and basic code 
#include<iostream>
#include<stack>
using namespace std;
class node {
    public : 
        int data;
        node * right;
        node * left;
        node (int key){
            this->data = key;
            this->left = this->right = NULL;
        }
};

class BST{
    private:
        node * root;
    public:
        BST(){this->root = NULL;}
        node * root_(){return this->root;}
        void insert(int key);
        node * search(node *,int);
        void inorder();
        void preorder();
        void postorder(node *);
        int height(node *);
        node * prePredecessor(node * ptr){
            ptr = ptr->left;
            while(ptr->right!=NULL){
                ptr = ptr->right;
            }
            return ptr;
        }
        node * preSuccessor(node * ptr){
            ptr = ptr->right;
            while(ptr->right!=NULL){
                ptr = ptr->left;
            }
            return ptr;
        }
        node * deleteN(node *,int);
};
void BST :: insert(int key){
    node * ptr = this->root;
    node * tptr = NULL;
    if(this->root == NULL){
        node * newNode = new node (key);
        this->root = newNode;
        return;
    }
    while(ptr!=NULL){
        tptr = ptr;
        if(ptr->data == key)return;
        else if(ptr->data > key)ptr = ptr->left;
        else if(ptr->data < key)ptr = ptr->right;
    }
    node * newNode = new node(key);
    if(tptr->data > newNode->data)tptr->left = newNode;
    else tptr->right = newNode;
}
node * BST :: search(node * ptr,int key){
    if(ptr == NULL)return NULL;
    else if(ptr->data == key)return ptr;
    else if(ptr->data > key)return search(ptr->left,key);
    else return search(ptr->right,key);
}
void BST :: inorder(){
    stack <node *> st;
    node * ptr = this->root;
    cout<<"Inorder : ";
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
void BST :: preorder(){
    stack <node *> st;
    node * ptr = this->root;
    cout<<"PreOrder : ";
    while(ptr || !st.empty()){
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
void BST :: postorder(node * ptr){
    if(ptr == NULL)return;
    postorder(ptr->left);
    postorder(ptr->right);
    cout<<ptr->data<<" ";
}
int BST :: height(node * ptr){
    if(ptr == NULL)return 0;
    if(height(ptr->left) > height(ptr->right))return height(ptr->left) + 1;
    else return height(ptr->right) + 1;
}
node * BST :: deleteN(node * ptr,int key){
    node * temp;
    if(ptr == NULL)return NULL;
    if(ptr->left == NULL && ptr->right == NULL){
        if(ptr == this->root)this->root = NULL;
        delete ptr;
        return NULL;
    }
    if(ptr->data > key) ptr->left = this->deleteN(ptr->left,key);
    else if(ptr->data < key) ptr->right = this->deleteN(ptr->right,key);
    else {
        if( this->height(ptr->left) > this->height(ptr->right) ){
            temp = this->prePredecessor(ptr);
            ptr->data = temp->data;
            ptr->left = this->deleteN(ptr->left,temp->data);
        }
        else {
            temp = this->preSuccessor(ptr);
            ptr->data = temp->data;
            ptr->right = this->deleteN(ptr->right,temp->data);
        }
    }
    return ptr;
}
int main(){
    BST tree;
    tree.insert(5);
    tree.insert(3);
    tree.insert(6);
    tree.insert(1);
    tree.insert(8);
    tree.insert(2);
    tree.insert(9);
    tree.inorder();
    return 0;
}