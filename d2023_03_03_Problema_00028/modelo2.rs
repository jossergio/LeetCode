impl Solution {
    pub fn str_str(haystack: String, needle: String) -> i32 {
        let th: usize = haystack.len ();
        let tn: usize = needle.len ();
        if (th < tn) { // É necessário, pela forma do algoritimo e pelo tipo usado, usize
            return -1
        }
        for i in 0..(th - tn + 1) {
            if (&haystack [i..(i + tn)] == &needle [..]) {
                return i as i32
            }
        }
        return -1; // Não achou
    }
}

