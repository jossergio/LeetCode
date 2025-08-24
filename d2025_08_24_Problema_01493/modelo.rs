impl Solution {
    pub fn longest_subarray(nums: Vec<i32>) -> i32 {
        let mut i = 0 as usize;
        let t = nums.len ();
        let mut zero: Option<usize> = None;
        while i < t && nums [i] != 1 {
            zero = Some (i);
            i += 1;
        }
        let mut j = i;
        let mut resposta: usize = 0;
        while j < t {
            if nums [j] == 1 {
                resposta = resposta.max (j - i);
                if let Some (z) = zero {
                    if z < i {
                        resposta += 1 // Acrescente o zero anterior
                    }
                }
            } else {
                if let Some (z) = zero {
                    if z >= i {
                        i = z + 1; // Pressupõe
                    }
                } else {
                    resposta = resposta.max (j);
                }
                zero = Some (j);
            }
            j += 1;
        }
        (if zero == None { t - 1} else { resposta }) as i32
    }
}
