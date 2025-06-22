#include <bits/stdc++.h>
using namespace std;

#define FAST_IO ios::sync_with_stdio(false); cin.tie(0);
typedef long long ll;

bool canForm(string s, string t) {
    int n = s.size(), m = t.size();

    for (int start = 0; start < n; ++start) {
        for (int rightSteps = 0; rightSteps < m && start + rightSteps < n; ++rightSteps) {
            string path = "";

            // move right and record
            for (int j = 0; j <= rightSteps; ++j)
                path += s[start + j];

            // now move left
            int remaining = m - path.size();
            int backIdx = start + rightSteps - 1;

            for (int k = 0; k < remaining && backIdx >= 0; ++k, --backIdx)
                path += s[backIdx];

            if (path == t) return true;
        }
    }
    return false;
}

int main() {
    FAST_IO;

    int test_cases;
    cin >> test_cases;
    while (test_cases--) {
        string s, t;
        cin >> s >> t;

        cout << (canForm(s, t) ? "YES" : "NO") << endl;
    }

    return 0;
}
