func uniquePaths(m int, n int) int {
    tabela := make ([][] int, m + 1) // A tabela é maior que o quadro, para ter zeros nos limites e nao precisar checar (if's) quando passando nas margens
    for i := 0; i < m + 1; i++ {
        tabela [i] = make ([] int, n + 1)
    }
    tabela [m - 1][n] = 1; // As demais, zeradas
    for i := m - 1; i >= 0; i-- {
        for j := n - 1; j >= 0; j-- {
            tabela [i][j] = tabela [i + 1][j] + tabela [i][j + 1]
        }
    }
    return tabela [0][0]
}

