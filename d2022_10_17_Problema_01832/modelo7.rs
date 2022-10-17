impl Solution {
    pub fn check_if_pangram(sentence: String) -> bool {
        let mut mapa: [bool; 26] = [false; 26]; // Um espaço para cada possibilidade de letra
        let mut total: i32 = 0;
        for c in sentence.bytes () {
            if !mapa [(c - 'a' as u8) as usize] {
                mapa [(c - 'a' as u8) as usize] = true;
                total += 1;
                if total == 26 { // Totas as letras já foram detectadas
                    return true
                }
            }
        }
        return false // Por omissão, se chegou ate aqui
    }
}

