impl Solution {
    pub fn find_kth_bit(n: i32, k: i32) -> char {
        let mut s = vec! ['0']; // Vec<char>; 1o valor já definido
        let k = k as usize; // Sombreia e altera o tipo
        while s.len () < k {
            let mut tmp: Vec<char> = s
                .iter ()
                .map (| &c | if c == '1' { '0' } else { '1' })
                .collect ();
            tmp.reverse ();
            s.push ('1');
            s.append (&mut tmp);
        }
        s [k - 1] // 0-begin x 1-begin
    }
}
