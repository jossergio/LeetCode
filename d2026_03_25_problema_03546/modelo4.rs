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
        Self::verificar (&grid
            .iter ()
            .map (| a | 
                a
                .iter ()
                .map (| &v | v as i64)
                .sum ())
            .collect::<Vec<_>> ()
        ) ||
        Self::verificar (&grid
            .iter ()
            .fold (vec![0; grid [0].len ()], | mut acum_colunas, linha_atual | {
                for (i, &v) in linha_atual.iter ().enumerate () {
                    acum_colunas [i] += v as i64;
                }
                acum_colunas
            })
        )
    }
}
