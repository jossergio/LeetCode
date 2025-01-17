impl Solution {
    pub fn minimum_length(s: String) -> i32 {
        let mut resposta = s.len () as i32;
        let mut contador = std::collections::HashMap::new ();
        for c in s.as_bytes () {
            let q = contador.entry (c).or_insert (0 as i32);
            *q += 1;
        }
        for q in contador.values () {
            let mut tmp = *q; // Ou utilizar values_mut no laço
            if tmp >= 3 {
                if tmp % 2 == 0 {
                    tmp -= 1;
                }
                resposta -= tmp - 1; // Só fica o do meio e tira os outros
            }
        }
        resposta
    }
}
