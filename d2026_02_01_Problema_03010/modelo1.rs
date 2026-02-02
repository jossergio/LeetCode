impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i32 {
        let mut resposta: i32 = nums
            .iter ()
            .take (3)
            .sum (); // Base
        let t = nums.len ();
        for i in 1..(t - 1) {
            for j in (i + 1)..t {
                resposta = resposta.min (nums [0] + nums [i] + nums [j]);
            }
        }
        resposta
    }
}
