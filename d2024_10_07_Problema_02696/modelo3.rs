impl Solution {
    pub fn min_length(s: String) -> i32 {
        let mut pilha: Vec<char> = Vec::new ();
        for c in s.chars () {
            if c != 'B' && c != 'D' { // Valores que podem tirar do topo da pilha
                pilha.push (c);
            } else {
                match (pilha.last (), c) {
                    (Some ('A'), 'B') => _ = pilha.pop (),
                    (Some ('C'), 'D') => _ = pilha.pop (),
                    _ => pilha.push (c)
                }
            }
        }
        pilha.len () as i32
    }
}

