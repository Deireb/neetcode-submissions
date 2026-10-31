class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }

        unordered_map<char, int> freq_s;
        unordered_map<char, int> freq_t;
        for (const auto& c : s){
            ++freq_s[c];
        }

        for (const auto& c : t){
            ++freq_t[c];
        }

        for (char c : s){
            if (freq_t[c] != freq_s[c]){
                return false;
            }
        }
        return true;
    }
};
