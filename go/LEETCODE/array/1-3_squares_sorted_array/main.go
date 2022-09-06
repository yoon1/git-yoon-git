package main

func quickSort(nums *[]int, left, right int) {
	if left >= right {
		return
	}

	pivot := left
	i, j := pivot+1, right

	for i <= j {
		for i <= right && (*nums)[i] <= (*nums)[pivot] {
			i++
		}

		for j > left && (*nums)[j] >= (*nums)[pivot] {
			j--
		}

		if i > j {
			(*nums)[j], (*nums)[pivot] = (*nums)[pivot], (*nums)[j]
		} else {
			(*nums)[j], (*nums)[i] = (*nums)[i], (*nums)[j]
		}
	}

	quickSort(nums, left, j-1)
	quickSort(nums, j+1, right)
}

func square(nums *[]int, length int) {
	for i := 0; i < length; i++ {
		(*nums)[i] *= (*nums)[i]
	}
}

func sortedSquares(nums []int) []int {
	length := len(nums)

	square(&nums, length)

	quickSort(&nums, 0, length-1)

	return nums
}
