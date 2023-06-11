class SnapshotArray {
private:
    int s = 0;
    vector<map<int, int>> espalhado;
public:
    SnapshotArray(int length) {
        espalhado = vector (length, map<int, int> ());
    }
    
    void set(int index, int val) {
        espalhado [index][s] = val;
    }
    
    int snap() {
        return s++; // Só adiciona posteriormente
    }
    
    int get(int index, int snap_id) {
        for (auto it = espalhado [index].rbegin (); it != espalhado [index].rend (); it++)
            if (it->first <= snap_id)
                return it->second;
        return espalhado [index][0]; // Por exceção
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

