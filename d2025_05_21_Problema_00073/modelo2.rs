impl Solution {
    pub fn set_zeroes(matrix: &mut Vec<Vec<i32>>) {
        let (m, n) = (matrix.len (), matrix [0].len ());
        let mut linhas = vec! [false; m];
        let mut cols = vec! [false; n];
        for (i, c) in matrix.iter ().enumerate () {
            for (j, v) in c.iter ().enumerate () {
                if *v == 0 {
                    linhas [i] = true;
                    cols [j] = true;
                }
            }
        }
        for i in 0..m {
            for j in 0..n {
                if linhas [i] || cols [j] {
                    matrix [i][j] = 0;
                }
            }
        }
    }
}
