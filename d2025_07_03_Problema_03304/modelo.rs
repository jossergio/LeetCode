impl Solution {
    pub fn kth_character(k: i32) -> char {
        let mut s = String::from ("a");
        let k = k as usize;
        while s.len () < k {
            s.push_str (&String::from_utf8 (s.bytes ().map (|c| if c == b'z' { b'a' } else { c + 1 }).collect::<Vec<_>> ()).unwrap ());
        }
        s.as_bytes () [k - 1] as char // 0-begin
    }
}
