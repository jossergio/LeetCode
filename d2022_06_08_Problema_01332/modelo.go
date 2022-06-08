func removePalindromeSub(s string) int {
    
    i, j := 0, len (s) - 1
    
    for i < j {
        
        if s [i] != s [j] {
            return 2
        }
        
        i++
        j--
    }
    
    return 1
}

