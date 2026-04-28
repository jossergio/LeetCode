impl Solution {
    pub fn min_operations(grid: Vec<Vec<i32>>, x: i32) -> i32 {
        let mut tmp: Vec<_> = grid.into_iter ().flatten ().collect ();
        let t = tmp.len ();
        tmp.sort ();
        let base = tmp [t / 2]; // Uma falsa mediana
        let mut resposta = 0; // i32
        for v in tmp {
            let k = (v - base).abs ();
            if k % x != 0 {
                return -1;
            }
            resposta += k / x;
        }
        resposta
    }
}
