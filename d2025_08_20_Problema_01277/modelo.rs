impl Solution {
    pub fn count_squares(matrix: Vec<Vec<i32>>) -> i32 {
        let mut cont = 0;
        let ti = matrix.len ();
        let tj = matrix [0].len ();
        for i in 0..ti {
            for j in 0..tj {
                for k in 0..usize::min (ti - i, tj - j) {
                    let mut possivel = true; // Pressupõe
                    for m in 0..=k {
                        if matrix [i + m][j + k] == 0 || matrix [i + k][j + m] == 0 {
                            possivel = false;
                            break;
                        }
                    }
                    if possivel {
                        cont += 1;
                    } else {
                        break;
                    }
                }
            }
        }
        cont
    }
}
