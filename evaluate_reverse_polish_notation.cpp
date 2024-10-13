// 150. Evaluate Reverse Polish Notation: https://leetcode.com/problems/evaluate-reverse-polish-notation/description/
// stack, medium


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> res;
        string operand1, operand2;
        int resOfOp;

        for(auto val : tokens)
        {
            if(val == "+" || val == "-" || val == "*" || val == "/")
            {
                operand2 = res.top();
                res.pop();
                operand1 = res.top();
                res.pop();

                if(val == "+") resOfOp = stoi(operand1) + stoi(operand2);
                else if(val == "-") resOfOp = stoi(operand1) - stoi(operand2);
                else if(val == "*") resOfOp = stoi(operand1) * stoi(operand2);
                else if(val == "/") resOfOp = stoi(operand1) / stoi(operand2);

                res.push(to_string(resOfOp));
            }
            else res.push(val);
        }
        return stoi(res.top());
    }
};