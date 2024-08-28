impl Solution {
    pub fn my_sqrt(x: i32) -> i32 {
        let x: i64 = x as i64; // Só para sombrear, para um tipo superior
        let mut resposta:i64 = 1;
        while (resposta * resposta <= x) {
            resposta += 1;
        }
        (resposta - 1) as i32
    }
}

