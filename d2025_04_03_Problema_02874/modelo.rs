impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let nums = nums.into_iter ().map (| a | a as i64).collect::<Vec<i64>> (); // Muda o tipo dos elementos
        let t = nums.len ();
        let mut pre = vec![0 as i64; t];
        let mut pos = vec![0 as i64; t];
        pre [0] = nums [0];
        pos [t - 1] = nums [t - 1];
        for i in 1..(t - 1) { // Desconsidera as pontas
            pre [i] = nums [i].max (pre [i - 1]);
            pos [t - i - 1] = nums [t - i - 1].max (pos [t - i]);
        }
        let mut resposta: i64 = 0;
        for j in 1..(t - 1) { // Desconsidera as pontas
            resposta = resposta.max ((pre [j - 1] - nums [j]) * pos [j + 1]);
        }
        resposta
    }
}
