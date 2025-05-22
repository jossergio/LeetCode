func setZeroes(matrix [][]int)  {
    m, n := len (matrix), len (matrix [0])
    linhas := make ([] bool, m)
    colunas := make ([] bool, n)
    for i := 0; i < m; i += 1 {
        for j := 0; j < n; j += 1 {
            if matrix [i][j] == 0 {
                linhas [i] = true
                colunas [j] = true
            }
        }
    }
    for i := 0; i < m; i += 1 {
        if linhas [i] {
            for j := 0; j < n; j += 1 {
                matrix [i][j] = 0;
            }
        }
    }
    for j := 0; j < n; j += 1 {
        if colunas [j] {
            for i := 0; i < m; i += 1 {
                matrix [i][j] = 0
            }
        }
    }
}
