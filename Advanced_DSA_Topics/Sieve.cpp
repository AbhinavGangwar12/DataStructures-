#include<iostream>
#include<vector>
using namespace std;

void print_primes(const int &num){
  vector<bool> primes(num+1,true);
  for(int i = 2;i*i <= num;i++){
    if(primes[i]){
      for(int j = i+i;j<=num;j+=i){
        primes[j] = false;
      }
    }
  }
  int count = 0;
  for(int i = 2;i<=num;i++){
    if(primes[i]){
        cout<<i<<" ";
        count++;
    }
  }
  cout<<endl<<count<<endl;
}
int main(){
  print_primes(100);
  return 0;
}
