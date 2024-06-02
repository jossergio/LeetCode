func reverseString(s []byte)  {
    var i int = 0
    var j int = len (s) - 1 // 0-begin
    for i < j {
        s [i], s [j] = s [j], s [i]
        i += 1
        j -= 1
    }
}

