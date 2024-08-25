class SnapshotArray {
public:

    int m_snap_id;
    vector<vector<pair<int,int>>> history;


    SnapshotArray(int length) {
        m_snap_id = 0;
        history.resize(length);
        for(int i=0; i< length; ++i){
            history[i].push_back(make_pair(0,0));
        }
    }
    
    void set(int i, int val) {
        history[i].push_back(make_pair(m_snap_id, val));
    }
    
    int snap() {
        return m_snap_id++;
    }
    
    int get(int i, int snap_id) {
        auto it = upper_bound(history[i].begin(), history[i].end(), make_pair(snap_id, INT_MAX));
        return prev(it)->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */
