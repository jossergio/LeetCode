impl Solution {
    pub fn is_power_of_three(n: i32) -> bool {
        
        let mut nLong: i64 = n as i64; // Redefine a variável
        let mut i: i64 = 1; // Um contador
        
        while i <= nLong {
            if i == nLong {
                return true;
            }
            i *= 3;
        }
        
        return false;
    }
}

