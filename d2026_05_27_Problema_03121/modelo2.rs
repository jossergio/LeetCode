use std::collections::HashMap;
impl Solution {
    pub fn number_of_special_chars(word: String) -> i32 {
        let t = 26; // O número de letras
        let mut minusculas = vec![-1; t];
        let mut maiusculas = vec![-1; t];
        for (i, c) in word.chars ().enumerate () {
            if c.is_lowercase () {
                minusculas [c as usize - 'a' as usize] = i as i32; // Só registra o último
            }
            if c.is_uppercase () {
                let idx = c as usize - 'A' as usize;
                if maiusculas [idx] == -1 {
                    maiusculas [idx] = i as i32;
                }
            }
        }
        minusculas
            .iter ()
            .zip (maiusculas.iter ())
            .filter (| (i, j) | **i != -1 && **i < **j)
            .count () as i32
    }
}
