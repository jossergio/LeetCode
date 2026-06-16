impl Solution {
    pub fn process_str(s: String) -> String {
        let mut res: Vec<u8> = Vec::new ();
        for c in s.bytes () {
            match c {
                b'*' => _ = res.pop (),
                b'#' => res.extend (res.clone ()),
                b'%' => res.reverse (),
                _ => res.push (c)
            }
        }
        String::from_utf8 (res).unwrap ()
    }
}
