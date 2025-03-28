impl Solution {
    pub fn min_operations(grid: Vec<Vec<i32>>, x: i32) -> i32 {
        let mut tmp = grid.iter ().flatten ().collect::<Vec<_>> ();
        let t = tmp.len ();
        if t < 2 {
            return 0;
        }
        tmp.sort ();
        let base = tmp [t / 2]; // Uma falsa mediana
        let mut resposta = 0; // i32
        for v in tmp {
            if i32::abs (v - base) % x != 0 {
                return -1;
            }
            resposta += i32::abs (v - base) / x;
        }
        resposta
    }
}
