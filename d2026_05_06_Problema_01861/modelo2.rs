impl Solution {
    pub fn rotate_the_box(box_grid: Vec<Vec<char>>) -> Vec<Vec<char>> {
        let (m, n) = (box_grid.len (), box_grid [0].len ());
        let mut resposta = vec![vec!['.'; m]; n];
        for i in 0..m {
            let mut k = n;
            for j in (0..n).rev () {
                if box_grid [i][j] == '#' {
                    resposta [j][m - i - 1] = '.';
                    k -= 1;
                    resposta [k][m - i - 1] = '#';
                } else {
                    if box_grid [i][j] == '*' {
                        resposta [j][m - i - 1] = '*';
                        k = j;
                    }
                }
            }
        }
        resposta
    }
}
