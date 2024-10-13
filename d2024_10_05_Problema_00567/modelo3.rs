impl Solution {
    fn iguais (d1: &[u8], d2: &[u8]) -> bool {
        for i in 0..d1.len () { // Tanto faz; são do mesmo tamanho
            if d1 [i] != d2 [i] {
                return false;
            }
        }
        true
    }
    pub fn check_inclusion(s1: String, s2: String) -> bool {
        let t1 = s1.len ();
        let t2 = s2.len ();
        if t1 > t2 { // A plataforma gera casos assim
            return false;
        }
        // else
        let s1 = s1.as_bytes (); // Sombreia
        let s2 = s2.as_bytes (); // Idem
        let mut d1: [u8; 26] = [0; 26];
        let mut d2: [u8; 26] = [0; 26];
        let ORD_a = b'a' as u8;
        let ordem = | c | { ((c as u8) - ORD_a) as usize};
        for i in 0..t1 {
            d1 [ordem (s1 [i])] += 1;
            d2 [ordem (s2 [i])] += 1;
        }
        for i in t1..t2 {
            if Self::iguais (&d1, &d2) {
                return true;
            }
            // else
            d2 [ordem (s2 [i - t1])] -= 1;
            d2 [ordem (s2 [i])] += 1;
        }
        Self::iguais (&d1, &d2) // No laço sobra o último teste
    }
}

