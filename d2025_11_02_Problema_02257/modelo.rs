impl Solution {
    pub fn count_unguarded(m: i32, n: i32, guards: Vec<Vec<i32>>, walls: Vec<Vec<i32>>) -> i32 {
        let n = n as usize; // Muda o tipo
        let m = m as usize; // Idem
        let mut guardas = vec![vec![false; n]; m];
        let mut paredes = vec![vec![false; n]; m];
        for a in guards {
            guardas [a [0] as usize][a [1] as usize] = true;
        }
        for a in walls {
            paredes [a [0] as usize][a [1] as usize] = true;
        }
        let mut horizontal = false;
        let mut vertical = vec![false; n];
        let mut visitados = vec![vec![false; n]; m];
        let mut resposta = 0;
        for i in 0..m {
            for j in 0..n {
                if guardas [i][j] {
                    horizontal = true;
                    vertical [j] = true;
                    resposta += 1; // Considera parte da resposta
                } else if paredes [i][j] {
                    horizontal = false;
                    vertical [j] = false;
                    resposta += 1; // Idem
                } else {
                    if horizontal || vertical [j] {
                        resposta += 1;
                        visitados [i][j] = true;
                    }
                }
            }
            horizontal = false; // Reinicia para próxima linha
        }
        vertical = vec![false; n]; // Zera as colunas
        for i in (0..m).rev () {
            // Aqui, não precisa atualizar resposta a cada parede ou guarda
            for j in (0..n).rev () {
                if guardas [i][j] {
                    horizontal = true;
                    vertical [j] = true;
                } else if paredes [i][j] {
                    horizontal = false;
                    vertical [j] = false;
                } else {
                    if !visitados [i][j] && (horizontal || vertical [j]) {
                        resposta += 1;
                    }
                }
            }
            horizontal = false; // Zera para próxima linha
        }
        (m * n) as i32 - resposta // Por conta da conversão, tive que tornar a precedência explícita
    }
}
