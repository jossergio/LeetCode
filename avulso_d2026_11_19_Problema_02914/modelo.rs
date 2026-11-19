impl Solution {
    pub fn min_changes(s: String) -> i32 {
        s
            .bytes ()
            .map (| c | c as i32)
            .collect::<Vec<_>> ()
            .chunks (2)
            .map (| a | (a [0] - a [1]).abs ())
            .sum ()
    }
}
