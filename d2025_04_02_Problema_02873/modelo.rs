impl Solution {
    pub fn maximum_triplet_value(nums: Vec<i32>) -> i64 {
        let nums = nums.into_iter ().map (| a | a as i64).collect::<Vec<i64>> (); // Converter
        let mut resposta: i64 = 0;
        let t = nums.len ();
        for i in 0..t {
            for j in (i + 1)..t {
                for k in (j + 1)..t {
                    resposta = i64::max (resposta, (nums [i] - nums [j]) * nums [k])
                }
            }
        }
        resposta // No mínimo, é zero
    }
}
