package main

import "log"

func selectionSort(arr []int) {
	for i := 0; i < len(arr); i++ {
		var min = i
		for j := i + 1; j < len(arr); j++ {
			if arr[min] > arr[j] {
				min = j
			}
		}
		arr[i], arr[min] = arr[min], arr[i]
	}
}

func main() {
	arr := []int{4, 2, 3, 4, 1}
	selectionSort(arr)
	log.Println(arr)
}
