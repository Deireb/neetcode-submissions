class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> heap;

    KthLargest(int k, vector<int>& nums) {
        this -> k = k; // pasamos la variable k del constructor a la variable de clase
        for (int num : nums){
            add(num);
        }
    }
    
    int add(int val) {
        heap.push(val); // añadimos valor al heap

        if (heap.size() > k){ // Nos quedamos con los k mayores valores (5, 12, 14, 16) elimina 16 para k = 3
            heap.pop(); 
        }

        return heap.top(); // Nos quedamos con el tercero más grande (5, 12, 14)
    }
};
