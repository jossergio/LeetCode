func minPathSum(grid [][]int) int {
    t1 := len (grid) - 1
    t2 := len (grid [0]) - 1
    for i := t1; i >= 0; i -= 1 {
        for j := t2; j >= 0; j -= 1 {
            if i == t1 && j == t2 {
                continue // Só ocorre no início
            }
            if i == t1 {
                grid [i][j] += grid [i][j + 1]
            } else {
                if j == t2 {
                    grid [i][j] += grid [i + 1][j]
                } else {
                    if grid [i + 1][j] < grid [i][j + 1] {
                        grid [i][j] += grid [i + 1][j]
                    } else {
                        grid [i][j] += grid [i][j + 1]
                    }
                }
            }
        }
    }
    
    return grid [0][0]
}

