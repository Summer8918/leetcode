/*
 * 282. Expression Add Operators
 *https://leetcode.com/problems/expression-add-operators/
 Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.

Example 1:

Input: num = "123", target = 6
Output: ["1+2+3", "1*2*3"]

Example 2:

Input: num = "232", target = 8
Output: ["2*3+2", "2+3*2"]

Example 3:

Input: num = "105", target = 5
Output: ["1*0+5","10-5"]

Example 4:

Input: num = "00", target = 0
Output: ["0+0", "0-0", "0*0"]

Example 5:

Input: num = "3456237490", target = 9191
Output: []

Constraints:

    0 <= num.length <= 10
    num only contain digits.

 * */
class Solution {
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        dfs(num, target, 0, 0, 0, "", res);
        return res;
    }
private:
    void dfs(const string &num, const int target, const int pos, long cumulative_val, long previous_val, string tmp, vector<string> &res) {
        if (pos == num.length() && cumulative_val == target) {
            res.push_back(tmp);
            return;
        }
        for (int i = 1; i <= num.length() - pos; ++i) {
            string t = num.substr(pos, i);
            if (i > 1 && t[0] == '0') {
                continue;
            }
            long n = stol(t);
            if (pos == 0) {
                dfs(num, target, i, n, n, t, res);
            } else {
                dfs(num, target, pos + i, cumulative_val + n, n, tmp + "+" + t, res);
                dfs(num, target, pos + i, cumulative_val - n, -n, tmp + "-" + t, res);
                dfs(num, target, pos + i, cumulative_val - previous_val + previous_val * n, previous_val * n, tmp + "*" + t, res);
            }
        }
    }
};
