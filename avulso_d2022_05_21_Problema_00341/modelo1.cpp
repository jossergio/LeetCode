/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */

class NestedIterator {
private:
    stack<pair<vector<NestedInteger>, int>> sequenciador;
    int proximo;
    bool lido = false;
    
    void pegarProximo () {
        
        lido = false;
        
        while ((! sequenciador.empty ()) && (! (sequenciador.top ().second < sequenciador.top ().first.size ())))
            sequenciador.pop ();

        if (sequenciador.empty ())
            return;
        
        if (sequenciador.top ().first [sequenciador.top ().second].isInteger ()) {
            proximo = sequenciador.top ().first [sequenciador.top ().second].getInteger ();
            sequenciador.top ().second++;
            lido = true;
            return;
        }
        
        // Poderia ser um else
        int tmp = sequenciador.top ().second;
        sequenciador.top ().second++;
        sequenciador.push ({sequenciador.top ().first [tmp].getList (), 0});
        pegarProximo ();
    }
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        sequenciador.push ({nestedList, 0});
        pegarProximo ();
    }
    
    int next() {
        
        int retorno = proximo;
        
        pegarProximo ();
        
        return retorno;
    }
    
    bool hasNext() {
        return !sequenciador.empty ();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

