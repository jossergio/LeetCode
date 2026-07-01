impl Solution {
    pub fn num_of_strings(patterns: Vec<String>, word: String) -> i32 {
        patterns
            .into_iter ()
            .map (| s |
                if word.contains (s.as_str ()) { 1 } else { 0 }
            )
            .sum ()
    }
}
