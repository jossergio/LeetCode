impl Solution {
    pub fn construct2_d_array(original: Vec<i32>, m: i32, n: i32) -> Vec<Vec<i32>> {
        let m = m as usize; // Para sombrear para o tipo
        let n = n as usize; // Idem
        if m * n != original.len () {
            return Vec::new ();
        }
        let mut resposta: Vec<Vec<i32>> = Vec::with_capacity (m);
        let mut k: usize = 0;
        for _ in 0..m {
            let mut tmp: Vec<i32> = Vec::with_capacity (n);
            for i in 0..n {
                tmp.push (original [k]);
                k += 1;
            }
            resposta.push (tmp);
        }
        resposta
    }
}

