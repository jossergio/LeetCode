impl Solution {
    pub fn num_equiv_domino_pairs(dominoes: Vec<Vec<i32>>) -> i32 {
        let mut pares = std::collections::HashMap::<i32, i32>::new ();
        let mut resposta = 0; // i32
        for d in dominoes {
            let tmp = pares.entry (if d [0] > d [1] { d [1] * 12 + d [0] } else { d [0] * 12 + d [1] }).or_insert (0);
            resposta += *tmp;
            *tmp += 1;
        }
        resposta
    }
}
