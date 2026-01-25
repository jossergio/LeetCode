impl Solution {
    pub fn minimum_difference(nums: Vec<i32>, k: i32) -> i32 {
        if k == 1 {
            return 0; // Sumariamenre
        }
        let k = k as usize; // Muda o tipo
        let mut nums = nums; // Torna mutável
        nums.sort ();
        nums.windows (k).map (| w | w [k - 1] - w [0]).min ().unwrap ()
    }
}
