struct Arvore {
    string palavra;
    Arvore *esquerda, *direita;
    Arvore (string p): palavra (p) {
        esquerda = nullptr;
        direita = nullptr;
    } // Arvore
}; // struct arvore

class Trie {
private:
    Arvore *raiz = nullptr;
    
    void inserir (Arvore *no, string p) {
// O nó nunca vem nullptr, pois, já foi testado por insert
        if (no->palavra.compare (p) >= 0) { // Os iguais também irão para a esquerda
            if (no->esquerda == nullptr)
                no->esquerda = new Arvore (p);
            else
                inserir (no->esquerda, p);
        } else { // if no->palavra.compare
            if (no->direita == nullptr)
                no->direita = new Arvore (p);
            else
                inserir (no->direita, p);
        } // else if no->palavra.compare
    } // inserir
    
    bool procurar (Arvore *no, string p) {
// Usar chaves, para não confundir o compilador
        if (no != nullptr) { // Atingiu a recursão pode chegar a nullptr
            if (no->palavra.compare (p) == 0 && no->palavra.size () == p.size ()) {
                return true;
            } else { // if raiz->palavra == word
                if (no->palavra.compare (p) >= 0) {
                    return procurar (no->esquerda, p);
                } else { // if raiz->palavra.compare (word)
                    return procurar (no->direita, p);
                } // else if raiz->palavra.compare (word)
            } // if raiz != nullptr
        } // if no != nullptr
        return false;
    } // procurar

    bool procurarPrefixo (Arvore *no, string p) {
// Usar chaves, para não confundir o compilador
        if (no != nullptr) { // Atingiu a recursão pode chegar a nullptr
            if (no->palavra.compare (0, p.size (), p) == 0) {
                return true;
            } else { // if raiz->palavra == word
                if (no->palavra.compare (p) >= 0) {
                    return procurarPrefixo (no->esquerda, p);
                } else { // if raiz->palavra.compare (word)
                    return procurarPrefixo (no->direita, p);
                } // else if raiz->palavra.compare (word)
            } // if raiz != nullptr
        } // if no != nullptr
        return false;
    } // procurarCom

public:
    Trie() {
        
    }
    
    void insert(string word) {
        if (raiz == nullptr)
            raiz = new Arvore (word);
        else
            inserir (raiz, word);
    }
    
    bool search(string word) {
        if (raiz != nullptr)
            return procurar (raiz, word);
        return false;
    }
    
    bool startsWith(string prefix) {
        if (raiz != nullptr)
            return procurarPrefixo (raiz, prefix);
        return false;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

