type WordDictionary struct {
    
    lista [] string
    
}


func Constructor() WordDictionary {
    
    var dicionario WordDictionary
    
    return dicionario
}


func (this *WordDictionary) AddWord(word string)  {
    
    this.lista = append (this.lista, word)
    
}


func (this *WordDictionary) Search(word string) bool {
    
    for _, s := range this.lista {
        
        if len (s) != len (word) {
            continue
        }
        
        var contador int // = 0
        
        for i, c := range word {
            
            contador += 1
            
            if c == '.' {
                continue
            }

            if byte (c) != s [i] {
                contador = 0 // Só para garantir que não é o último
                break
            }
            
        }
        
        if contador == len (word) {
            return true
        }
        
    }
    
    return false // Buscou em todos e não achou
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */

