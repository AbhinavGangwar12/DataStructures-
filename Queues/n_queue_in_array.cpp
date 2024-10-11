#include<iostream>
#include<vector>
using namespace std;

class NQueue{
    private:
        int total_size;
        int *front;
        int *rear;
        int *free_slots_map;
        int *arr;
        int next_free_slot;
    public:
        NQueue(int size, int nq){
            this->total_size = size;
            this->front = new int[nq];
            this->rear = new int[nq];
            for(int i = 0;i<3;i++){
                front[i] = -1;
                rear[i] = -1;
            }
            this->free_slots_map = new int[this->total_size];
            for(int i = 0;i<this->total_size;i++){
                free_slots_map[i] = i+1;
            }
            free_slots_map[this->total_size - 1] = -1;
            this->arr = new int[this->total_size];
            this->next_free_slot = 0;
        }
        void enqueue(int qn,int val){
            // Checking whether we have any space or not 
            if(this->next_free_slot == -1){
                cout<<"Queue is full"<<endl;
                return;
            }
            // extracting value of index where we can insert
            int index = this->next_free_slot;
            this->next_free_slot = this->free_slots_map[index];
            // Checking whether it's our first element or not
            if(this->front[qn-1] == -1)this->front[qn-1] = index;//if yes, then moving our front pointer to that index
            else this->free_slots_map[this->rear[qn-1]] = index;//otherwise, mapping the index of the next in rear's current index that where we have stored our next element
            this->free_slots_map[index] = -1;// since we are moving our rear pointer to the next index this means curr index will be occupied that is why we are assinging -1 to the index of curr element in the map 
            this->rear[qn-1] = index;//moving rear to the next element's index
            this->arr[index] = val;//inserting value
        }

        int dequeue(int qn){
            if(this->front[qn-1] == -1){
                cout<<"Queue is empty"<<endl;
                return-1;
            }
            int index = this->front[qn-1];
            front[qn-1] = this->free_slots_map[index];
            this->free_slots_map[index] = this->next_free_slot;
            this->next_free_slot = index;
            return this->arr[index];
        }

};


int main(){
    NQueue nqueue(10,3);
    nqueue.enqueue(1,4);
    nqueue.enqueue(2,1);
    nqueue.enqueue(2,9);
    nqueue.enqueue(1,5);
    cout<<nqueue.dequeue(1)<<endl;
    cout<<nqueue.dequeue(1)<<endl;
    cout<<nqueue.dequeue(2)<<endl;
    cout<<nqueue.dequeue(2)<<endl;
    cout<<nqueue.dequeue(2)<<endl;
    
    return 0;
}