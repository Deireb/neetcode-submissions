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

            if (x == y){ // Same weight stones
                continue;
            }
            else if (y < x){ // First stone weight more than second
                heap.push(x - y);
            }
        }
        return !heap.empty() ? heap.top() : 0;
    }
};
