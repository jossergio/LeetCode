func numRescueBoats(people []int, limit int) int {
    var i, j, resposta int = 0, len (people) - 1, 0
    sort.Ints (people)
    for i <= j {
        resposta += 1
        if (people [i] + people [j] <= limit) {
            i += 1
        }
        j -= 1
    }
    return resposta
}

