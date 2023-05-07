package main

func sortColors(nums []int) {
	color := [3]int{}
	for _, n := range nums {
		color[n]++
	}

	numsIdx := 0
	for i := 0; i < 3; i++ {
		colorNum := color[i]
		for colorNum > 0 {
			nums[numsIdx] = i
			colorNum--
			numsIdx++
		}
	}
}
