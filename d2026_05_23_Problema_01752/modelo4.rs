impl Solution {
    pub fn check(nums: Vec<i32>) -> bool {
        let ult = nums [nums.len () - 1];
        nums
            .into_iter ()
            .fold ((ult, 0),
                | (ant, mut cont), atual | {
                    if ant > atual {
                        cont += 1;
                    }
                    (atual, cont)
                }).1 < 2
    }
}
