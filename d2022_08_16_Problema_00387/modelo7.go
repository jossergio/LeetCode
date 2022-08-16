func firstUniqChar(s string) int {
    
    listagem := make (map [rune] int)
    
    for _, c := range s {
        if _, existe := listagem [c]; existe {
            listagem [c]++
        } else {
            listagem [c] = 1
        }
    }
    
    for i, c := range s {
        if listagem [c] == 1 {
            return i
        }
    }
    
    return -1
}

