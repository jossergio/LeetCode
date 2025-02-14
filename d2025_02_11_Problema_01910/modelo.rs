impl Solution {
    pub fn remove_occurrences(s: String, part: String) -> String {
        let mut b = s.bytes ().collect::<Vec<u8>> ();
        let p = part.bytes ().collect::<Vec<u8>> ();
        let t1 = s.len ();
        let t2 = part.len ();
        let mut resposta: Vec<u8> = Vec::new ();
        for i in 0..t1 {
            resposta.push (b [i]);
            if resposta.len () >= t2 && &resposta [(resposta.len () - t2)..] == &p {
                resposta.truncate (resposta.len () - t2);
            }
        }
        String::from_utf8 (resposta).unwrap ()
    }
}
