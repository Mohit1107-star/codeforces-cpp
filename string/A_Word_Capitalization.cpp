/*
Problem: A. Word Capitalization
Topic: String
Source: Codeforces 
URL: https://codeforces.com/problemset/problem/281/A
Date: 2025-06-23
Author: Mohit Assudani
*/

#include <iostream>
using namespace std;

int main() {
    string s;
    cin >> s;

    if (s.length() > 0 && s[0] >= 'a' && s[0] <= 'z') {
        s[0] = s[0] - 'a' + 'A';  // Convert lowercase to uppercase
    }

    cout << s << endl;
    return 0;
}
