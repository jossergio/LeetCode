impl Solution {
    pub fn min_operations(s: String) -> i32 {
        i32::min (
            s.bytes ()
                .enumerate ()
                .map (| (i, b) | ((i as i32 % 2) - (b - b'0') as i32).abs ())
                .sum (),
            s.bytes ()
                .enumerate ()
                .map (| (i, b) | ((1 - (i as i32 % 2)) as i32 - (b - b'0') as i32).abs ())
                .sum ()
        )
    }
}
