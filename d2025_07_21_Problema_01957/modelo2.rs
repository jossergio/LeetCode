impl Solution {
    pub fn make_fancy_string(s: String) -> String {
        let mut p1: usize = 2;
        let mut a = Vec::<u8>::from_iter (s.into_bytes ());
        for p2 in 2..a.len () {
            if ! (a [p2] == a [p1 - 1] && a [p2] == a [p1 - 2]) {
                a [p1] = a [p2];
                p1 += 1;
            }
        }
        String::from_utf8 (a [..p1.min (a.len ())].to_vec ()).unwrap () // min, para o caso de string de letra única
    }
}
