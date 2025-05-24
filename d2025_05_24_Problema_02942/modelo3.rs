impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        words.into_iter ().enumerate ().filter_map (|(i, w)| if w.contains (x) { Some (i as i32) } else { None }).collect::<Vec<i32>> ()
    }
}
