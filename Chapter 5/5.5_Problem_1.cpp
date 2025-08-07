#include <bits/stdc++.h>
using namespace std;

bool is_alpha(char ch) {
    return isalpha(ch); // A-Z or a-z
}

bool is_alpha_num(char ch) {
    return isalnum(ch); // A-Z, a-z, 0-9
}

bool check(string s) {
    if (!is_alpha(s[0]) && s[0] != '_') return false;
    for (int i = 1; i < s.length(); ++i) {
        if (!is_alpha_num(s[i]) && s[i] != '_') return false;
    }
    return true;
}

int main() {
    vector<string> keywords = {
        "auto", "break", "case", "char", "const", "continue",
        "default", "do", "double", "else", "enum", "extern",
        "float", "for", "goto", "if", "int", "long", "register",
        "return", "short", "signed", "sizeof", "static", "struct",
        "switch", "typedef", "union", "unsigned", "void", "volatile", "while"
    };

    string s;
    getline(cin, s);

    if (find(keywords.begin(), keywords.end(), s) != keywords.end()) {
        cout << s << " is a keyword.\n";
    } else if (check(s)) {
        cout << s << " is not a keyword but it is a valid identifier.\n";
    } else {
        cout << s << " is not a keyword nor a valid identifier.\n";
    }

    return 0;
}
