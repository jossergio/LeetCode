impl Solution {
    pub fn get_min_distance(nums: Vec<i32>, target: i32, start: i32) -> i32 {
        nums
            .into_iter ()
            .enumerate ()
            .filter_map (| (i, v) |
                if v == target {
                    Some (i32::abs (i as i32 - start))
                } else {
                    None
                }
            )
            .min ()
            .unwrap ()
    }
}
