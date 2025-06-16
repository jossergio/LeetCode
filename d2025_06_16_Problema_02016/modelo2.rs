impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        nums.iter ().enumerate ().fold (-1, |acum, (i, v)| {
            let tmp = nums [(i + 1)..].iter ().map (|x| 
            if x > v { x - v} else { -1 }).max ().unwrap_or (-1);
            if tmp > acum { tmp } else { acum }
        })
    }
}
