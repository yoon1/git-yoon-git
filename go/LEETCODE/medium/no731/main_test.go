package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	obj := Constructor()
	assert.Equal(t, obj.Book(10, 20), true)
	assert.Equal(t, obj.Book(50, 60), true)
	assert.Equal(t, obj.Book(10, 40), true)
	assert.Equal(t, obj.Book(5, 15), false)
	assert.Equal(t, obj.Book(5, 10), true)
	assert.Equal(t, obj.Book(25, 55), true)
}

func Test_solution_2(t *testing.T) {
	obj := Constructor()
	assert.Equal(t, obj.Book(26, 35), true)
	assert.Equal(t, obj.Book(26, 32), true)
	assert.Equal(t, obj.Book(25, 32), false)
	assert.Equal(t, obj.Book(18, 26), true)
	assert.Equal(t, obj.Book(40, 45), true)
	assert.Equal(t, obj.Book(19, 26), true)
	assert.Equal(t, obj.Book(48, 50), true)
	assert.Equal(t, obj.Book(1, 6), true)
	assert.Equal(t, obj.Book(46, 50), true)
	assert.Equal(t, obj.Book(11, 18), true)
}

func Test_solution_3(t *testing.T) {
	obj := Constructor()
	assert.Equal(t, obj.Book(24, 40), true)
	assert.Equal(t, obj.Book(43, 50), true)
	assert.Equal(t, obj.Book(27, 43), true)
	assert.Equal(t, obj.Book(5, 21), true)
	assert.Equal(t, obj.Book(30, 40), false)
	assert.Equal(t, obj.Book(14, 29), false)
	assert.Equal(t, obj.Book(3, 19), true)
	assert.Equal(t, obj.Book(3, 14), false)
	assert.Equal(t, obj.Book(25, 39), false)
	assert.Equal(t, obj.Book(6, 19), false)
}

func Test_solution_4(t *testing.T) {
	obj := Constructor()
	assert.Equal(t, obj.Book(28, 46), true)
	assert.Equal(t, obj.Book(9, 21), true)
	assert.Equal(t, obj.Book(21, 39), true)
	assert.Equal(t, obj.Book(37, 48), false)
	assert.Equal(t, obj.Book(38, 50), false)
	assert.Equal(t, obj.Book(22, 39), false)
	assert.Equal(t, obj.Book(45, 50), true)
	assert.Equal(t, obj.Book(1, 12), true)
	assert.Equal(t, obj.Book(40, 50), false)
	assert.Equal(t, obj.Book(31, 44), false)
}
