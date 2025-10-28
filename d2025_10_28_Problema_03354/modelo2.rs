impl Solution {
    pub fn count_valid_selections(nums: Vec<i32>) -> i32 {
        let mut esquerda: i32 = 0;
        let mut direita: i32 = nums.iter ().sum ();
        let mut resposta = 0;
        for v in nums {
            if v == 0 {
                resposta += match i32::abs (esquerda - direita) {
                    0 => 2,
                    1 => 1,
                    _ => 0
                }
            } else {
                esquerda += v;
                direita -= v;
            }
        }
        resposta
    }
}
