class MyHashMap {
public:
    MyHashMap() {
        hashMap.resize(maxen, -1);
    }
    
    void put(int key, int value) {
        hashMap[key] = value;
    }
    
    int get(int key) {
        return hashMap[key];
    }
    
    void remove(int key) {
        hashMap[key] = -1;
    }
    
private:
    std::vector<uint32_t> hashMap;
    const uint32_t maxen = 1e6 + 7;
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */