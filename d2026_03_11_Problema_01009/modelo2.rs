impl Solution {
    pub fn bitwise_complement(n: i32) -> i32 {
        let mut soma = 1;
        let mut tmp = n; // n será aproveitado ao final
        while { tmp >>= 1; tmp } != 0 {
            soma = (soma << 1) + 1;
        }
        soma - n // Preencheu soma com uns até o limite do tamanho n binário; extrai-se complemento
    }
}
