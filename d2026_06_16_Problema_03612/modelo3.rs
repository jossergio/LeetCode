impl Solution {
    pub fn process_str(s: String) -> String {
        String::from_iter (
            s
                .chars ()
                .fold (Vec::<char>::new (),
                    | mut trab, c | {
                    match c {
                        '*' => _ = trab.pop (),
                        '#' => trab.extend (trab.clone ()),
                        '%' => trab.reverse (),
                        _ => trab.push (c)
                    }
                    trab
                }).into_iter ()
        )
    }
}
