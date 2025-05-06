impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        nums.clone ().into_iter ().map (| n | nums [n as usize]).collect::<Vec<i32>> ()
    }
}
