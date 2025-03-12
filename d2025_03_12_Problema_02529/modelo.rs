impl Solution {
    pub fn maximum_count(nums: Vec<i32>) -> i32 {
        std::cmp::max (
            nums.iter ().filter (| &a | if *a < 0 {  true } else { false }).count (),
            nums.iter ().filter (| &a | if *a > 0 { true } else { false }).count ()) as i32
    }
}
