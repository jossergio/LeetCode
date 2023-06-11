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
        int atual = snap_id;
        while (atual > 0 && espalhado [index].count (atual) == 0)
            atual -= 1;
        return espalhado [index][atual];
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */

