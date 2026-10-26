class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> heap;

        for (int stone : stones){ 
            heap.push(stone);
        }

        while (heap.size() > 1){
            int x = heap.top(); // First stone
            heap.pop();
            int y = heap.top(); // Second stone
            heap.pop();

            if (x == y){
                continue;
            }
            else if (y < x){
                heap.push(x - y);
            }
        }
        return !heap.empty() ? heap.top() : 0;
    }
};
