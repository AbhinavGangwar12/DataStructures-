#include<iostream>
#include<queue>
#include<stack>
using namespace std;

class node{
    public:
    int data;
    node * left_child;
    node * right_child;
    node(int val){
        this->data = val;
        this->left_child = NULL;
        this->right_child = NULL;
    }
};

node* make_binary_tree(node * root){
    
    cout<<"Enter data : ";
    int data;
    cin>>data;
    root = new node(data);
    if(data == -1)return NULL;
    
    cout<<"Enter data for left child of "<<data<<" : "<<endl;
    root->left_child = make_binary_tree(root->left_child);

    cout<<"Enter data for left child of "<<data<<" : "<<endl;
    root->right_child = make_binary_tree(root->right_child);
    
    return root;
}

void level_order(node* root){
    if(root == NULL)return;
    cout<<endl;
    queue<node*> temp;
    temp.push(root);
    temp.push(NULL);
    while(!temp.empty()){
        node * front = temp.front();
        temp.pop();
        if(front == NULL){
            cout<<endl;
            if(!temp.empty())temp.push(NULL);
        }
        else{
            cout<<front->data<<" ";
            if(front->left_child){
                temp.push(front->left_child);
            }
            if(front->right_child){
                temp.push(front->right_child);
            }
        }
    }
}

void in_order(node* root){
    if(root != NULL){
        in_order(root->left_child);
        cout<<root->data<<" ";
        in_order(root->right_child);
    }
}

void pre_order(node* root){
    if(root != NULL){
        cout<<root->data<<" ";
        in_order(root->left_child);
        in_order(root->right_child);
    }
}

void post_order(node* root){
    if(root != NULL){
        in_order(root->left_child);
        in_order(root->right_child);
        cout<<root->data<<" ";
    }
}

void rev_level_order(node * root){
    if(root==NULL)return;
    
    cout<<endl;
    
    stack<node*> temp;
    queue<node*> q;
    
    q.push(root);
    q.push(NULL);
    
    while(!q.empty()){
        node* curr = q.front();
        q.pop();
        temp.push(curr);
        
        if(curr == NULL){
            if(!q.empty())q.push(NULL);
        }
        else{
            if(curr->left_child)q.push(curr->left_child);
            if(curr->right_child)q.push(curr->right_child);
        }
    }

    while(!temp.empty()){
        if(temp.top() == NULL)cout<<endl;
        else cout<<temp.top()->data<<" ";
        temp.pop();
    }
}

//tree : { 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 }

int main(){
    node * root = NULL;
    root = make_binary_tree(root);
    
    cout<<endl<<"Level order Traversal : ";
    level_order(root);
    
    cout<<endl<<"Reversed Level order Traversal : ";
    rev_level_order(root);
    
    cout<<endl<<"In order Traversal : ";
    in_order(root);
    
    cout<<endl<<"Pre order Traversal : ";
    pre_order(root);
    
    cout<<endl<<"Post order Traversal : ";
    post_order(root);
    
    return 0;
}