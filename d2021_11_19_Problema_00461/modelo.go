func hammingDistance(x int, y int) int {
	var diferenca int = x ^ y;
	var distancia int = -1;
	for diferenca != 0 {
		if (diferenca & 1) == 1{
			if distancia == -1 {
				distancia = 1
			}
		} else { // if diferenca & 1
			if distancia > 0 {
				distancia++;
			} // if distancia > 0
		} // else if diferenca & 1
		diferenca >>= 1;
	} // for diferenca != 0
	return distancia
}

