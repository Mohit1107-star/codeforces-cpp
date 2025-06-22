/*
Problem: E. Kefa and First Steps (DP version)
Topic: Arrays, DP
URL: https://codeforces.com/problemset/problem/580/A
Date: 2025-06-22
Author: Mohit Assudani
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);

int main() {
    FAST_IO;

    int n;
    cin >> n;
    vector<int> a(n);
    for (int& x : a) cin >> x;

    vector<int> dp(n, 1);  // Base case: every element is a segment of length 1
    int maxLen = 1;

    for (int i = 1; i < n; ++i) {
        if (a[i] >= a[i - 1]) {
            dp[i] = dp[i - 1] + 1;
        } else {
            dp[i] = 1;
        }
        maxLen = max(maxLen, dp[i]);
    }

    cout << maxLen << endl;
    return 0;
}
