use std::collections::HashSet;
impl Solution {
    pub fn sort_vowels(s: String) -> String {
        let vogais: HashSet<char> = HashSet::from (['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']);
        let mut listaVogais: Vec<char> = Vec::new ();
        let mut s = s.chars ().collect::<Vec<_>> (); // char
        for c in &s {
            if vogais.contains (c) {
                listaVogais.push (*c);
            }
        }
        listaVogais.sort ();
        let mut proximaVogal = listaVogais.into_iter ();
        for i in 0..s.len () {
            if vogais.contains (&s [i]) {
                s [i] = proximaVogal.next ().unwrap ();
            }
        }
        String::from_utf8 (s.into_iter ().map (| c | c as u8).collect::<Vec<_>> ()).unwrap ()
    }
}
