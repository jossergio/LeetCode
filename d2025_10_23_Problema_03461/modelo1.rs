impl Solution {
    pub fn has_same_digits(s: String) -> bool {
        let mut s: Vec<u8> = s.bytes ().map (| c | c - b'0' ).collect ();
        while s.len () > 2 {
            let t = s.len ();
            let mut tmp: Vec<u8> = vec! [0; t - 1];
            for i in 1..t {
                tmp [i - 1] = (s [i - 1] + s [i]) % 10;
            }
            s = tmp;
        }
        s [0] == s [1]
    }
}
