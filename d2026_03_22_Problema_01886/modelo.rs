impl Solution {
    pub fn find_rotation(mat: Vec<Vec<i32>>, target: Vec<Vec<i32>>) -> bool {
        let (mut girar_0, mut girar_90, mut girar_180, mut girar_270) = (true, true, true, true); // Pressupõe
        let n = mat.len (); // São de mesma dimensão e quadradas
        for i in 0..n {
            for j in 0..n {
                girar_0 &= mat [i][j] == target [i][j];
                girar_90 &= mat [i][j] == target [j][n - 1 - i];
                girar_180 &= mat [i][j] == target [n - 1 - i][n - 1 - j];
                girar_270 &= mat [i][j] == target [n - 1 - j][i];
            }
        }
        girar_0 || girar_90 || girar_180 || girar_270
    }
}
