class SnapshotArray {
public:
    unordered_map<int,map<int,int>> mp;
    int snap_id = 0;
    SnapshotArray(int length) {
        
    }
    
    void set(int index, int val) {
        mp[index][snap_id] = val;
    }
    
    int snap() {
        return snap_id++;
    }
    
    int get(int index, int snap_id) {
        auto it = mp[index].upper_bound(snap_id);
        return it == mp[index].begin()?0: prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */