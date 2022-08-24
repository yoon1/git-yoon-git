package lv2_rotate_matrix

import (
	"fmt"
	"log"
)

func PrintMatrix(nums [][]int, rowLen, colLen int) {
	log.Println("==========")
	for i := 0; i < rowLen; i++ {
		for j := 0; j < colLen; j++ {
			fmt.Printf("%5d ", nums[i][j])
		}
		fmt.Println()
	}
	log.Println("==========")
}
