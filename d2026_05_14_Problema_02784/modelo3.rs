impl Solution {
    pub fn is_good(nums: Vec<i32>) -> bool {
        let mut nums = nums; // Torna mutável
        nums.sort ();
        let ultimo = nums.len () - 1; // Valor para i último
        for (i, v) in nums.into_iter ().enumerate () {
            if v != (i + 1).min (ultimo) as i32 {
                return false;
            }
        }
        true // Passou nos testes
    }
}
