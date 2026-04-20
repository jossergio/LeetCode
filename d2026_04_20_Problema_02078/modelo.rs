impl Solution {
    pub fn max_distance(colors: Vec<i32>) -> i32 {
        i32::max (
            colors
                .iter ()
                .enumerate ()
                .rev ()
                .find_map (| (i, c) |
                    if *c == colors [0] {
                        None
                    } else {
                        Some (i)
                    }
                ).unwrap () as i32,
            colors
                .iter ()
                .enumerate ()
                .find_map (| (i, c) |
                    if *c == colors [colors.len () - 1] {
                        None
                    } else {
                        Some (colors.len () - 1 - i)
                    }
                ).unwrap () as i32
        )
    }
}
