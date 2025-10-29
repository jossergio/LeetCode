impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let mut n = n; // Torna mutável
        let mut cont = 0;
        while n > 0 {
            cont += 1;
            n >>= 1;
        }
        while cont > 0 {
            n <<= 1;
            n += 1;
            cont -= 1;
        }
        n // Reaproveitada
    }
}
