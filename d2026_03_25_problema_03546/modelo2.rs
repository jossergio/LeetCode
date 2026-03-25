impl Solution {
    fn verificar (a: &Vec<i64>) -> bool {
        let mut total: i64 = a.iter ().sum ();
        let mut soma = 0; // i64
        for v in a {
            total -= v;
            soma += v;
            if soma == total {
                return true;
            }
        }
        false
    }
    pub fn can_partition_grid(grid: Vec<Vec<i32>>) -> bool {
        let linhas: Vec<i64> = grid
            .iter ()
            .map (| a | 
                a
                .iter ()
                .map (| &v | v as i64)
                .sum ())
            .collect ();
        let t = grid [0].len ();
        let mut colunas = vec![0; t];
        grid
            .iter ()
            .for_each (| a | {
                for (i, &v) in a.iter ().enumerate () {
                    colunas [i] += v as i64;
                }
            });
        Self::verificar (&linhas) || Self::verificar (&colunas)
    }
}
