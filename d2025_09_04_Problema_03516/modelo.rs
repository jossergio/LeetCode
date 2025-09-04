impl Solution {
    pub fn find_closest(x: i32, y: i32, z: i32) -> i32 {
        let p1 = (z - x).abs ();
        let p2 = (z - y).abs ();
        if p1 == p2 { 0 } else { if p1 < p2 { 1 } else { 2 } }
    }
}
