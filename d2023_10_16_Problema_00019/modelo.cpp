func getRow(rowIndex int) []int {
    
    if rowIndex < 1 {
        return [] int {1}
    }
    
    linha := make ([] int, rowIndex + 1)
    linha [0] = 1
    linha [1] = 1
    
    for i := 2; i <= rowIndex; i++ {
                
        var anterior int = linha [0]
        
        for j := 1; j < i; j++ {
            tmp := linha [j]
            linha [j] = anterior + linha [j]
            anterior = tmp
        }
        
        linha [i] = 1
        
    }
    
    return linha
}

