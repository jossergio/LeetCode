impl Solution {
    pub fn area_of_max_diagonal(dimensions: Vec<Vec<i32>>) -> i32 {
        let mut m_diag = 0f64;
        let mut resposta: i32 = 0;
        for d in dimensions {
            let tmp = f64::from (d [0] * d [0] + d [1] * d [1]).sqrt ();
            if tmp > m_diag {
                m_diag = tmp;
                resposta = d [0] * d [1];
            } else if tmp == m_diag { // Se iguais, pega o de maior área
                resposta = resposta.max (d [0] * d [1]);
            }
        }
        resposta
    }
}
