use std::collections::{HashMap, HashSet};
impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        let mut rank: HashMap <i32, i32> = HashMap::new ();
        let a = arr.clone ();
        let conjunto: HashSet<i32> = HashSet::from_iter (a.into_iter ());
        let mut unicos: Vec<i32> = Vec::from_iter (conjunto.into_iter ());
        unicos.sort ();
        for (i, v) in unicos.iter ().enumerate () {
            rank.insert (*v, (i + 1) as i32); // Não há atualização de valores
        }
        let mut arr = arr; // Sombreia e torna mutável; usarei para resposta
        for i in 0..arr.len () {
            arr [i] = rank [&arr [i]]; // O próprio vetor original conterá a resposta
        }
        arr
    }
}

