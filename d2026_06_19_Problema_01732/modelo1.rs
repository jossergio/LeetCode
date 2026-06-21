impl Solution {
    pub fn largest_altitude(gain: Vec<i32>) -> i32 {
        gain
            .into_iter ()
            .fold ((0, 0), | (maior, mut acum), atual | {
                acum += atual;
                (maior.max (acum), acum)
            }
            ).0
    }
}
