use std::collections::HashSet;
impl Solution {
    fn eh_valido (n: i32) -> bool {
        let alters = [0, 1, 5, -1, -1, 2, 9, -1, 8, 6];
        let mut novo = 0;
        let mut k = n;
        let mut potencia = 1;
        while k > 0 {
            let tmp = (k % 10) as usize;
            if alters [tmp] == -1 {
                return false; // Sumariamente
            }
            // else
            novo += alters [tmp] * potencia;
            potencia *= 10;
            k /= 10;
        }
        novo != n
    }
    pub fn rotated_digits(n: i32) -> i32 {
        (0..=n) // O zero nunca é válido
            .into_iter ()
            .filter (| &k | Self::eh_valido (k))
            .count () as i32
    }
}
