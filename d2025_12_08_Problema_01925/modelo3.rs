impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut cont = 0;
        for i in 1..=n {
            for j in i..=n {
                let soma = i * i + j * j;
                if soma <= n * n {
                    let raiz = (soma as f32).sqrt (); // Para melhor vista do código
                    if raiz.fract () == 0.0 {
                        cont += 2; // a,b e b,a
                    }
                } else {
                    break; // Passou do limite de n
                }
            }
        }
        cont
    }
}
