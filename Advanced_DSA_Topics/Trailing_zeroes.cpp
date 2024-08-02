#include<iostream>
using namespace std;

int zeroes(const int &num){
  int zeroes = 0;
  for(int i = 5;i<=num;i*=5){
    zeroes+=num/i;
  }
  return zeroes;
}
int main(){
  return 0;
}
