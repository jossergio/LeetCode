class MyCalendar {
private:
    vector<bool> lista;
public:
    MyCalendar() {
        
    }
    
    bool book(int start, int end) {
        
        if (lista.size () < end)
            lista.resize (end, false);
        
        for (int i = start; i < end; i++)
            if (lista [i])
                return false;
        // else
        
        for (int i = start; i < end; i++)
            lista [i] = true;
        
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */

