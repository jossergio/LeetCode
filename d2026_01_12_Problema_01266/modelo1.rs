impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        let mut resposta = 0;
        for i in 1..points.len () {
            resposta += i32::max (
                i32::abs (points [i - 1][0] - points [i][0]),
                i32::abs (points [i - 1][1] - points [i][1]));
        }
        resposta
    }
}
