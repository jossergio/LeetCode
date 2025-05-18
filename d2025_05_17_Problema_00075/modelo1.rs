impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let t = nums.len ();
        let mut i: usize = 0;
        // Busca o primeiro não zero
        while i < t && nums [i] == 0 {
            i += 1;
        }
        let mut j = i + 1;
        // Busca os demais zeros
        while j < t {
            if nums [j] == 0 {
                nums.swap (i, j);
                i += 1
            }
            j += 1;
        }
        j = i;
        // Busca os 1's
        while j < t {
            if nums [j] == 1 {
                nums.swap (i, j);
                i += 1;
            }
            j += 1;
        }
        // Por omissão, os 2's já estão no final
    }
}
l