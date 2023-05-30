class MyHashSet {
public:
    bitset<1000001> bit;
    MyHashSet() {
        
    }
    
    void add(int key) {
        bit.set(key);
    }
    
    void remove(int key) {
        if(bit[key] & 1) bit.flip(key);
    }
    
    bool contains(int key) {
        if(bit[key]&1) return true;
        return false;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */