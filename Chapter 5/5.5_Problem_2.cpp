#include <bits/stdc++.h>
using namespace std;

bool simulateDFA(string s) {
    int state = 0;

    for (char ch : s) {
        if (ch != '0' && ch != '1') return false;

        switch (state) {
            case 0:
                state = (ch == '0') ? 1 : 0;
                break;
            case 1:
                state = (ch == '0') ? 1 : 2;
                break;
            case 2:
                state = (ch == '0') ? 1 : 0;
                break;
        }
    }

    return state == 2;
}

int main() {
    string input;
    cin >> input;

    if (simulateDFA(input)) {
        cout << "Accepted: String ends with '01'\n";
    } else {
        cout << "Rejected\n";
    }

    return 0;
}
