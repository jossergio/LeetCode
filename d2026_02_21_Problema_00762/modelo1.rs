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
        let primos = std::collections::HashSet::<i32>::from ([2, 3, 5, 7, 11, 13, 17, 19]);
        let mut cont = 0;
        for i in left..=right {
            if primos.contains (&Self::contar_bits (i)) {
                cont += 1;
            }
        }
        cont
    }
}
