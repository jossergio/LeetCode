use std::collections::HashMap;
impl Solution {
    pub fn is_isomorphic(s: String, t: String) -> bool {
        let mut vinculos_s: HashMap<u8, u8> = HashMap::new ();
        let mut vinculos_t: HashMap<u8, u8> = HashMap::new ();
        let tamanho = s.len (); // São do mesmo tamanho
        let s = s.as_bytes (); // Sombreia
        let t = t.as_bytes (); // Idem
        for i in 0..tamanho {
            if vinculos_s.contains_key (&s [i]) {
                if vinculos_s [&s [i]] != t [i] || !vinculos_t.contains_key (&t [i]) || vinculos_t [&t [i]] != s [i] {
                    return false;
                }
            } else {
                if vinculos_t.contains_key (&t [i]) {
                    return false; // Com certeza não é o correspondente
                }
                vinculos_s.insert (s [i], t [i]);
                vinculos_t.insert (t [i], s [i]);
            }
        }
        true // Se passou por todos os testes, então, é válido
    }
}
