impl Solution {
    fn buscar (grid: &Vec<Vec<i32>>, memo: &mut Vec<Vec<i32>>, i: usize, j: usize) -> i32 {
        let pegar = |y: i32, x: usize| -> i32 { if y < 0 || y >= grid.len () as i32 || x >= grid [0].len () { 0 } else { grid [y as usize][x]}};
        // Acima: é que o índice negativo para a linha é utilizado nos testes
        if memo [i][j] == -1 { // Ainda não calculado
            memo [i][j] = 0;
            if grid [i][j] < pegar (i as i32 - 1, j + 1) {
                memo [i][j] = std::cmp::max (memo [i][j], 1 + Self::buscar (grid, memo, i - 1, j + 1));
            }
            if grid [i][j] < pegar (i as i32, j + 1) {
                memo [i][j] = std::cmp::max (memo [i][j], 1 + Self::buscar (grid, memo, i, j + 1));
            }
            if (grid [i][j] < pegar (i as i32 + 1, j + 1)) {
                memo [i][j] = std::cmp::max (memo [i][j], 1 + Self::buscar (grid, memo, i + 1, j + 1));
            }
        }
        memo [i][j]
    }
    pub fn max_moves(grid: Vec<Vec<i32>>) -> i32 {
        let mut memo: Vec<Vec<i32>> = vec! [vec! [-1; grid [0].len ()]; grid.len ()];
        let mut resposta: i32 = 0;
        for i in 0..grid.len () {
            resposta = std::cmp::max (resposta, Self::buscar (&grid, &mut memo, i, 0));
        }
        return resposta;
    }
}

