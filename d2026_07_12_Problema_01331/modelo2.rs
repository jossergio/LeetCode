impl Solution {
    pub fn array_rank_transform(arr: Vec<i32>) -> Vec<i32> {
        let mut unicos: Vec<i32> = Vec::from_iter (
            std::collections::HashSet::<i32>::from_iter (arr.to_vec ().into_iter ()).into_iter ()
        );
        unicos.sort ();
        let mut rank = std::collections::HashMap::<i32, i32>::from_iter (
            unicos.into_iter ().enumerate ().map (| (i, v) | (v, i as i32 + 1)) // O ranking é 1-begin
        );
        arr.into_iter ().map (| v | rank [&v]).collect::<Vec<i32>> ()
    }
}
