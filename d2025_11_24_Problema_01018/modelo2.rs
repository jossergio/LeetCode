impl Solution {
    pub fn prefixes_div_by5(nums: Vec<i32>) -> Vec<bool> {
        nums.into_iter ().scan (0, | ant, atual | {
            *ant = (*ant << 1 | atual) % 5;
            Some (*ant == 0)
        }).collect ()
    }
}
