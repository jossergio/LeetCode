impl Solution {
    pub fn min_removal(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums: Vec<i64> = nums.into_iter ().map (| v | v as i64).collect (); // Torna mutável; muda o tipo
        // Mudar to tipo porque os cálculos intermediários podem passar i32
        let k = k as i64; // Muda o tipo
        nums.sort ();
        let t = nums.len ();
        let mut resposta = t; // Limite lógico
        let mut direita: usize = 0;
        for esquerda in 0..t {
            while direita < t && nums [esquerda] * k >= nums [direita] {
                direita += 1;
            }
            resposta = resposta.min (t - (direita - esquerda));
        }
        resposta as i32
    }
}
