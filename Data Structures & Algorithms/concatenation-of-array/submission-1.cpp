class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        // Time complexity O (n)
        // Space complexity O(n)
        int n = nums.size();
        vector<int> ans(2 * n);
        for(int i = 0; i < n; ++i){
            ans[i] = ans[i + n] = nums[i];
        }
        return ans;
    }
};