use std::collections::HashSet;
impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        s.as_bytes ()
            .windows (k as usize)
            .collect::<HashSet<_>> ()
            .len () == 1 << k
    }
}
