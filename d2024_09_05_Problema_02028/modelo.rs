impl Solution {
    pub fn missing_rolls(rolls: Vec<i32>, mean: i32, n: i32) -> Vec<i32> {
        let t = rolls.len () + n as usize;
        let mut soma: i32 = 0;
        for v in rolls { soma += v; }
        let mut mean = mean * (t as i32); // Sombreia, alterando o tipo
        // mean passa a ser a soma integral antes do cálculo da média em si
        if (soma + n > mean) || (soma + n * 6 < mean) { return vec! [];}
        mean -= soma; // Aqui, só ficou a parte relativa a n
        let mut resposta: Vec<i32> = vec! [mean / n; n as usize]; // Divisão inteira
        // Com certeza, o que ficou está entre n e 6 * n
        let mut resto: i32 = mean % n; // O que sobrou, formará adição em alguns elementos
        let mut p: usize = 0; // Iniciará no primeiro
        while resto > 0 {
            let preencher: i32 = 6 - resposta [p];
            if preencher <= resto {
                resposta [p] = 6; // Há suficiente para encher essa posição
                resto -= preencher;
            } else {
                resposta [p] += resto; // Joga o restante aqui...
                resto = 0; // ... e tira todo o resto que ficou
            }
            p += 1;
            // Observar que p, pela quantidade contida em resto,
            // jamais passará o tamanho de resposta
        }
        resposta
    }
}

