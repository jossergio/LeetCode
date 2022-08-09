impl Solution {
    pub fn two_sum(nums: Vec<i32>, target: i32) -> Vec<i32> {
        
        let mut a: i32 = 0;
        let mut b: i32 = 0;
        
        'externo: while (a < nums.len () as i32) {
            
            b = a + 1;
            
            while (b < nums.len () as i32) {
                if ((nums [a as usize] + nums [b as usize]) == target) {
                    break 'externo;
                }
                b += 1;
            }
            
            a += 1;
        }
        
        let mut retorno: Vec<i32> = vec![a, b];
        
        return retorno;
    }
}

