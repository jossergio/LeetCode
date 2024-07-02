impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        use std::collections::HashMap;
        let mut a: HashMap<i32, i32> = HashMap::new ();
        for i in nums1 {
            let v = a.entry (i).or_insert (0);
            *v += 1;
        }
        let mut resposta: Vec<i32> = Vec::new ();
        for i in nums2 {
            let valor = a.entry (i).or_insert (0);
            if *valor > 0 {
                *valor -= 1;
                resposta.push (i);
            }
        }
        return resposta
    }
}

