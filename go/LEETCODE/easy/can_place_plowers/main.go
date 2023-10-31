package main

func canPlaceFlowers(flowerbed []int, n int) bool {
	length := len(flowerbed)

	for i := 0; i < length && n > 0; i++ {
		if (flowerbed[i] == 0) &&
			(i == 0 || flowerbed[i-1] == 0) &&
			(i == length-1 || flowerbed[i+1] == 0) {
			flowerbed[i] = 1
			n--
		}
	}

	return n == 0
}
