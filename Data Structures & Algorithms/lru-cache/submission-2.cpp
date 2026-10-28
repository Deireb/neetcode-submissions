class LRUCache {
public:
    std::unordered_map<int, std::pair<int, list<int>::iterator>> cache;
    /*
    Time complexity: O(1)
    Space complexity: O(n)
    */
    list<int> order;
    int capacity;
    LRUCache(int capacity) {
        this -> capacity = capacity;
    }
    
    int get(int key) {
        auto it = cache.find(key);
        if (it == cache.end()){
            return -1;
        }
        order.erase(cache[key].second);
        order.push_back(key);
        cache[key].second = --order.end();
        return cache[key].first;
    }
    
    void put(int key, int value) {
        auto it = cache.find(key);
        if (it != cache.end()){
            order.erase(cache[key].second);
        }
        else if(cache.size() == capacity){
            int lru = order.front();
            order.pop_front();
            cache.erase(lru);
        }
        order.push_back(key);
        cache[key] = {value, --order.end()};
    }
};
