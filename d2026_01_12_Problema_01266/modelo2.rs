impl Solution {
    pub fn min_time_to_visit_all_points(points: Vec<Vec<i32>>) -> i32 {
        points.windows (2).fold (0, | acum, atual |
            acum + i32::max (
                i32::abs (atual [0][0] - atual [1][0]),
                i32::abs (atual [0][1] - atual [1][1])
                )
            )
    }
}
