package main

import "math/rand"

// int(time.Now().UnixNano()) % len(this.m)
type RandomizedSet struct {
	nums []int
	ids  map[int]int // num -> index
}

func Constructor() RandomizedSet {
	return RandomizedSet{
		nums: []int{},
		ids:  make(map[int]int),
	}
}

func (this *RandomizedSet) Insert(val int) bool {
	if _, ok := this.ids[val]; ok {
		return false
	}

	this.nums = append(this.nums, val)
	this.ids[val] = len(this.nums) - 1
	return true
}

func (this *RandomizedSet) Remove(val int) bool {
	if id, ok := this.ids[val]; ok {
		last := this.nums[len(this.nums)-1]
		this.nums[id], this.ids[last] = last, id
		this.nums = this.nums[:len(this.nums)-1]
		delete(this.ids, val)
		return true
	}

	return false
}

func (this *RandomizedSet) GetRandom() int {
	return this.nums[rand.Intn(len(this.nums))]
}

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * obj := Constructor();
 * param_1 := obj.Insert(val);
 * param_2 := obj.Remove(val);
 * param_3 := obj.GetRandom();
 */

func main() {
	obj := Constructor()
	obj.Insert(1)
	obj.Remove(2)
	obj.Insert(2)
	obj.GetRandom()
	obj.Remove(1)
	obj.Insert(2)
	obj.GetRandom()
}
