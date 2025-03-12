impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let mut acum = 0i32;
        let k = k as usize; // Mudar o tipo
        let b = blocks.as_bytes ();
        for i in 0..k {
            if b [i] == b'W' {
                acum += 1;
            }
        }
        let mut resposta = acum; // Pressupõe 
        for i in k..b.len () {
            if b [i - k] == b'W' { // Repor
                acum -= 1;
            }
            if b [i] == b'W' {
                acum += 1;
            }
            resposta = std::cmp::min (resposta, acum);
        }
        resposta
    }
}
