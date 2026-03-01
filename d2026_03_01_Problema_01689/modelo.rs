impl Solution {
    pub fn min_partitions(n: String) -> i32 {
        n.bytes ()
            .map (| c | c - b'0')
            .max ()
            .unwrap_or (0) as i32
    }
}
