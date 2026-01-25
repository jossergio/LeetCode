impl Solution {
    pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
        let mut nums = nums.clone ();
        let k = k as usize; // Muda o tioo
        nums.sort ();
        let t = nums.len () - k + 1;
        let mut resposta =
            if k == 1 {
                0
            } else {
                nums [k - 1] - nums [0] // Pode, sim
            };
        for i in 0..t {
            resposta = resposta.min (nums [i +  k - 1] - nums [i]);
        }
        resposta
    }
}
