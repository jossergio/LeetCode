impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let t = nums.len ();
        nums
            .iter ()
            .fold ((nums [t - 1], 0),
                | (ant, mut cont), atual | {
                    if ant > *atual {
                        cont += 1;
                    }
                    (*atual, cont)
                }).1 < 2
    }
}
