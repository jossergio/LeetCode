impl Solution {
    pub fn find_words_containing(words: Vec<String>, x: char) -> Vec<i32> {
        words.into_iter ().enumerate ().filter_map (|a| if a.1.find (x) != None { Some (a.0 as i32) } else { None }).collect::<Vec<i32>> ()
    }
}
