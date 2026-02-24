use std::collections::HashSet;
use std::collections::VecDeque;
impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let mut valores: HashSet<i32> = HashSet::new ();
        let contagem = 2i32.pow (k as u32) - 1; // Também será máscara
        let mut valor: i32 = 0;
        let mut s: VecDeque<i32> = VecDeque::from_iter (
            s.bytes ()
            .map (| v | (v - b'0') as i32));
        for _ in 0..k {
            if let Some (v) = s.pop_front () {
                valor <<= 1;
                valor = (valor + v) & contagem;;
            } else {
                return false; // Nem enche
            }
        }
        valores.insert (valor);
        while !s.is_empty () {
            if let Some (v) = s.pop_front () {
                valor <<= 1;
                valor = (valor + v) & contagem;
                valores.insert (valor);
            }
            // Não precisa testar o None; o teste do laço supre
        }
        valores.len () as i32 == contagem + 1
    }
}
