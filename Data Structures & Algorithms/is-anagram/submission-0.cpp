class Solution {
public:
    bool isAnagram(string s, string t) {
        std::unordered_map<char, int> freq_s;
        std::unordered_map<char, int> freq_t;

        for (const char& c : s){
            ++freq_s[c];
        }
        for (const char& c : t){
            ++freq_t[c];
        }

        if (freq_s.size() != freq_t.size()){
            return false;
        }

        for(int i = 0; i < freq_s.size(); ++i){
            if (freq_s[i] != freq_t[i]){
                return false;
            }
        }
        return true;
    }
};
