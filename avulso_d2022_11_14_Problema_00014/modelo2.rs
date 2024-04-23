impl Solution {
    pub fn longest_common_prefix(strs: Vec<String>) -> String {
        let mut resposta: String = String::new ();
        let mut i: usize = 0;
        'externo: loop {
            for s in &strs {
                if !(i < s.len () && s.as_bytes ()[i] == strs [0].as_bytes ()[i]) {
                    break 'externo;
                }
            }
            resposta.push (strs [0].as_bytes ()[i] as char); // Passou
            i += 1;
        }
        return resposta;
    }
}

