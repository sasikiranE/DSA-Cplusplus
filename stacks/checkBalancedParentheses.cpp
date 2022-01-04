#include<bits/stdc++.h>

using namespace std;

bool checkBalancedParentheses(string &str) {
    unordered_map<char, int> ump = {
            {'(', 1},
            {')', -1},
            {'{', 2},
            {'}', -2},
            {'[', 3},
            {']', -3}
    };

    stack<char> st;
    for (int i = 0; i < str.size(); i++) {
        char c = str[i];
        if (ump[c] > 0) {
            st.push(c);
        } else {
            if (st.empty()) return false;
            if (ump[c] + ump[st.top()] != 0) return false;
            st.pop();
        }
    }
    return st.empty();
}

int main() {
    string exp = "{{[[()]]}}";
    cout << (checkBalancedParentheses(exp) ? "VALID" : "INVALID") << "\n";
    return 0;
}