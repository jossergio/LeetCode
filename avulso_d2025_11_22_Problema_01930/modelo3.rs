impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let s = s.bytes ().map (| b | (b - b'a') as usize).collect::<Vec<_>> ();
        let mut letras = vec![Option::<(usize, usize)>::None; 26]; // Espaço para todas as letras
        for (i, &c) in s.iter ().enumerate () {
            if let Some (a) = letras [c] {
                letras [c] = Some ((a.0, i));
            } else {
                letras [c] = Some ((i, i)); // Deixa iguais
            }
        }
        let mut pal = std::collections::HashSet::<String>::new ();
        for (c, (i, f)) in letras
        .into_iter ()
        .enumerate ()
        .filter_map (
            | a | if let Some (b) = a.1 { Some ((a.0 as u8, (b.0, b.1))) } else { None })
            {
            for i in (i + 1)..(f) { // Ignora: o primeiro e o último
                pal.insert (unsafe { String::from_utf8_unchecked (vec![c, s [i] as u8, c]) }); // Todos os palídromos, para o problema, são assim
            }
        }
        pal.len () as i32
    }
}
