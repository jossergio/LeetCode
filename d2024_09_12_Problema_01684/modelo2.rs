use std::collections::HashSet;
impl Solution {
    pub fn count_consistent_strings(allowed: String, words: Vec<String>) -> i32 {
        let mut contador = 0; // Para a resposta
        let letras: HashSet<char> = HashSet::from_iter (allowed.chars ());
        for palavra in &words {
            if letras.is_superset (&HashSet::from_iter (palavra.chars ())) {
                contador += 1;
            }
        }
        contador
    }
}

