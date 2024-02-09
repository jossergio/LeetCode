func firstUniqChar(s string) int {
    
    var listagem [27] int // Tudo zero
    
    for _, c := range s {
        listagem [int (c) - 97]++
    }
    
    for i, c := range s {
        if listagem [int (c) - 97] == 1 {
            return i
        }
    }
    
    return -1
}

