class SeatManager {
private:
    priority_queue<int, vector<int>, greater<int>> assentos;
    int proximo = 1; // 1-begin
public:
    SeatManager(int n) {
        
    }
    
    int reserve() {
        int tmp;
        if (assentos.empty ())
            tmp = proximo++; // Já incrementa
        else {
            tmp = assentos.top ();
            assentos.pop ();
        }
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
 
