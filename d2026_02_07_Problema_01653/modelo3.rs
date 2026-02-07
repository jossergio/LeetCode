impl Solution {
    pub fn minimum_deletions(s: String) -> i32 {
        let s = s.as_bytes ().to_vec ();
        let mut c_a = s.iter ().filter (| c | **c == b'a').count () as i32;
        let t = s.len ();
        let mut resposta = t as i32; // O máximo de remoções possíveis
        let mut c_b = 0;
        for c in s {
            if c == b'a' {
                c_a -= 1;
            }
            resposta = resposta.min (c_a + c_b); // Elimina os a's posteriores e os b's anteriores
            if c == b'b' {
                c_b += 1;
            }
        }
        resposta
    }
}
