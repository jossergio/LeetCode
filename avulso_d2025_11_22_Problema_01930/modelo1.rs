impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let s = s.bytes ().collect::<Vec<_>> (); // Porque String, em Rust, não indexa; bytes, porque UTF8 é gerado com esse tipo
        let mut letras = std::collections::HashMap::<u8, (usize, Option<usize>)>::new ();
        for (i, c) in s.iter ().enumerate () {
            match letras.get (c) {
                Some (p) => _ = letras.insert (*c, (p.0, Some (i))), // Atualiza
                None => _ = letras.insert (*c, (i, None))
            }
        }
        let mut pal = std::collections::HashSet::<String>::new ();
        for (c, p) in letras {
            if let Some (l2) = p.1 {
                for i in (p.0 + 1)..(l2) { // Ignora: o primeiro e o último
                    pal.insert (unsafe { String::from_utf8_unchecked (vec![c, s [i], c]) }); // Todos os palídromos, para o problema, são assim
                }
            } // Caso contrário, não precisa fazer nada
        }
        pal.len () as i32
    }
}
