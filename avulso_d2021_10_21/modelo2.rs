impl Solution {
    pub fn is_palindrome(x: i32) -> bool {
        
        let digitos = x.to_string ();
        let digitos = digitos.as_bytes (); // Reutiliza, sobrepondo
        
        let mut i: usize = 0;
        let mut j: usize = digitos.len () - 1;
        
        while i < j {
            if digitos [i] != digitos [j] {
                return false
            }
            i += 1;
            j -= 1;
        }
        
        return true
    }
}

