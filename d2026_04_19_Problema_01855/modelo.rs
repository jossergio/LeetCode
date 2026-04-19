impl Solution {
    pub fn max_distance(nums1: Vec<i32>, nums2: Vec<i32>) -> i32 {
        let mut resposta: i32 = 0;
        let mut i = 0usize;
        let mut j = 0usize;
        let t1 = nums1.len ();
        let t2 = nums2.len ();
        while j < t2 {
            while i < t1 && nums1 [i] > nums2 [j] {
                i += 1;
            }
            if i == t1 {
                break; // Não gosto disso, mas vou usar
            }
            j = i; // Atualiza
            while j < t2 && nums1 [i] <= nums2 [j] {
                resposta = resposta.max ((j - i) as i32);
                j += 1;
            }
            i += 1;
        }
        resposta
    }
}
