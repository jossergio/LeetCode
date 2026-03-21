impl Solution {
    pub fn reverse_submatrix(grid: Vec<Vec<i32>>, x: i32, y: i32, k: i32) -> Vec<Vec<i32>> {
        let mut grid = grid.clone ();
        let (mut x, mut y, mut k) = (x as usize, y as usize, k as usize); // Muda o tipo
        for j in y..(y + k) { // Observar que x e y não são do cartesiano, mas inversos
            let (mut cima, mut baixo) = (x, x + k - 1);
            while cima < baixo {
                (grid [cima][j], grid [baixo][j]) = (grid [baixo][j], grid [cima][j]);
                cima += 1;
                baixo -= 1;
            }
        }
        grid
    }
}
