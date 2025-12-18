use std::collections::HashSet;
use std::collections::HashMap;
impl Solution {
    pub fn find_words(words: Vec<String>) -> Vec<String> {
        let linhas = vec![
            HashSet::<char>::from_iter ("qwertyuiop".chars ()),
            HashSet::<char>::from_iter ("asdfghjkl".chars ()),
            HashSet::<char>::from_iter ("zxcvbnm".chars ())
        ]; // linhas
        let tabela: HashMap<char, usize> = HashMap::from_iter (
            linhas.into_iter ().enumerate ().flat_map ( | (i, s) |
                s.into_iter ().map (move | c | (c, i))
            ));
        let verificar = | s: String | {
            let t: Vec<usize> = s.chars ().map (| c | tabela [&c]).collect ();
            let primeiro = t [0];
            t.into_iter ().all (| a | a == primeiro)
        }; // verificar
        words.into_iter ().filter (| w | verificar (w.to_lowercase ())).collect::<Vec<_>> ()
    }
}
