impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        let mut d_h = 0i32; // Distância horizontal em relação à origem
        let mut d_v = 0i32; // Idem, vertical
        for m in moves.chars () {
            match m {
                'U' => d_v -= 1,
                'D' => d_v += 1,
                'L' => d_h -= 1,
                'R' => d_h += 1,
                _ => ()
            }
        }
        d_h == 0 && d_v == 0
    }
}
