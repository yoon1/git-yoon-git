package main

import (
	"errors"
)

type Stack struct {
	items  []Item
	length int
}

func (s *Stack) IsEmpty() bool {
	return s.length == 0
}

func (s *Stack) LastIdx() int {
	return s.length - 1
}

func (s *Stack) Top() (Item, error) {
	if s.length == 0 {
		return Item{}, errors.New("No Item")
	}

	return s.items[s.LastIdx()], nil
}

func (s *Stack) Push(item Item) {
	s.items = append(s.items, item)
	s.length++
}

func (s *Stack) Pop() error {
	if s.length == 0 {
		return errors.New("No Item")
	}
	s.items = s.items[0:s.LastIdx()]
	s.length--
	return nil
}

type Item struct {
	id, val int
}

func solution(numbers []int) []int {
	length := len(numbers)
	t := make([]int, length)

	var stk Stack
	pre := -1
	for i, cur := range numbers {
		if pre < cur {
			for !stk.IsEmpty() {
				item, err := stk.Top()
				if err != nil {
					panic(err)
				}
				if item.val < cur {
					t[item.id] = cur
					if err := stk.Pop(); err != nil {
						panic(err)
					}
				} else {
					break
				}
			}
		}

		item := Item{
			id:  i,
			val: cur,
		}
		stk.Push(item)
	}

	for !stk.IsEmpty() {
		item, err := stk.Top()
		if err != nil {
			panic(err)
		}
		if err := stk.Pop(); err != nil {
			panic(err)
		}

		t[item.id] = -1
	}

	return t
}
