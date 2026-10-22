class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        std::queue<int> q;
        int n = students.size();
        int k = n;

        for (int student : students){
            q.push(student);
        }

        for (int i = 0; i < n; ++i){
            int temp = 0;
            while(q.front() != sandwiches[i] && temp < q.size()){
                q.push(q.front());
                q.pop();
                temp ++;
            }
            if (q.front() != sandwiches[i]){
                break;
            }
            q.pop();
            k--;
            }
        return k;
    }
};