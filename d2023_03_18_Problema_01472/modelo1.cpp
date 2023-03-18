class BrowserHistory {
protected:
    vector<string> hs;
    int posicao;
public:
    BrowserHistory(string homepage) {
        hs.push_back (homepage); // Primeira
        posicao = 0; // Primeira
    }
    
    void visit(string url) {
        posicao += 1;
        if (posicao < hs.size ()) // Refaz o final
            hs = vector (hs.begin (), hs.begin () + posicao);
        hs.push_back (url);
    }
    
    string back(int steps) {
        posicao -= steps;
        if (posicao < 0)
            posicao = 0;
        return hs [posicao];
    }
    
    string forward(int steps) {
        posicao += steps;
        if (posicao >= hs.size ())
            posicao = hs.size () - 1;
        return hs [posicao];
    }
};

/**
 * Your BrowserHistory object will be instantiated and called as such:
 * BrowserHistory* obj = new BrowserHistory(homepage);
 * obj->visit(url);
 * string param_2 = obj->back(steps);
 * string param_3 = obj->forward(steps);
 */

