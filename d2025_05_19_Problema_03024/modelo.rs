impl Solution {
    pub fn triangle_type(nums: Vec<i32>) -> String {
        let mut nums = nums.clone (); // Sombreia e torna mutável
        nums.sort ();
        if nums [0] + nums [1] <= nums [2] {
            return String::from ("none");
        }
        if nums [0] == nums [1] || nums [1] == nums [2] {
            if nums [0] == nums [2] { // Os três são iguais
                return String::from ("equilateral");
            } else {
                return String::from ("isosceles");
            }
        }
        // else
        String::from ("scalene")
    }
}
