#include<iostream>
using namespace std;
void prime_factors(int num){
  if(num <= 1)return;
  while(num%2==0){
    cout<<2<<" ";
    num /= 2;
  }
  while(num%3==0){
    cout<<3<<" ";
    num /= 3;
  }
  for(int i = 5;i <= num;i+=6){
    while(num%i==0){
      cout<<i<<" ";
      num /= i;
    }
    while(num%(i+2)==0){
      cout<<i+2<<" ";
      num /= (i+2);
    }
  }
  if(num > 3)cout<<num;
}
int main(){
  prime_factors(84);
  cout<<endl;
  return 0;
}
