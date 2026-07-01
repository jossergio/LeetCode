impl Solution {
    pub fn number_of_substrings(s: String) -> i32 {
        use std::collections::VecDeque;
        let mut a: VecDeque<usize> = VecDeque::new ();
        let mut b: VecDeque<usize> = VecDeque::new ();
        let mut c: VecDeque<usize> = VecDeque::new ();
        let t = s.len (); // Tem que recompor no acumulado
        let mut resp: usize = 0;
        for (i, d) in s.chars ().enumerate () {
            match d {
                'a' => a.push_back (i),
                'b' => b.push_back (i),
                'c' => c.push_back (i),
                _ => ()
            }
            while !a.is_empty () && !b.is_empty () && !c.is_empty () {
                if a.front () < b.front () && a.front () < c.front () {
                    a.pop_front ();
                    resp += t - i;
                }
                if b.front () < a.front () && b.front () < c.front () {
                    b.pop_front ();
                    resp += t - i;
                }
                if c.front () < a.front () && c.front () < b.front () {
                    c.pop_front ();
                    resp += t - i;
                }
            }
        }
        resp as i32
    }
}
