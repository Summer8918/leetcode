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

//BFS
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        int m = nums.size();
		vector<int> ans;
        queue<pair<int, int>> q;
        q.push({0,0}); // first row, first cell
		// BFS
        while (!q.empty()) {
            pair<int, int> p = q.front();
            q.pop();
            ans.push_back(nums[p.first][p.second]);

			// insert the element below, if in first column
            if (p.second == 0 && p.first+1 < m) q.push({p.first+1, p.second});

			// insert the right neighbour, if exists
            if (p.second+1 < nums[p.first].size())
                q.push({p.first, p.second+1});
        }
        return ans;
    }
};
