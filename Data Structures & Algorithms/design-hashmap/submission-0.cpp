class MyHashMap {
public:
    map<int, int>mp;
    MyHashMap() {
        mp = map<int, int>();
    }
    
    void put(int key, int value) {
        mp[key] = value;
    }
    
    int get(int key) {
        return mp.count(key) == 0? -1: mp[key];
    }
    
    void remove(int key) {
        mp.erase(key);
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */