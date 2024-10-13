impl Solution {
    pub fn divide_players(skill: Vec<i32>) -> i64 {
        let mut skill: Vec<i64> = skill.iter ().map (|&v| { v as i64 }).collect (); // Sombreia, converte e torna mutável
        skill.sort ();
        let t = skill.len ();
        let q = skill [0] + skill [t - 1]; // Referência
        let mut total = 0 as i64;
        for i in 0..(t / 2) {
            if skill [i] + skill [t - i - 1] != q {
                return -1;
            }
            // else
            total += (skill [i] * skill [t - i - 1]) as i64;
        }
        total
    }
}

