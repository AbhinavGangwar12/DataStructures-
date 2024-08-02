#include<iostream>
using namespace std;
int power(const int num,const int p){
  if(p == 0)return 1;
  int temp = power(num,p/2);
  temp *= temp;
  if(p&2)return temp;//p%2==0-->p&2
  else return num*temp;
}
int main(){

  cout<<power(2,5);
  return 0;
}
