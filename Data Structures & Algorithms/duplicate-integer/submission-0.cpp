class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        /*
        Return true if a value appears more than once, otherwise return false

        // Time complexity O(n)
        // Space complexity O(n)
        */
        std::unordered_map<int, int> freq;

        for (const int num : nums){
            ++freq[num];
            if (freq[num] > 1){
                return true;
            }
        }
        return false;
    }
};