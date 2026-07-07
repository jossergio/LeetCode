impl Solution {
    pub fn sum_and_multiply(n: i32) -> i64 {
        let mut soma = 0i64;
        let mut digs = 0i64;
        let mut n = n as i64; // Muda o tipo e torna mutável
        let mut pot = 1i64; // Potência Potência a ser serusada ser usada o deslocamento
        while n > 0 {
            let tmp = n % 10;
            soma += tmp; // Não precisa estar no teste
            if tmp != 0 {
                digs += pot * tmp;
                pot *= 10;
            }
            n /= 10;
        }
        digs * soma
    }
}
