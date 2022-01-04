#include<bits/stdc++.h>

using namespace std;

// Reverse a string using stack.
string reverseString(string &str) {
    string ans;
    stack<char> st;
    for (char c: str) {
        st.push(c);
    }
    while (!st.empty()) {
        char c = st.top();
        st.pop();
        ans.push_back(c);
    }
    return ans;
}

int main() {
    string name = "Sasi Kiran";
    cout << reverseString(name) << "\n";
    return 0;
}