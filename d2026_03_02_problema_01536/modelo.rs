use std::collections::HashMap;
impl Solution {
    pub fn min_swaps(grid: Vec<Vec<i32>>) -> i32 {
        let t = grid.len ();
        let mut topos: Vec<i32> = grid
            .into_iter ()
            .map (| col | 
                col
                .into_iter ()
                .rev ()
                .take_while (| i | *i == 0)
                .count () as i32
            ).collect ();
        let mut resposta: usize = 0;
        for i in 0..(t - 1) {
            let tmp = (t - i - 1) as i32;
            if topos [i] < tmp {
                let mut j = i + 1;
                while j < t && topos [j] < tmp {
                    j += 1;
                }
                if j == t {
                    return - 1;
                }
                // else
                while j > i  {
                    topos.swap (j, j - 1);
                    resposta += 1;
                    j -= 1;
                }
                resposta += j - i;
            }
        }
        resposta as i32
    }
}
