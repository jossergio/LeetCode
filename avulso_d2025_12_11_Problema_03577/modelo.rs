impl Solution {
    pub fn count_permutations(complexity: Vec<i32>) -> i32 {
        const modulo: i64 = 1_000_000_007;
        let mut tmp = complexity.clone (); // Para fazer um teste lógico
        tmp.sort ();
        let mut resposta: i64 = 0; // Padrão
        if tmp [0] == complexity [0] && tmp [1] > complexity [0] {
            resposta = 1; // Teremos, pelo menos, uma
            let n = complexity.len () as i64;
            for i in 1..=(n - 1) {
                resposta = (resposta * i) % modulo;
            }
        }
        resposta as i32
    }
}
