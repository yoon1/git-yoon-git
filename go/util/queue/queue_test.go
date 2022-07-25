package queue

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_Push(t *testing.T) {
	queue := Queue{}
	queue.Push(1)
	assert.Equal(t, len(queue), 1)
}

func Test_Pop(t *testing.T) {
	queue := Queue{}
	queue.Push(1)
	res, err := queue.Pop()
	assert.Equal(t, err, nil)
	assert.Equal(t, res, 1)
}

func Test_Empty(t *testing.T) {
	queue := Queue{}
	queue.Push(1)
	isEmpty := queue.Empty()
	assert.Equal(t, isEmpty, false)
}
