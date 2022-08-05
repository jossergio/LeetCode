class MyCalendar {
private:
    vector<pair<int, int>> lista;
    
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for (auto p = lista.begin (); p != lista.end (); p++)
            if (p->second > start && p->first < end)
                return false;
        // else
        
        lista.push_back ({start, end});
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

