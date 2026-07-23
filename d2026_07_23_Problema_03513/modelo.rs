impl Solution {
    pub fn unique_xor_triplets(nums: Vec<i32>) -> i32 {
        fn mais_significante (mut a: i32) -> u32 {
            let mut i = 0; // Infere u32
            while a > 0 {
                i += 1;
                a >>= 1;
            }
            i
        }
        match nums.len () {
            0 => 0,
            1 => 1,
            2 => 2,
            _ => 2i32.pow (mais_significante (nums.into_iter ().max ().unwrap ()))
        }
    }
}
