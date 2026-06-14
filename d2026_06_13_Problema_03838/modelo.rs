impl Solution {
    pub fn map_word_weights(words: Vec<String>, weights: Vec<i32>) -> String {
        String::from_iter (
            words
                .into_iter ()
                .map (| w |
                    (b'z' - w.bytes ()
                        .fold (0, | acum, atual |
                            (acum + weights [(atual - b'a') as usize]) % 26) as u8) as char)
        )
    }
}
