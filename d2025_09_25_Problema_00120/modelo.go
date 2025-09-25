func minimumTotal(triangle [][]int) int {
    
    t := make ([][] int, len (triangle))
    
    menor := func (a int, b int) int {
        if a < b {
            return a
        }
        // else
        return b
    }
    
    t [0] = make ([] int, 1)
    t [0][0] = triangle [0][0]
    
    for i := 1; i < len (triangle); i++ {
        
        t [i] = make ([] int, i + 1)
        t [i][0] = triangle [i][0] + t [i - 1][0]
        
        for j := 1; j < len (triangle [i]) - 1; j++ {
            t [i][j] = triangle [i][j] + menor (t [i - 1][j - 1], t [i - 1][j])
        }
        
        t [i][i] = t [i - 1][i - 1] + triangle [i][i]
    }
    
    var minimo int = t [len (t) - 1][0]
    
    for _, v := range t [len (t) - 1] {
        minimo = menor (minimo, v)
    }
    
    return minimo
}
