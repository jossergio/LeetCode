impl Solution {
    pub fn find_min(nums: Vec<i32>) -> i32 {
        let mut esq = 0usize;
        let mut dir = nums.len () - 1;
        while esq < dir {
            let meio = (esq + dir) / 2;
            if nums [meio] > nums [dir] {
                esq = meio + 1;
            } else {
                dir = meio;
            }
        }
        nums [esq]
    }
}
