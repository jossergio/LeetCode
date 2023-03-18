class BrowserHistory {
protected:
    stack<string> hs;
    stack<string> fw;
public:
    BrowserHistory(string homepage) {
        hs.push (homepage);
    }
    
    void visit(string url) {
        hs.push (url);
        while (!fw.empty ()) // Esvaziar fw; ou redefinir
            fw.pop ();
    }
    
    string back(int steps) {
        while (hs.size () > 1 && steps > 0) { // Não pode tirar o primeiro elemento
            fw.push (hs.top ());
            hs.pop ();
            steps -= 1;
        }
        return hs.top ();
    }
    
    string forward(int steps) {
        while (fw.size () > 0 && steps > 0) {
            hs.push (fw.top ());
            fw.pop ();
            steps -= 1;
        }
        return hs.top ();
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

