/*
Problem: C. Sum in Binary Tree (DFS style)
URL: https://codeforces.com/problemset/problem/1843/C
Topic: Binary Tree, Math, DFS
Date: 2025-06-22
Author: Mohit Assudani
*/

#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
typedef long long ll;

// DFS function to compute sum of v and its ancestors
ll dfs(ll v) {
    if (v == 0) return 0;
    return v + dfs(v / 2);  // current + parent path
}

int main() {
    FAST_IO;

    int t;
    cin >> t;

    while (t--) {
        ll v;
        cin >> v;
        cout << dfs(v) << endl;
    }

    return 0;
}
