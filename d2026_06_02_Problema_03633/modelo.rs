impl Solution {
    pub fn earliest_finish_time(land_start_time: Vec<i32>, land_duration: Vec<i32>, water_start_time: Vec<i32>, water_duration: Vec<i32>) -> i32 {
        let ls = land_start_time; // Facilitar digitação
        let ld = land_duration;
        let ws = water_start_time;
        let wd = water_duration;
        let tl = ls.len ();
        let tw = ws.len ();
        let mut res = i32::MAX;
        for i in 0..tl {
            for j in 0..tw {
                let (a, b, c, d) = (ls [i], ld [i], ws [j], wd [j]); // Facilitar digitação
                if c > a + b {
                    res = res.min (c + d); // Suficiente, pois a + b é anulado na fórmula real
                } else {
                    res = res.min (a + b + d); // c é engolido na reta
                }
                if a > c + d {
                    res = res.min (a + b);  // Similar acima
                } else {
                    res = res.min (c + d + b); // Similar acima
                }
            }
        }
        res
    }
}
