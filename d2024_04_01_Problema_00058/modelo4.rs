impl Solution {
    pub fn length_of_last_word(s: String) -> i32 {
        let mut resposta: usize = 0;
        let s: String = String::from (s.trim ()); // Só para tirar os espaços antes e depois
        for (i, c) in s.as_bytes ().iter ().rev ().enumerate () {
            if *c == b' ' {
                return i as i32 // Como é 0-begin, essa posição é o próprio tamanho
            }
        }
        s.len () as i32
    }
}

