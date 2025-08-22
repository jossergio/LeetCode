impl Solution {
    pub fn minimum_area(grid: Vec<Vec<i32>>) -> i32 {
        let mut y_max = 0 as usize;
        let mut y_min = grid.len ();
        let mut x_max = 0 as usize;
        let mut x_min = grid [0].len ();
        for (i, l) in grid.iter ().enumerate () {
            for (j, v) in l.iter ().enumerate () {
                if *v == 1 {
                    y_max = y_max.max (i);
                    y_min = y_min.min (i);
                    x_max = x_max.max (j);
                    x_min = x_min.min (j);
                }
            }
        }
        ((y_max - y_min + 1) * (x_max - x_min + 1)) as i32
    }
}
