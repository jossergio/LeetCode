impl Solution {
    pub fn count_palindromic_subsequence(s: String) -> i32 {
        let s = s.bytes ().map (| b | (b - b'a') as usize).collect::<Vec<_>> ();
        let mut letras = vec![Option::<(usize, usize)>::None; 26]; // Espaço para todas as letras
        for (i, &c) in s.iter ().enumerate () {
            if let Some (a) = letras [c] {
                letras [c] = Some ((a.0, i)); // Atualiza o segundo
            } else {
                letras [c] = Some ((i, i)); // Deixa iguais
            }
        }
        let mut resposta = 0;
        for (c, (i, f)) in letras
        .into_iter ()
        .enumerate ()
        .filter_map (
        | a | if let Some (b) = a.1 { Some ((a.0 as u8, (b.0, b.1))) } else { None })
        {
            let mut feitos = vec![false; 26];
            for k in (i + 1)..f { // Ignora: o primeiro e o último
                if !feitos [s [k]] {
                    resposta += 1;
                }
                // else
                feitos [s [k]] = true;
            }
        }
        resposta
    }
}
