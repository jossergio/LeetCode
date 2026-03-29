impl Solution {
    pub fn can_be_equal(s1: String, s2: String) -> bool {
        let mut s1: Vec<char> = Vec::from_iter (s1.chars ());
        let mut s2: Vec<char> = Vec::from_iter (s2.chars ());
        let t = s1.len ();
        for i in (2..t).rev () {
            if s1 [i] != s2 [i] {
                if s1 [i - 2] == s2 [i] {
                    s1.swap (i - 2, i);
                } else {
                    return false;
                }
            }
        }
        s1 [0] == s2 [0] && s1 [1] == s2 [1] // Teste final
    }
}
