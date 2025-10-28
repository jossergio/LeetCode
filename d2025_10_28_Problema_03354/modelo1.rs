impl Solution {
    pub fn count_valid_selections(nums: Vec<i32>) -> i32 {
        let t = nums.len ();
        if t == 1 {
            // O LeetCode teve a pegadinha abaixo
            if nums [0] == 0 {
                return 2;
            }
            // else
            return 0; // Sumariamente
        }
        let mut esquerda: Vec<i32> = vec![0; t];
        let mut direita: Vec<i32> = vec![0; t];
        esquerda [0] = nums [0];
        direita [t - 1] = nums [t - 1];
        let mut resposta: i32 = 0;
        for i in 1..t { // O primeiro já é posto
            esquerda [i] = esquerda [i - 1] + nums [i];
            direita [t - i - 1] = direita [t - i] + nums [t - i - 1];
        }
        resposta += if nums [0] == 0 {
            match direita [1] {
                0 => 2,
                1 => 1,
                _ => 0
            }
        } else { 0 };
        resposta += if nums [t - 1] == 0 {
            match esquerda [t - 2] {
                0 => 2,
                1 => 1,
                _ => 0
            }
        } else { 0 };
        for i in 1..(t - 1) {
            if nums [i] == 0 {
                if esquerda [i - 1] == direita [i + 1] {
                    resposta += 2;
                } else {
                    if i32::abs (esquerda [i - 1] - direita [i + 1]) == 1 {
                        resposta += 1;
                    }
                }
            }
        }
        resposta
    }
}
