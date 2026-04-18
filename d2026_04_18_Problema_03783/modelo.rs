impl Solution {
    pub fn mirror_distance(n: i32) -> i32 {
        let mut algarismos: Vec<i32> = Vec::new ();
        let mut origem = n;
        let mut espelho = 0;
        while origem > 0 {
            espelho = (espelho * 10) + (origem % 10);
            origem /= 10;
        }
        n.abs_diff (espelho) as i32
    }
}
