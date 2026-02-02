impl Solution {
    pub fn minimum_cost(nums: Vec<i32>) -> i32 {
        let mut resto: Vec<_> = nums
            .iter ()
            .skip (1)
            .collect ();;
        resto.sort ();
        nums [0] + resto [0] + resto [1]
    }
}
