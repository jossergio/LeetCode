func transpose(matrix [][]int) [][]int {
    resp := make ([][] int, len (matrix [0]))
    for j := 0; j < len (matrix [0]); j++ {
        resp [j] = make ([] int, len (matrix))
        for i := 0; i < len (matrix); i++ {
            resp [j][i] = matrix [i][j]
        }
    }
    return resp
}

