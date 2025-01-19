impl Solution {
    pub fn count_prefix_suffix_pairs(words: Vec<String>) -> i32 {
        let mut resposta: i32 = 0;
        for (i, w) in words.iter ().enumerate () {
            for w2 in words [(i + 1)..].iter () {
                if w.len () <= w2.len () {
                    let t = w2.len ();
                    let p1 = match w2.find (w) {
                        Some (p) => if p == 0 { 0 } else { t },
                        None => t
                    }; // t = joga para o final, pois não achou
                    let p2 = match w2.rfind (w) {
                        Some (p) => if p == t - w.len () { p } else { t },
                        None => t
                    }; // Idem
                    if  p1 != t && p2 != t {
                        resposta += 1;
                    }
                }
            }
        }
        resposta
    }
}
