impl Solution {
    pub fn unique_paths(m: i32, n: i32) -> i32 {
        let m: usize = m as usize; // Só para mudar o tipo
        let n: usize = n as usize; // Idem
        let mut tabela: Vec<Vec<i32>> = vec![vec![0; n + 1]; m + 1];
        tabela [m - 1][n] = 1; // Para uma lógica onde m é a linha
        for i in (0..m).rev () { // Destacar que irá de m - 1 a 0
            for j in (0..n).rev () { // Similar
                tabela [i][j] = tabela [i + 1][j] + tabela [i][j + 1];
            }
        }
        return tabela [0][0];
    }
}

