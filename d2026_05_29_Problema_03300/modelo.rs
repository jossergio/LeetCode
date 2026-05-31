impl Solution {
    pub fn min_element(nums: Vec<i32>) -> i32 {
        nums
            .into_iter ()
            .map (| mut v | {
                let mut r = 0;
                while v > 0 {
                    r += v % 10;
                    v /= 10;
                }
                r
            })
            .min ().unwrap ()
    }
}
