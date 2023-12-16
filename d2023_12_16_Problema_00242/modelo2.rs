impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len () != t.len () {
            return false;
        }
        let mut contador: [usize; 26] = [0; 26];
        const base: u8 = 'a' as u8;
        let tam: usize = t.len (); // Tanto faz; são do mesmo tamanho
        let sbytes = s.as_bytes (); // Tipo automático
        let tbytes = t.as_bytes ();
        for i in 0..tam {
            contador [(sbytes [i] - base) as usize] += 1;
            contador [(tbytes [i] - base) as usize] -= 1;
        }
        for v in contador {
            if v != 0 { // Alguém sobrou, para mais ou para menos
                return false;
            }
        }
        return true; // Passou nos testes
    }
}

