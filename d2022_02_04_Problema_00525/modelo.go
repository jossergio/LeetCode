func max (i, j int) int {
    
    if i > j {
        return i
    }
    
    return j
}

func findMaxLength(nums []int) int {
    
    var mapa map [int] int = make (map [int] int)
    
    mapa [0] = -1
    
    var maximo, contar = 0, 0
    
    for i := 0; i < len (nums); i++ {
        
        tmp := 1
        if nums [i] == 0 {
            tmp = -1
        }
        
        contar += tmp
        
        _, existe := mapa [contar]
        if existe {
            
            maximo = max (maximo, i - mapa [contar])
            
        } else {
            
            mapa [contar] = i
            
        }
        
    }
    
    return maximo
    
}

