impl Solution {
    pub fn min_operations(s: String) -> i32 {
        let t = s.len ();
        let tipo1: Vec<i32> = (0..t)
            .map (| i | if i % 2 == 0 { 0 } else { 1 })
            .collect ();
        let tipo2: Vec<i32> = (0..t)
            .map (| i | if i % 2 == 0 { 1 } else { 0 })
            .collect ();
        
        let s: Vec<i32> = s.bytes ().map (| c | (c - b'0') as i32).collect ();
        i32::min (
            s.iter ()
                .zip (tipo1.iter ())
                .map (| (a, b) | (a - b).abs ())
                .sum (),
            s.iter ()
                .zip (tipo2.iter ())
                .map (| (a, b) | (a - b).abs ())
                .sum ()
        )
    }
}
