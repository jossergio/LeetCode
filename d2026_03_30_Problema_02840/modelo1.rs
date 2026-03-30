impl Solution {
    pub fn check_strings(s1: String, s2: String) -> bool {
        let menos_2 = | a | if a >= 2 { Some (a - 2) } else { None };
        let mut s1: Vec<char> = Vec::from_iter (s1.chars ());
        let mut s2: Vec<char> = Vec::from_iter (s2.chars ());
        let t = s1.len (); // São do mesmo tamanho
        for i in (2..t).rev () {
            if s1 [i] != s2 [i] {
                let mut prox: Option<usize> = menos_2 (i);
                while let Some (j) = prox && s1 [j] != s2 [i] {
                    prox = menos_2 (j);
                }
                if let Some (j)= prox {
                    s1.swap (j, i);
                } else {
                    return false;
                }
            }
        }
        s1 [0] == s2 [0] && 
            (t == 1 || s1 [1] == s2 [1]) // Teste final
    }
}
