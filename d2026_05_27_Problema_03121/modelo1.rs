use std::collections::HashMap;
impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let mut maiusculas: HashMap<char, usize> = HashMap::new (); // Conterá o primeiro da classe
        let mut minusculas: HashMap<char, usize> = HashMap::new (); // Conterá o último da classe
        for (i, c) in word.chars ().enumerate () {
            if c.is_uppercase () && !maiusculas.contains_key (&c) {
                maiusculas.insert (c, i); // Só armazena o primeiro
            }
            if c.is_lowercase () {
                minusculas.insert (c, i); // Só fica registrado o último
            }
        }
        let mut contagem = 0;
        for (m, n) in ('A'..='Z').zip (('a'..='z')) {
            if maiusculas.contains_key (&m) && minusculas.contains_key (&n) { // Tem que conter ambos
                if maiusculas.get (&m).unwrap () > minusculas.get (&n).unwrap () {
                    contagem += 1;
                }
            }
        }
        contagem
    }
}
