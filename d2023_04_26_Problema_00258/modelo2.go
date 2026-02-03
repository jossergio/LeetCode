func addDigits(num int) int {
    num -= 1
    return num - (num - (num % 9)) + 1
}
