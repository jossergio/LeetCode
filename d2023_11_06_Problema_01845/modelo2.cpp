class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> assentos;
public:
    SeatManager(int n) {
        for (int i = 1; i <= n; i += 1)
            assentos.push (i);
    }
    
    int reserve() {
        int tmp = assentos.top ();
        assentos.pop ();
        return tmp;
    }
    
    void unreserve(int seatNumber) {
        assentos.push (seatNumber);
    }
};

/**
 * Your SeatManager object will be instantiated and called as such:
 * SeatManager* obj = new SeatManager(n);
 * int param_1 = obj->reserve();
 * obj->unreserve(seatNumber);
 */
 
