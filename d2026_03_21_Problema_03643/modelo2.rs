impl Solution {
    pub fn reverse_submatrix(grid: Vec<Vec<i32>>, x: i32, y: i32, k: i32) -> Vec<Vec<i32>> {
        let mut grid = grid.clone ();
        let (mut x, mut y, mut k) = (x as usize, y as usize, k as usize); // Muda o tipo
        for j in y..(y + k) { // Observar que x e y não são do cartesiano, mas inversos
            for i in 0..(k / 2) {
                (grid [x + i][j], grid [x + k - i - 1][j]) = (grid [x + k - i - 1][j], grid [x + i][j])
            }
        }
        grid
    }
}
