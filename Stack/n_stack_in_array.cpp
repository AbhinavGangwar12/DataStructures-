#include<iostream>
using namespace std;

class N_stacks{
    private:
        int size_of_array;
        int *arr;
        int no_of_stacks;
        int *top;
        int *vacant_spaces;
        int free_slot;
    public:
        N_stacks(int size,int num){
            this->size_of_array = size;
            this->no_of_stacks = num;
            this->top = new int[this->no_of_stacks];
            this->vacant_spaces = new int[this->size_of_array];
            this->arr = new int[this->size_of_array];
            this->free_slot = 0;
            for(int i = 0;i<this->no_of_stacks;i++){
                this->top[i] = -1;
            }
            for(int i = 0;i<this->size_of_array;i++){
                this->arr[i] = -1;
            }
            for(int i = 0;i<this->size_of_array;i++){
                this->vacant_spaces[i] = i+1;
            }
            this->vacant_spaces[this->size_of_array-1] = -1;
        }
        void push(int stn,int val){
            // checking the condition for overflow
            if(this->free_slot == -1){
                cout<<"Stack Overflow"<<endl;
                return;
            }
            // taking the index where we can push the element 
            int index = this->free_slot;
            // updating the free slot since, vacant_spaces stores the next free slot available and the connection to the previous top of the stack
            this->free_slot = this->vacant_spaces[index];
            // storing the inidex of stack top where it is currently before any updation so that there can be a link between the elements of the stack
            this->vacant_spaces[index] = this->top[stn-1];
            // pushing the value inot the main array
            this->arr[index] = val;
            // updating the stack top
            this->top[stn-1] = index;
        }

        void pop(int stn){
            // condition check for stack underflow
            if(this->top[stn-1] == -1){
                cout<<"Stack "<<stn<<" Underflow"<<endl;
                return;
            }
            // taking out the current index of stack top
            int index = this->top[stn-1];
            // updating stack top to it's previous location as "vacant_spaces" stores the previous locations of the stacks as well
            this->top[stn-1] = this->vacant_spaces[index];
            // updating the current index in "vacant-spaces" as a free slot so that any other stack can utilize it
            this->vacant_spaces[index] = free_slot;
            // finally updating th free-slot with the current index
            this->free_slot = index;
            this->arr[index] = -1;
            cout<<"Element poped"<<this->arr[index]<<"from stack "<<stn<<endl;
        }
        void print_array(){
            cout<<"-1 represents vacant space"<<endl;
            for(int i = 0;i<this->size_of_array;i++){
                cout<<this->arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    N_stacks nst(10,3);
    nst.push(1,2);
    nst.push(1,3);
    nst.push(2,4);
    nst.push(2,6);
    nst.push(1,2);
    nst.push(3,8);
    nst.push(2,0);
    nst.print_array();
    nst.pop(1);
    nst.pop(2);
    nst.pop(2);
    nst.pop(3);
    nst.print_array();
    nst.pop(3);
    return 0;
}