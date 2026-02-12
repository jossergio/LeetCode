use std::collections::HashMap;
impl Solution {
    pub fn longest_balanced(s: String) -> i32 {
        let mut cont: HashMap<u8, i32> = HashMap::new ();
        let s = s.as_bytes ();
        let t = s.len ();
        let mut resposta: usize = 0; // As parcelas de cálculo são desse tipo
        for i in 0..t {
            cont.clear ();
            for j in i..t {
                let atual = *cont.entry (s [j]).and_modify (| v | *v += 1).or_insert (1); // Usarei como parâmetro
                if cont.values ().all (| v | *v == atual) {
                    resposta = resposta.max (j - i + 1);
                }
            }
        }
        resposta as i32
    }
}
