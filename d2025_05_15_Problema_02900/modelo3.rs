impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        (0..words.len ()).filter (|&a| a == 0 || groups [a] != groups [a - 1]).map (|a| words [a].clone ()).collect::<Vec<String>> ()
    }
}
