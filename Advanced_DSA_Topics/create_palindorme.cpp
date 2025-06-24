#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
using namespace std;

int create_palindrome(int n, bool is_even) {
    int pal = n;
    if (!is_even) pal /= 10;
    while (pal > 0) {
        n = n * 10 + pal % 10;
        pal /= 10;
    }
    return n;
}

vector<int> palindromes(int n) {
    vector<int> pals;
    for (int len = 1; ; len++) {
        int start = pow(10, (len - 1) / 2);
        int end = pow(10, (len + 1) / 2);
        for (int half = start; half < end; half++) {
            int pal = create_palindrome(half, len % 2);
            if (pal > n) return pals;
            pals.push_back(pal);
        }
    }
}

int main() {
    int n = 100;
    vector<int> pals = palindromes(n);
    sort(pals.begin(), pals.end());
    cout << "Palindromes less than or equal to " << n << ":\n";
    for (int x : pals) {
        cout << x << " ";
    }
    return 0;
}
