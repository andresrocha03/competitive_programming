//Problem: given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//Solution, use a stack to keep track of opening brackets and ensure they are properly closed in the correct order.

class Solution {
public:
    bool isValid(string s) {
        set<char> open = {'[','{','('};
        map<char,char> match = {{')', '('},{']','['},{'}','{'}};

        stack<char> pilha;

        for (auto i : s) {
            cout << i;
            if (open.count(i) > 0) pilha.push(i);
            else {
                if (!pilha.empty() && pilha.top() == match[i]) pilha.pop();
                else {
                    return false;
                }
            }    
        
        }

        if (!pilha.empty()) return false;

        return true;

    }
};
