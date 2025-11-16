impl Solution {
    pub fn num_sub(s: String) -> i32 {
        let modulo = 1000000007;
        let mut uns = 0;
        let mut resposta = 0;
        for c in s.bytes () {
            if c == b'0' {
                uns = 0;
            } else {
                uns += 1;
                resposta = (resposta + uns) % modulo;
            }
        }
        resposta 
    }
}
