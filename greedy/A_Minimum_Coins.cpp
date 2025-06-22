/*
Problem: A. Hit the Lottery
Topic: Greedy
Source: Codeforces (Mock from problem 996A)
URL: https://codeforces.com/problemset/problem/996/A
Date: 2025-06-22
Author: Mohit Assudani
*/

#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int coins[] = {100, 20, 10, 5, 1};
    int count = 0;

    for (int coin : coins) {
        count += n / coin;
        n %= coin;
    }

    cout << count << endl;
    return 0;
}
