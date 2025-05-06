impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        let t = nums.len ();
        let mut resposta = Vec::<i32>::with_capacity (t);
        for i in 0..t {
            resposta.push (nums [nums [i] as usize]);
        }
        resposta
    }
}
