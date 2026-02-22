impl Solution {
    pub fn binary_gap(n: i32) -> i32 {
        (0..32).filter (| i | n & (1 << i) != 0)
            .collect::<Vec<_>> ()
            .windows (2)
            .map (| a | a [1] - a [0])
            .max ().unwrap_or (0)
    }
}
