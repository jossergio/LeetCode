use std::collections::HashSet;
impl Solution {
    pub fn sort_vowels(s: String) -> String {
        let vogais: HashSet<char> = "aeiouAEIOU".chars ().collect ();
        let mut listaVogais: Vec<char> = s.chars ().filter (| c | vogais.contains (c)).collect ();
        listaVogais.sort ();
        let mut proximaVogal = listaVogais.into_iter ();
        String::from_utf8 (
            s.chars ().map (| c | if vogais.contains (&c) { proximaVogal.next ().unwrap () as u8 } else { c as u8 }).collect::<Vec<_>> ()
            ).unwrap ()
    }
}
