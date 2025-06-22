/*
Problem: B. T-primes
Topic: Primes, Number Theory
URL: https://codeforces.com/problemset/problem/230/B
Date: 2025-06-22
Author: Mohit Assudani
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
typedef long long ll;

bool isPrime(ll num) {
    if (num < 2) return false;
    for (ll i = 2; i * i <= num; ++i) {
        if (num % i == 0) return false;
    }
    return true;
}

bool hasExactly3Divisors(ll n) {
    ll root = sqrtl(n); 
    return (root * root == n) && isPrime(root);
}


int main() {
    FAST_IO;

    int n;
    cin >> n;

    vector<ll> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    // Your logic here
    for (ll x : numbers) {
        // Write code to check if x is a T-prime

        if(hasExactly3Divisors(x)){
            cout<< "YES" << endl;
        }else{
            cout << "NO" << endl; 
        }
    }

    return 0;
}

