package main

// 예약이 3번 발생하지 않으면 새로운 이벤트 추가 가능.
// triple booking : 세 이벤트가 비어 있지 않은 교차점이 있을 때 발생. (세 이벤트에 모두 공통?)
// map을 써야되나..?
//type MyCalendarTwo struct {
//	list     []int
//	countMap map[int]int
//}
//
//func Constructor() MyCalendarTwo {
//	return MyCalendarTwo{list: []int{}, countMap: make(map[int]int)}
//}
//
//func (this *MyCalendarTwo) Book(start int, end int) bool {
//	var (
//		copyList = make([]int, len(this.list))
//	)
//
//	copy(copyList, this.list)
//
//	s, sok := slices.BinarySearch(copyList, start)
//	if !sok {
//		copyList = slices.Insert(copyList, s, start)
//	}
//
//	e, eok := slices.BinarySearch(copyList, end-1)
//	if !eok {
//		copyList = slices.Insert(copyList, e, end-1)
//	}
//
//	var res = true
//	var i = s
//	for ; i <= e; i++ {
//		this.countMap[copyList[i]]++
//		if this.countMap[copyList[i]] >= 3 {
//			res = false
//			break
//		}
//	}
//
//	if res {
//		this.list = copyList
//	} else {
//		for ; i >= s; i-- {
//			this.countMap[copyList[i]]--
//			if this.countMap[copyList[i]] == 0 {
//				delete(this.countMap, copyList[i])
//			}
//		}
//	}
//
//	log.Println(this.list, this.countMap)
//	return res
//}
