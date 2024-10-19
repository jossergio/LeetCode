impl Solution {
    pub fn find_kth_bit(n: i32, k: i32) -> char {
        let mut s = vec! ['0']; // Vec<char>; 1o valor já definido
        let k = k as usize; // Sombreia e altera o tipo
        while s.len () < k {
            s.push ('1');
            s.append (&mut Vec::from_iter (s.iter ().take (s.len () - 1).rev ().map (| &v | if v == '1' { &'0' } else { &'1'}).copied ()));
        }
        s [k - 1] // 0-begin x 1-begin
    }
}

