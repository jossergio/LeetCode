impl Solution {
    pub fn judge_circle(moves: String) -> bool {
        let mut d_h = 0i32; // Distância horizontal em relação à origem
        let mut d_v = 0i32; // Idem, vertical
        for m in moves.chars () {
            d_h += match m {
                'L' => -1,
                'R' => 1,
                _ => 0
            };
            d_v += match m {
                'U' => -1,
                'D' => 1,
                _ => 0
            };
        }
        d_h == 0 && d_v == 0
    }
}
