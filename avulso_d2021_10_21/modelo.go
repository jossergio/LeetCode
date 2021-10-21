func isPalindrome(x int) bool {
	var s = fmt.Sprint (x)
	var i, t int = 0, len (s) - 1
	for i < t {
		if s [i] != s [t] {
			return false
		} // if s i != s t
		i++
		t--
	} // for i < t
	return true
}

