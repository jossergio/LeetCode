impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        let mut resposta: i32 = -1;
        let t = nums.len ();
        for i in 0..t {
            for j in (i + 1)..t {
                if nums [j] > nums [i] {
                    resposta = i32::max (resposta, nums [j] - nums [i]);
                }
            }
        }
        resposta
    }
}
