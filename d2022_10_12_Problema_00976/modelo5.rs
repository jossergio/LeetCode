impl Solution {
    pub fn largest_perimeter(nums: Vec<i32>) -> i32 {
        let mut nums = Vec::from (nums); // Como nums não é mutável e precisamos ordenar, gerar outro (de mesmo nome, Rust permite)
        nums.sort ();
        for i in 0..nums.len () {
            println! ("{}", nums [i]);
        }
        for i in (0..=nums.len () - 3).rev () {
            if (nums [i] + nums [i + 1]) > nums [i + 2] {
                return nums [i] + nums [i + 1] + nums [i + 2]
            }
        }
        return 0 // Por omissão; se chegou até aqui, não localizou
    }
}

