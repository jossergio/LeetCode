impl Solution {
    pub fn check_ones_segment(s: String) -> bool {
        s.as_bytes ()
            . windows (2)
            .filter (| a | a [0] == b'0' && a [1] == b'1')
            .count () == 0
    }
}
