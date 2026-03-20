use std::collections::HashSet;
impl Solution {
    pub fn min_abs_diff(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let k = k as usize; // Muda o tipo
        let m = grid.len () - k + 1;
        let n = grid [0].len () - k + 1;
        let mut resposta = vec! [vec![0; n]; m]; // Já sabemos o tamanho
        for i in 0..m {
            for j in 0..n {
                let mut tmp: HashSet<i32> = HashSet::with_capacity (k * k); // Devem ser únicos
                for a in 0..k {
                    for b in 0..k {
                        tmp.insert (grid [i + a][j + b]);
                    }
                }
                let mut tmp: Vec<i32> = Vec::from_iter (tmp.into_iter ()); // Reaproveita o nome da variável
                tmp.sort ();
                resposta [i][j] = tmp
                    .windows (2)
                    .map (| a | i32::abs (a [0] - a [1]))
                    .min ()
                    .unwrap_or (0);
            }
        }
        resposta
    }
}
