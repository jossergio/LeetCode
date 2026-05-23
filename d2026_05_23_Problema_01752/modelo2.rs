impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        nums
            .iter ()
            .fold ((nums [nums.len () - 1], 0),
                | (ant, mut cont), atual | {
                    if ant > *atual {
                        cont += 1;
                    }
                    (*atual, cont)
                }).1 < 2
    }
}
