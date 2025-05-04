impl Solution {
    pub fn clear_digits(s: String) -> String {
        let mut pilha: Vec<u8> = Vec::new ();
        for c in s.bytes () {
            if c >= b'0' && c <= b'9' {
                match pilha.last () {
                    Some (a) => { let _ = pilha.pop (); },
                    None => { pilha.push (c) }
                }
            } else {
                pilha.push (c);
            }
        }
        String::from_utf8 (pilha).unwrap ()
    }
}
