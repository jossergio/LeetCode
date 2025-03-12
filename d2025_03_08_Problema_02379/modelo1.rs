impl Solution {
    pub fn minimum_recolors(blocks: String, k: i32) -> i32 {
        let mut resposta = i32::MAX;
        let b = blocks.as_bytes ();
        let k = k as usize; // Mudar o tipo
        for i in 0..=(b.len () - k) {
            let mut tmp = 0i32;
            for j in 0..k {
                if b [i + j] == b'W' {
                    tmp += 1;
                }
            }
            resposta = std::cmp::min (resposta, tmp);
        }
        resposta
    }
}
