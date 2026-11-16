use std::collections::VecDeque;
impl Solution {
    pub fn digit_sum(s: String, k: i32) -> String {
        let mut s: VecDeque<i32> =
            s.bytes ()
            .map (| c | (c - b'0') as i32)
            .collect (); // Transforma em valores base calculáveis
        let k = k as usize; // Muda o tipo
        fn dig_rev (mut d: i32) -> Vec<i32> { // Retorna os dígitos invertidos
            let mut tmp: Vec<i32> = Vec::new ();
            if d == 0 { // Há o vazio; e há o elemento 0
                tmp.push (0);
            }
            while d > 0 { // Se 0, antes, nem executa o laço
                tmp.push (d % 10);
                d /= 10;
            }
            tmp.reverse ();
            tmp
        }
        while s.len () > k {
            let mut tmp: Option<i32> = None;
            let t = s.len (); // Temporário, pois s muda o tamanho dinamicamente
            for i in 0..t {
                if let Some (v) = tmp {
                    tmp = Some (v + s.pop_front ().unwrap ());
                } else {
                    tmp = Some (s.pop_front ().unwrap ());
                }
                if (i + 1) % k == 0 {
                    for d in dig_rev (tmp.unwrap ()) {
                        s.push_back (d);
                    }
                    tmp = None;
                }
            }
            if let Some (v) = tmp {
                for d in dig_rev (v) {
                    s.push_back (d);
                }
            }
        }
        String::from_utf8 (s.into_iter ()
            .map (| c | (c + b'0' as i32) as u8)
            .collect ())
            .unwrap ()
    }
}
