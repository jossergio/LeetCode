impl Solution {
    pub fn process_str(s: String) -> String {
        String::from_utf8 (
            s
                .bytes ()
                .fold (Vec::<u8>::new (),
                    | mut trab, c | {
                    match c {
                        b'*' => _ = trab.pop (),
                        b'#' => trab.extend (trab.clone ()),
                        b'%' => trab.reverse (),
                        _ => trab.push (c)
                    }
                    trab
                })
        ).unwrap ()
    }
}
