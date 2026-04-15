impl Solution {
    pub fn closest_target(words: Vec<String>, target: String, start_index: i32) -> i32 {
        let k = start_index as usize; // Muda o tipo e diminui o nome
        let t = words.len ();
        words
            .into_iter ()
            .enumerate ()
            .filter_map (| (i, s) | 
                if s == target {
                    let dist = k.abs_diff (i);
                    Some (dist.min (t - dist) as i32)
                    // Tem que ter a conversão de tipo aqui, para ser compatível com o valor de unwrap_or, no final
                    // A distância de trás para frente é o que sobrou do todo (a diferença)
                } else {
                    None
                }
            )
            .min ()
            .unwrap_or (-1)
    }
}
