impl Solution {
    fn zero (v: i32) -> bool {
        let mut v = v; // Torna mutável
        while v != 0 {
            if v % 10 == 0 {
                return true; // Tem zero
            }
            // else
            v /= 10;
        }
        false // Não tem zero
    }
    pub fn get_no_zero_integers(n: i32) -> Vec<i32> {
        let mut a = n - 1;
        let mut b = 1;
        while Self::zero (a) || Self::zero (b) {
            a -= 1;
            b += 1;
            // O problema diz que há solução
            // Então, não precisa de trstes
        }
        Vec::from ([a, b])
    }
}
