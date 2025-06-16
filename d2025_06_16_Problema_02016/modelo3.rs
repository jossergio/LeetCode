impl Solution {
    pub fn maximum_difference(nums: Vec<i32>) -> i32 {
        nums [1..].iter ().fold ((nums [0], -1), |acum, v| if *v > acum.0 { (acum.0, i32::max (acum.1, *v - acum.0)) } else { (*v, acum.1) }).1
    }
}
