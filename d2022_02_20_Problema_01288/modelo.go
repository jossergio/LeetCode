func removeCoveredIntervals(intervals [][]int) int {
    
    var t int = len (intervals)
    var resposta int = len (intervals)
    
    for i := 0; i < t; i++ {
        for j := 0; j < t; j++ {
            if i != j && intervals [i][0] >= intervals [j][0] && intervals [i][1] <= intervals [j][1] {
                resposta--
                break
            }
        }
    }
    
    return resposta
}

