impl Solution {
    pub fn possible_string_count(word: String) -> i32 {
        let mut resposta = 0; // i32
        let word = word.as_bytes ();
        for i in 1..word.len () {
            if word [i] == word [i - 1] { resposta += 1; }
        }
        resposta + 1 // A própria palavra
    }
}
