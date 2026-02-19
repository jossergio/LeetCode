impl Solution {
    pub fn count_binary_substrings(s: String) -> i32 {
        let mut prefixo: Vec<i32> = Vec::new ();
        let mut i: usize = 0;
        let s = s.as_bytes (); // Sombreia
        let t = s.len ();
        while i < t {
            let atual = s [i];
            let mut cont = 0;
            while i < t && s [i] == atual {
                cont += 1;
                i += 1;
            }
            prefixo.push (cont);
        }
        let t = prefixo.len (); // Sombreia
        let mut resposta = 0;
        for i in 1..t {
            resposta += prefixo [i - 1].min (prefixo [i]);
        }
        resposta
    }
}
