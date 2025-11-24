impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        let mut resposta= vec! [false; nums.len ()];
        let mut acum = 0;
        for (i, v) in nums.into_iter ().enumerate () {
            acum = ((acum << 1) + v) % 5;
            resposta [i] = acum == 0;
        }
        resposta
    }
}
