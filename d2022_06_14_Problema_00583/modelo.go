func minDistance(word1 string, word2 string) int {
    
    maior := func (a int, b int) int {
        if a > b {
            return a
        }
        // else
        return b
    }
    
    acumulados := make ([][] int, len (word1) + 1)
    
    acumulados [0] = make ([] int, len (word2) + 1)
    
    for i := 1; i <= len (word1); i++ {
        acumulados [i] = make ([] int, len (word2) + 1)
        for j := 1; j <= len (word2); j++ {
            
            if word1 [i - 1] == word2 [j - 1] {
                acumulados [i][j] = acumulados [i - 1][j - 1] + 1
            } else {
                acumulados [i][j] = maior (acumulados [i][j - 1], acumulados [i - 1][j])
            }
        }
    }
    
    return len (word1) + len (word2) - 2 * acumulados [len (word1)][len (word2)]
}

