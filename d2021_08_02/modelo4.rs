impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        for (a, v1) in nums.iter ().enumerate () {
            for (b, v2) in nums [a + 1..].iter ().enumerate () {
                if v1 + v2 == target {
                    return vec! [a as i32, ((b + a) as i32) + 1] // slice inicia em zero
                }
            }
        }
        return vec! [0, 0] // Só para constar; não chega aqui
    }
}

