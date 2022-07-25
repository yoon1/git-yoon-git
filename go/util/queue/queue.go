package queue

import (
	"errors"
)

const (
	ErrPop = "error pop"
)

type Queue []interface{}

func (q *Queue) Push(item interface{}) {
	*q = append(*q, item)
}

func (q *Queue) Pop() (interface{}, error) {
	if len(*q) <= 0 {
		return nil, errors.New(ErrPop)
	}

	res := (*q)[0]
	*q = (*q)[1:]
	return res, nil
}

func (q *Queue) Empty() bool {
	if len(*q) == 0 {
		return true
	}

	return false
}
