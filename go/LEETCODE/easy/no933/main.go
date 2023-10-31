package main

type RecentCounter struct {
	arr []int
}

func Constructor() RecentCounter {
	return RecentCounter{
		[]int{},
	}
}

func (this *RecentCounter) Ping(t int) int {
	var min = t - 3000
	var res = 1

	for i := len(this.arr) - 1; i >= 0; i-- {
		if this.arr[i] < min {
			break
		}
		res++
	}

	this.arr = append(this.arr, t)
	return res
}
