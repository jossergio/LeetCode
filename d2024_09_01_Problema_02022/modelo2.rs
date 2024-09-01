impl Solution {
    pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
        let m = m as usize; // Para sombrear para o tipo
        let n = n as usize; // Idem
        if m * n != original.len () {
            return vec![vec![0;0]; 0]
        }
        let mut resposta: Vec<Vec<i32>> = vec![vec![0; n]; m];
        let mut i: usize = 0;
        let mut j: usize = 0;
        for v in original {
            resposta [i][j] = v;
            j += 1;
            if (j == n) {
                i += 1;
                j = 0;
            }
        }
        resposta
    }
}

