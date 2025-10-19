impl Solution {
    pub fn remove_anagrams(words: Vec<String>) -> Vec<String> {
        let ordenados = words.iter ()
            .map (| w | {
                let mut tmp = w.chars ().collect::<Vec<_>> ();
                tmp.sort ();
                tmp
            }).collect::<Vec<_>> ();
        let mut ficam = vec![0 as usize]; // O 1o sempre fica
        for i in 1..words.len () {
            if ordenados [i] != ordenados [i - 1] {
                ficam.push (i);
            }
        }
        ficam.into_iter ().map (| i | &words [i]).map (| s | s.clone ()).collect::<Vec<_>> ()
    }
}
