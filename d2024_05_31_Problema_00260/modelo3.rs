use std::collections::HashMap;

impl Solution {
    pub fn single_number(nums: Vec<i32>) -> Vec<i32> {
        let mut contagem = HashMap::new ();
        for n in nums {
            let c = contagem.entry (n).or_insert (0);
            *c += 1
        }
        let mut resposta: Vec<i32> = Vec::new ();
        for (i, v) in contagem { // Não precisa se preocupar com o proprietário
            if v == 1 {
                resposta.push (i);
            }
        }
        resposta
    }
}

