//Problem: compute the value of an arithmetic expression in Reverse Polish Notation
//Solution: use a stack to store operands and execute the operations when an operator is encountered
//O(n) time complexity, O(n) space complexity

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> operands;
        unordered_set<string> operators = {"+", "-", "/", "*"};
        int answer;

        for (auto item : tokens) {
            if (operators.count(item)) {
                int x = operands.top();
                operands.pop();
                int y = operands.top();
                operands.pop();
                int res;

                if (item == "+") {
                        res = y+x;
                } else if (item == "-")  {
                    res = y-x;
                }
                else if (item == "*") {
                    res = y*x;
                }     
                else if (item == "/") {
                    res = y/x;
                }
                operands.push(res);
            } 
            else {
                operands.push(stoi(item));
            }
        }

        return operands.top();
    }
};
