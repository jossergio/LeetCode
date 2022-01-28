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
        
        for i, c := range word {
            
            if c != '.' {

                if byte (c) != s [i] {
                    break
                }
            
            }
            
            if i == len (word) - 1 {
                return true
            }
            
        }
        
    }
    
    return false
}


/**
 * Your WordDictionary object will be instantiated and called as such:
 * obj := Constructor();
 * obj.AddWord(word);
 * param_2 := obj.Search(word);
 */

