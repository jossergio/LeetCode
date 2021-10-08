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
/*
 == Desconsiderar essas funções
*/
    void mostrarArvore (Arvore *no) {
        if (no != nullptr) {
            mostrarArvore (no->esquerda);
            cout << " " << no->palavra;
            mostrarArvore (no->direita);
        }
    } // mostrarArvore
    
    void mostrar () {
        cout << "Mostrando árvore: ";
        mostrarArvore (raiz);
        cout << endl;
    } // mostrar
/*
 == Considerar a chave abaixo, pois, é o fim da classe
*/
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

void testar (Trie *t, string p) {
    if (t->search (p))
        cout << "Encontrou " << p << endl;
    else
        cout << "Não encontrou " << p << endl;
} // testar

void testarPrefixo (Trie *t, string p) {
    if (t->startsWith (p))
        cout << "Encontrou prefixo " << p << endl;
    else
        cout << "Não encontrou prefixo " << p << endl;
} // testarCom

int main() {
// Pela definição do problema, só letras minúsculas inglesas
    Trie *obj = new Trie ();
    obj->insert ("banca");
    obj->insert ("casamento");
    obj->insert ("astrologia");
    obj->mostrar ();
    testar (obj, "astro");
    testar (obj, "casa");
    testarPrefixo (obj, "astro");
    testarPrefixo (obj, "casa");
    testarPrefixo (obj, "cara");
    obj->insert ("astro");
    obj->insert ("casa");
    obj->mostrar ();
    testar (obj, "astro");
    testar (obj, "cara");
}

