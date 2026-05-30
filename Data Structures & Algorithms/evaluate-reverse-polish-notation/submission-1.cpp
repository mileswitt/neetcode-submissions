class Solution {
public:
    int evalRPN(vector<string>& tokens) {

        stack<int> res;
        int temp = 0;
        int temp2 = 0;

        for (int i = 0; i<tokens.size(); i++) {
            if (check(tokens[i]) == false) {
                res.push(stoi(tokens[i]));
            } else {
                temp = res.top();
                res.pop();
                temp2 = res.top();
                res.pop();
                if (tokens[i] == "+") {
                    res.push(temp2 + temp);
                } else if (tokens[i] == "-") {
                    res.push(temp2 - temp);
                } else if (tokens[i] == "*") {
                    res.push(temp2 * temp);
                } else if (tokens[i] == "/") {
                    res.push(temp2 / temp);
                }
            }
        }
        return res.top();

        
    }

    bool check(const string& value) {
        return value == "+" || value == "-" || value == "*" || value == "/";
    }
};
