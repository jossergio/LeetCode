impl Solution {
    pub fn get_longest_subsequence(words: Vec<String>, groups: Vec<i32>) -> Vec<String> {
        let mut resposta: Vec<String> = Vec::new ();
        for (i, s) in words.into_iter ().enumerate () {
            if i == 0 || groups [i] != groups [i - 1] {
                resposta.push (s);
            }
        }
        resposta
    }
}
