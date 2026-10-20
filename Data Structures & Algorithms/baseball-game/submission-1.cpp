#include <cctype>   

class Solution {
public:
    int calPoints(vector<string>& operations) {
        // Time complexity: O(n)
        // Space complexity: O(n)
        vector<int> record;
        int n = record.size();

        for (const string& op : operations){
            if(op == "+"){
                int sum = record.back() + record[record.size() - 2];
                record.push_back(sum);
            }
            else if(op == "D"){
                record.push_back(2 * record.back());
            }
            else if(op == "C"){
                record.pop_back();
            } 
            else{
                record.push_back(stoi(op));
            }
        }
        return accumulate(record.begin(), record.end(), 0);
    }
};