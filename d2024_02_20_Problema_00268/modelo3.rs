impl Solution {
    pub fn missing_number(nums: Vec<i32>) -> i32 {
        let t = nums.len () as i32;
        (t * (t + 1)) / 2 - nums.into_iter ().sum::<i32> ()
        // Utiliza soma de uma P.A. de razão 1
        // Há um termo faltante; por isso o parâmetro t + 1
        // O primeiro termo é, sempre, 0; por isso a omissão no primeiro fator
        // O termo faltante é a diferença dessas somas (o termo que faltou ser somado de nums)
    }
}
