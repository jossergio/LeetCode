impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let t = nums.len ();
        let mut i: usize = 0;
        for v in 0..=1 { // Organiza os 0's e os 1's
            let mut j = i;
            while j < t {
                if nums [j] == v {
                    nums.swap (i, j);
                    i += 1;
                }
                j += 1;
            }
        }
        // Os 2's são organizados por omissão
    }
}
