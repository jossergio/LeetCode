impl Solution {
    pub fn max_increasing_subarrays(nums: Vec<i32>) -> i32 {
        let t = nums.len ();
        let mut anterior = 1usize; // Sequência anterior
        let mut atual = 1usize; // Há, pelo menos, o item atual
        let mut resposta = 1usize; // Idem
        for i in 1..t {
            if nums [i] > nums [i - 1] {
                atual += 1;
            } else {
                if atual > anterior {
                    resposta = resposta.max (anterior.max (atual / 2));
                    anterior = atual;
                } else {
                    resposta = resposta.max (anterior.min (atual));
                    anterior = 1;
                }
                atual = 1;
            }
        }
        if atual > anterior { resposta.max (anterior.max (atual / 2)) as i32 } else { resposta.max (anterior.min (atual)) as i32 }
    }
}
