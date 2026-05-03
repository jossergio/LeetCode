use std::collections::HashSet;
impl Solution {
    fn eh_valido (k: i32) -> bool {
        let invalidos = HashSet::from ([3, 4, 7]);
        let invalido = | c | invalidos.contains (&c);
        let espelhos = HashSet::from ([0, 1, 8]);
        let espelho = | c | espelhos.contains (&c);
        let mut k = k;
        let mut cont = 0;
        while k > 0 {
            let tmp = k % 10;
            if invalido (tmp) {
                return false; // Sumariamente
            }
            // else
            if !espelho (tmp) {
                cont += 1;
            }
            k /= 10;
        }
        cont > 0 // É diferente após mofificar
    }
    pub fn rotated_digits(n: i32) -> i32 {
        (1..=n) // O zero nunca é válido
            .into_iter ()
            .filter (| &k | Self::eh_valido (k))
            .count () as i32
    }
}
