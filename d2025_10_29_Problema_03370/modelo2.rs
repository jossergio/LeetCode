impl Solution {
    pub fn smallest_number(n: i32) -> i32 {
        let mut resposta = 1; // Será, pelo menos, esse
        while resposta < n {
            resposta = (resposta << 1) + 1;
        }
        resposta
    }
}
