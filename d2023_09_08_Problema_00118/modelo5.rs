impl Solution {
    pub fn generate(num_rows: i32) -> Vec<Vec<i32>> {
        let mut resposta: Vec<Vec<i32>> = vec! [vec! [1; 1]; num_rows as usize]; // Já adiciona a primeira linha
        for i in 1..num_rows as usize { // Será utilizada para índice de slice
            for j in 1..i { // Infere o tipo a patir de i
                let tmp: i32 = resposta [i - 1][j] + resposta [i - 1][j - 1]; // Necessário, por conta de empréstimos (borrows)
                resposta [i].push (tmp);
            }
            resposta [i].push (1);
        }
        resposta
    }
}

