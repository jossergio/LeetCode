impl Solution {
    pub fn count_servers(grid: Vec<Vec<i32>>) -> i32 {
        let tl = grid.len ();
        let tc = grid [0].len ();
        let mut linhas = vec![0; tl];
        let mut cols = vec![0; tc];
        for i in 0..tl {
            for j in 0..tc {
                if grid [i][j] == 1 {
                    linhas [i] += 1;
                    cols [j] += 1;
                }
            }
        }
        let mut resposta = 0;
        for i in 0..tl {
            for j in 0..tc {
                if grid [i][j] == 1 && (linhas [i] > 1 || cols [j] > 1) {
                    resposta += 1;
                }
            }
        }
        resposta
    }
}
