impl Solution {
    pub fn string_matching(words: Vec<String>) -> Vec<String> {
        let mut words = words; // Para tornar mutável
        words.sort_by (| s1, s2 | { s1.len ().cmp (&s2.len ()) });
        let mut resposta: Vec<String> = Vec::new ();
        for (i, w) in words.iter ().enumerate () {
            for w2 in words [i + 1..].iter () {
                if w2.contains (w) {
                    resposta.push (w.clone ());
                    break;
                }
            }
        }
        resposta
    }
}
