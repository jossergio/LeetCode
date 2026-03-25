impl Solution {
    pub fn can_partition_grid(grid: Vec<Vec<i32>>) -> bool {
        // Tenta, primeiro, as linhas
        let linhas: Vec<i64> = grid
            .iter ()
            .map (| a | a
                .iter ()
                .map (| &v | v as i64)
                .sum ())
            .collect ();
        let mut total: i64 = linhas.iter ().sum ();
        let mut soma: i64 = 0;
        for v in linhas {
            total -= v;
            soma += v;
            if soma == total {
                return true;
            }
        }
        // Tenta as colunas
        let t = grid [0].len ();
        let mut colunas = vec![0 as i64; t];
        grid
            .iter ()
            .for_each (| a | {
                for (i, &v) in a.iter ().enumerate () {
                    colunas [i] += v as i64;
                }
            });
        total = colunas.iter ().sum ();
        soma = 0;
        for v in colunas {
            total -= v;
            soma += v;
            if soma == total {
                return true;
            }
        }
        false
    }
}
