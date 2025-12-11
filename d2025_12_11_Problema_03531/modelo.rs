use std::collections::HashSet;
impl Solution {
    pub fn count_covered_buildings(n: i32, buildings: Vec<Vec<i32>>) -> i32 {
        let n = n as usize; // Muda o tipo
        let mut construcoes: HashSet<Vec<i32>> = HashSet::from_iter (buildings.clone ().into_iter ());
        let mut verticais: Vec<Vec<i32>> = vec![Vec::new (); n + 1]; // 1-begin
        let mut horizontais: Vec<Vec<i32>> = vec![Vec::new (); n + 1]; // Idem
        for b in buildings.clone ().into_iter () {
            verticais [b [0] as usize].push (b [1]);
            horizontais [b [1] as usize].push (b [0]);
        }
        for i in 1..=n { // 1-begin; despreza-se o índice 0
            match verticais [i].len () {
                0 => (), // Não há o que fazer
                1 => { construcoes.remove (&vec![i as i32, *verticais [i].first ().unwrap ()]); },
                _ => { 
                    verticais [i].sort ();
                    construcoes.remove (&vec![i as i32, *verticais [i].first ().unwrap ()]);
                    construcoes.remove (&vec![i as i32, *verticais [i].last ().unwrap ()]);
                    ()
                    }, // _
            } // match verticais
            match horizontais [i].len () {
                0 => (),
                1 => { construcoes.remove (&vec![*horizontais [i].first ().unwrap (), i as i32]); },
                _ => {
                    horizontais [i].sort ();
                    construcoes.remove (&vec![*horizontais [i].first ().unwrap (), i as i32]);
                    construcoes.remove (&vec![*horizontais [i].last ().unwrap (), i as i32]);
                }
            }
        }
        construcoes.len () as i32
    }
}
