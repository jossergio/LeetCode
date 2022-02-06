var mapa map [rune] int
var texto string
var tamP int

func checar (i int) bool {
    
    var limite int = i + tamP
    
    m := make (map [rune] int)
    
    for a, v := range mapa {
        m [a] = v
    }
    
    for j := i; j < limite; j++ {
        
        _, existe := m [rune (texto [j])]
        
        if existe {
            
            m [rune (texto [j])]--
            
            if m [rune (texto [j])] < 0 {
                return false
            }
          
        } else {
            
            return false
            
        }
        
    }
    
    for _, v := range m {
        
        if v > 0 {
            
            return false
            
        }
        
    }
    
    return true
    
}

func findAnagrams(s string, p string) []int {
    
    tamP = len (p)
    texto = s
    mapa = make (map [rune] int)
    
    var limite int = len (s) - tamP
    
    for _, v := range p {
        
        _, existe := mapa [v]
        
        if existe {
            mapa [v] += 1
        } else {
            mapa [v] = 1
        }
        
    }
    
    var resposta [] int
    
    for i := 0; i <= limite; i++ {
        
        _, existe := mapa [rune (s [i])]
        
        if existe && checar (i) {
            resposta = append (resposta, i)
        }
        
    }
    
    return resposta
    
}

