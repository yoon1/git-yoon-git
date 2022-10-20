package main

import "errors"

var (
	errEmpty = errors.New("empty!!")
)

type Stack struct {
	nums []int
}

func (s *Stack) IsEmpty() bool {
	return len(s.nums) == 0
}

func (s *Stack) Push(num int) {
	s.nums = append(s.nums, num)
}

func (s *Stack) Pop() (int, error) {
	if s.IsEmpty() {
		return 0, errEmpty
	}
	length := len(s.nums)
	ret := s.nums[length-1]
	s.nums = s.nums[:length-1]

	return ret, nil
}

func (s *Stack) Top() (int, error) {
	if s.IsEmpty() {
		return 0, errEmpty
	}

	length := len(s.nums)
	return s.nums[length-1], nil
}

func solution(order []int) int {
	stack := Stack{}
	res := 0
	count := len(order)
	for i := 1; i <= count; i++ {
		if i == order[res] {
			res++
			continue
		} else {
			if stack.IsEmpty() {
				stack.Push(i)
			} else {
				for !stack.IsEmpty() {
					t, err := stack.Top()
					if err != nil {
						panic("panic!!")
					}
					if t == order[res] {
						stack.Pop()
						res++
						continue
					} else {
						break
					}
				}
				if i == order[res] {
					res++
					continue
				} else {
					stack.Push(i)
				}
			}
		}
	}

	for !stack.IsEmpty() {
		t, err := stack.Pop()
		if err != nil {
			panic("panic!!")
		}
		if t != order[res] {
			return res
		}
		res++
	}

	return res
}
