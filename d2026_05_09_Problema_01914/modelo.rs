impl Solution {
    fn vetor (g: &Vec<Vec<i32>>, n: usize) -> Vec<i32> {
        let i_i = n;
        let i_j = n;
        let f_i = g.len () - n - 1;
        let f_j = g [0].len () - n - 1;
        let mut r: Vec<i32> = Vec::new ();
        for j in i_j..=f_j {
            r.push (g [i_i][j]);
        }
        for i in (i_i + 1)..=f_i {
            r.push (g [i][f_j]);
        }
        for j in (i_j..=(f_j - 1)).rev () {
            r.push (g [f_i][j]);
        }
        for i in ((i_i + 1)..=(f_i - 1)).rev () {
            r.push (g [i][i_j]);
        }
        r
    }
    fn rodar (v: &mut Vec<i32>, k: usize) {
        let t = v.len ();
        v.rotate_left (k % t);
    }
    fn distribuir (g: &mut Vec<Vec<i32>>, v: Vec<i32>, n: usize) {
        let i_i = n;
        let i_j = n;
        let f_i = g.len () - n - 1;
        let f_j = g [0].len () - n - 1;
        let mut a: usize = 0;
        for j in i_j..=f_j {
            g [i_i][j] = v [a];
            a += 1;
        }
        for i in (i_i + 1)..=f_i {
            g [i][f_j] = v [a];
            a += 1;
        }
        for j in (i_j..=(f_j - 1)).rev () {
            g [f_i][j] = v [a];
            a += 1;
        }
        for i in ((i_i + 1)..=(f_i - 1)).rev () {
            g [i][i_j] = v [a];
            a += 1;
        }
    }
    pub fn rotate_grid(grid: Vec<Vec<i32>>, k: i32) -> Vec<Vec<i32>> {
        let mut grid = grid.clone ();
        let t_i = grid.len ();
        let t_j = grid [0].len ();
        let k = k as usize;
        for n in 0..(t_i / 2).min (t_j / 2) {
            let mut v = Self::vetor (&grid, n);
            Self::rodar (&mut v, k);
            Self::distribuir (&mut grid, v, n);
        }
        grid
    }
}
