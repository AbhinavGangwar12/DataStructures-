#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000007
#define SIZE 1000000

vector<long long> factorial(SIZE+1);
vector<long long> inv_fact(SIZE+1);


long long mod_exp(long long base, long long exp, long long mod) {
    long long result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % mod;
        }
        base = (base * base) % mod;
        exp /= 2;
    }
    return result;
}

void fact() {
    factorial[0] = 1;
    for (int i = 1; i <= SIZE; i++) {
        factorial[i] = (factorial[i-1] * i) % MOD;
    }
    inv_fact[SIZE] = mod_exp(factorial[SIZE], MOD-2, MOD);
    for (int i = SIZE-1; i >= 0; i--) {
        inv_fact[i] = (inv_fact[i+1] * (i+1)) % MOD;
    }
}

int main() {
    int n = 4;
    int r = 2;
    fact();
    long long result = (factorial[n] * inv_fact[n-r] % MOD * inv_fact[r] % MOD) % MOD;
    cout << result << endl;
    return 0;
}
