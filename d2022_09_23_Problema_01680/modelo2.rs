impl Solution {
    pub fn concatenated_binary(n: i32) -> i32 {
        
        let MODULO:i64 = 1000000007;
        let mut acumulado:i64 = 0;
        
        for i in 1..=n as i64 {
            
            let mut deslocamento:i64 = i; // Desloca com base no bit 1 mais significativo do valor que vai entrar, para dar espao
            
            while deslocamento > 0 {
                acumulado <<= 1; // Desloca para a esquerda
                deslocamento >>= 1; // Desloca para a direita
            }
            
            acumulado += i;
            acumulado %= MODULO;
        }
        
        return acumulado as i32
    }
}

