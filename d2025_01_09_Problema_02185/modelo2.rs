impl Solution {
    pub fn prefix_count(words: Vec<String>, pref: String) -> i32 {
        let tmp = pref.as_str ();
        words.iter ().filter (|palavra| palavra.starts_with (tmp)).count () as i32
    }
}
