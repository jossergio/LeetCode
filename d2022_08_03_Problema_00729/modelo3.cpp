class MyCalendar {
private:
    vector<pair<int, int>> lista;
    
    static bool ordenar (pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        for (vector<pair<int, int>>::iterator i = lista.begin (); i != lista.end (); i++)
            if (i->first < end && i->second > start)
                return false;
        // else
        
        lista.push_back ({start, end});
        sort (lista.begin (), lista.end (), ordenar);
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

