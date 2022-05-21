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
        
        stack<vector<NestedInteger>> pilha;
        stack<int> proximosPilha;
        
        pilha.push (n);
        proximosPilha.push (0); // Primeiro elemento da lista principal
        
        while (! pilha.empty ())
            if (proximosPilha.top () < pilha.top ().size()) {
                if (pilha.top () [proximosPilha.top ()].isInteger ()) {
                    valores.push_back (pilha.top () [proximosPilha.top ()].getInteger ());
                    proximosPilha.top ()++; // Vide observação na linha similar abaixo
                } else {
                    pilha.push (pilha.top () [proximosPilha.top ()].getList ());
                    proximosPilha.top ()++; // Tem que ficar aqui e redundante, para iniciar um novo ciclo
                    proximosPilha.push (0); // Início da lista no novo nível
                }
            } else {
                pilha.pop ();
                proximosPilha.pop ();
            }
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

