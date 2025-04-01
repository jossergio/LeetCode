impl Solution {
    pub fn hamming_weight(n: i32) -> i32 {
        let mut resposta: i32 = 0;
        let mut n = n; // Torna mutável
        while n > 0 {
            if n & 1 == 1 {
                resposta += 1;
            }
            n >>= 1;
        }
        resposta
    }
}
