func arrangeCoins(n int) int {
    var i int = 1
    for n >= i {
        n -= i
        i++
    } // for n > i
    return i - 1
}

