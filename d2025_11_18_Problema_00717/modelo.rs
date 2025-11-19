impl Solution {
    pub fn is_one_bit_character(bits: Vec<i32>) -> bool {
        let mut i = 0;
        let t = bits.len () - 1; // Pois o último já é definido
        while i < t {
            if bits [i] == 1 {
                i += 1;
            }
            i += 1; // O normal
        }
        i == t // Ou é maior que isso e é falso
    }
}
