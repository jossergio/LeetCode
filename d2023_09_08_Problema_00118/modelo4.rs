impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut resposta: Vec<Vec<i32>> = Vec::new ();
        resposta.push (vec! [1]);
        for i in 1..num_rows as usize { // Será índice de slice
            let mut linha: Vec<i32> = Vec::new ();
            linha.push (1);
            for j in 1..i { // Infere de i ser usize
                linha.push (resposta [i - 1][j] + resposta [i - 1][j - 1]);
            }
            linha.push (1);
            resposta.push (linha);
        }
        resposta
    }
}

