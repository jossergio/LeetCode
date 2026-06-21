impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        gain
            .into_iter ()
            .scan (0, | acum, atual | {
                *acum += atual;
                Some (*acum)
            })
            .max ().unwrap_or (0).max (0)
    }
}
