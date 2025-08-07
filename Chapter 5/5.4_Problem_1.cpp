#include <bits/stdc++.h>
using namespace std;
bool is_alpha(char ch) {
return ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z'));
}
bool is_alpha_num(char ch) {
return ((ch >= 'a' and ch <= 'z') or (ch >= 'A' and ch <= 'Z') or
(ch >= '0' and ch <= '9'));
}
bool check(string s) {
if (not is_alpha(s[0]) and s[0] != '_') {
return false;
}
for (int i = 1; i < s.size(); ++i) {
if (not is_alpha_num(s[i]) and s[i] != '_') {
return false;
}
}
return true;
}
int main() {
vector<string> keywords = {
"auto", "break", "case", "char",
"const", "continue", "default", "do",
"double", "else", "enum", "extern",
"float", "for", "goto", "if",
"int", "long", "register", "return",
"short", "signed", "sizeof", "static",
"struct", "switch", "typedef", "union",
"unsigned", "void", "volatile", "while"
};
string s;
getline(cin, s);
for (auto u: keywords) {
if (u == s) {
cout << s << " is a keyword.\n";
return 0;
}
}
if (check(s)) {
cout << s << " is not a keyword but it is a valid
identifier.\n";
} else {
cout << s << " is not a keyword neither a valid
identifier.\n";
}
return 0;
}