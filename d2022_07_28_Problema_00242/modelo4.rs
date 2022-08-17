impl Solution {
    pub fn is_anagram(s: String, t: String) -> bool {
        if s.len () != t.len () {
            return false // Sem ponto e vírgula
        }
        
        let mut contador: [i32; 26] = [0; 26];
        
        for i in 0..t.len () { // Tanto faz; são do mesmo tamanho
            contador [(s.as_bytes () [i] - 97) as usize] += 1;
            contador [(t.as_bytes () [i] - 97) as usize] -= 1;
        }
        
        for v in contador {
            if v != 0 {
                return false;
            }
        }
        
        // else
        return true // Idem, sem ponto e vírgula
    }
}

