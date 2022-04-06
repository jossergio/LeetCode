func reverseString(s []byte)  {
    
    var n int = len (s)
    
    for i := 0; i < (n / 2); i++ {
        s [i], s [n - i - 1] = s [n - i - 1], s [i]
    }
    
}

