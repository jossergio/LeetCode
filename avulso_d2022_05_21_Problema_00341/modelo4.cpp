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
    vector<int> valores;
    int ponteiro = 0;
    
    void montar (vector<NestedInteger> &n) {
        
        stack<pair<vector<NestedInteger>::iterator, vector<NestedInteger>::iterator>> pilha;
        
        pilha.emplace (n.begin (), n.end ());
        
        while (! pilha.empty ()) {
            vector<NestedInteger>::iterator p = pilha.top ().first;
            if (p != pilha.top ().second) {
                pilha.top ().first++;
                if (p->isInteger ()) {
                    valores.push_back (p->getInteger ());
                } else {
                    auto& tmp = p->getList ();
                    pilha.emplace (tmp.begin (), tmp.end ());
                }
            } else {
                pilha.pop ();
            }
        } // while
    }
    
public:
    NestedIterator(vector<NestedInteger> &nestedList) {
        montar (nestedList);
    }
    
    int next() {
        return valores [ponteiro++];
    }
    
    bool hasNext() {
        return ponteiro < valores.size ();
    }
};

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i(nestedList);
 * while (i.hasNext()) cout << i.next();
 */

