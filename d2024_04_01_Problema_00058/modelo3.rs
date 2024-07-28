impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut resposta: usize = 0;
        let s: String = String::from (s.trim ()); // Só para tirar os espaços antes e depois
        for (i, c) in s.as_bytes ().iter ().enumerate () {
            if *c == b' ' {
                resposta = i + 1; // O próximo caractere
            }
        }
        (s.len () - resposta) as i32
    }
}

