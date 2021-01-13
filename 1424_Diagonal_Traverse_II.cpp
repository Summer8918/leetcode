/*
1424. Diagonal Traverse II
question desription:
https://leetcode.com/problems/diagonal-traverse-ii/
explain:
https://leetcode.com/problems/diagonal-traverse-ii/discuss/597741/Clean-Simple-Easiest-Explanation-with-a-picture-and-code-with-comments
Key Idea
In a 2D matrix, elements in the same diagonal have same sum of their indices.
*/
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        vector<int> res;
        map<int, vector<int>> m;
        int max_index = 0;
        for (int i = 0; i < nums.size(); ++i) {
            for (int j = 0; j < nums[i].size(); ++j) {
                m[i + j].push_back(nums[i][j]);
                max_index = max(i + j, max_index);
            }
        }
        for (int i = 0; i <= max_index; ++i) {
            for (auto it = m[i].rbegin(); it != m[i].rend(); ++it) {
                res.push_back(*it);
            }
        }
        return res;
    }
};
