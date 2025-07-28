impl Solution {
    pub fn count_hill_valley(nums: Vec<i32>) -> i32 {
        let mut cont = 0; // i32
        let mut dif = nums [0];
        for i in 1..(nums.len () - 1) {
            if (nums [i] > nums [i - 1] && nums [i] > nums [i + 1]) ||
            (nums [i] < nums [i - 1] && nums [i] < nums [i + 1]) {
                cont += 1;
                dif = nums [i];
            } else {
                if (nums [i] > dif && nums [i] > nums [i + 1]) ||
                (nums [i]< dif && nums [i] < nums [i + 1]) {
                    cont += 1;
                    dif = nums [i];
                }
            }
        }
        cont
    }
}
