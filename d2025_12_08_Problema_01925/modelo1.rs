impl Solution {
    pub fn count_triples(n: i32) -> i32 {
        let mut cont = 0;
        for i in 1..=n {
            for j in 1..=n {
                let soma = i * i + j * j;
                if soma <= n * n {
                    let raiz = (soma as f32).sqrt ();
                    let dif_f = raiz - raiz.trunc (); // Para melhor vista do código
                    if dif_f == 0.0 {
                        cont += 1;
                    }
                } else {
                    break; // Passou do limite de n
                }
            }
        }
        cont
    }
}
