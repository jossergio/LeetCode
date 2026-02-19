impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let s = s.as_bytes (); // Sombreia
        let mut i: usize = 0;
        let mut resposta = 0;
        let t = s.len ();
        let mut anterior = 0;
        while i < t {
            let atual = s [i];
            let mut cont = 0;
            while i < t && s [i] == atual {
                cont += 1;
                i += 1;
            }
            resposta += cont.min (anterior); // A primeira soma é com zero
            anterior = cont;
        }
        resposta
    }
}
