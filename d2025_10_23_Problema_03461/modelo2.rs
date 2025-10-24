impl Solution {
    pub fn has_same_digits(s: String) -> bool {
        let mut s: Vec<u8> = s.bytes ().map (| c | c - b'0' ).collect ();
        while s.len () > 2 {
            for i in 1..s.len () {
                s [i - 1] = (s [i - 1] + s [i]) % 10;
            }
            _ = s.pop ();
        }
        s [0] == s [1]
    }
}
