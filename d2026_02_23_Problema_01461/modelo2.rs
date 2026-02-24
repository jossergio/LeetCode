use std::collections::HashSet;
use std::collections::VecDeque;
impl Solution {
    pub fn has_all_codes(s: String, k: i32) -> bool {
        let contagem = 2usize.pow (k as u32) - 1; // Também será máscara
        let mut valores = vec![false; contagem + 1]; // O zero também entea
        let mut valor: usize = 0;
        let mut s: VecDeque<usize> = VecDeque::from_iter (
            s.bytes ()
            .map (| v | (v - b'0') as usize));
        for _ in 0..k {
            if let Some (v) = s.pop_front () {
                valor <<= 1;
                valor = (valor + v) & contagem;;
            } else {
                return false; // Nem enche
            }
        }
        valores [valor] = true;
        while !s.is_empty () {
            if let Some (v) = s.pop_front () {
                valor <<= 1;
                valor = (valor + v) & contagem;
                valores [valor] = true;
            }
            // Não precisa testar o None; o teste do laço supre
        }
        valores.iter ().all (| v | *v) // Tudo tem que ser verdadeiro
    }
}
