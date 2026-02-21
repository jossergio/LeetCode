impl Solution {
    fn contar_bits (n: i32) -> i32 {
        let mut n = n; // Torna mutável
        let mut cont = 0;
        while n > 0 {
            if n & 1 == 1 {
                cont += 1;
            }
            n >>= 1;
        }
        cont
    }
    pub fn count_prime_set_bits(left: i32, right: i32) -> i32 {
        let mut primos = vec![true; 33]; // 0..=32
        primos [0] = false;
        primos [1] = false;
        for i in 2..=32 {
            for j in ((2 * i)..=32).step_by (i) {
                primos [j] = false; // Erastóstenes
            }
        }
        let mut cont = 0;
        for i in left..=right {
            if primos [Self::contar_bits (i) as usize] {
                cont += 1;
            }
        }
        cont
    }
}
