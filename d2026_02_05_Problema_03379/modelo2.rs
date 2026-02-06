impl Solution {
    pub fn construct_transformed_array(nums: Vec<i32>) -> Vec<i32> {
        let t = nums.len () as i32;
        nums
            .iter ()
            .enumerate ()
            .map (|(i, &v)| {
                let mut base = ((t + (i as i32 + v) % t) % t) as usize;
                nums [base]
            })
            .collect ()
    }
}
