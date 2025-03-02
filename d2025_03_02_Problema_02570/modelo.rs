use std::collections::HashMap;
impl Solution {
    pub fn merge_arrays(nums1: Vec<Vec<i32>>, nums2: Vec<Vec<i32>>) -> Vec<Vec<i32>> {
        let mut h: HashMap<i32, i32> = HashMap::new ();
        let (mut menor, mut maior) = (i32::MAX, i32::MIN);
        for a in nums1 {
            if a [0] < menor {
                menor = a [0];
            }
            if a [0] > maior {
                maior = a [0];
            }
            h.insert (a [0], a [1]);
        }
        for b in nums2 {
            if b [0] < menor {
                menor = b [0];
            }
            if b [0] > maior {
                maior = b [0];
            }
            let v = h.entry (b [0]).or_insert (0);
            *v += b [1];
        }
        let mut resposta: Vec<Vec<i32>> = Vec::new ();
        for c in menor..=maior {
            if let Some (v) = h.get (&c) {
                resposta.push (vec![c, *v]);
            }
        }
        resposta
    }
}
