impl Solution {
    pub fn has_increasing_subarrays(nums: Vec<i32>, k: i32) -> bool {
        if nums.len () < 4 {
            return true; // Nâo há condições de não ser
        }
        let k = k as usize; // Muda o tipo
        let limite = nums.len () - 2 * k;
        let mut i = 0;
        while i <= limite {
            let mut tmp = 1usize; // Começa pelo segundo
            while tmp < k && nums [i + tmp] > nums [i + tmp - 1] && nums [i + k + tmp] > nums [i + k + tmp - 1] {
                tmp += 1;
            }
            if tmp == k {
                return true;
            }
            // else
            i += tmp;
        }
        false // Não achou
    }
}
