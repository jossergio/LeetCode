func findCenter(edges [][]int) int {
    if edges [0][0] == edges [1][0] || edges [0][0] == edges [1][1] {
        return edges [0][0]
    } // if ...
    return edges [0][1] // Pela lógica do problema
}

