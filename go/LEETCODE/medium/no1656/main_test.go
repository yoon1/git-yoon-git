package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_solution(t *testing.T) {
	obj := Constructor(5)
	assert.Equal(t, obj.Insert(3, "ccccc"), []string{})
	assert.Equal(t, obj.Insert(1, "aaaaa"), []string{"aaaaa"})
	assert.Equal(t, obj.Insert(2, "bbbbb"), []string{"bbbbb", "ccccc"})
	assert.Equal(t, obj.Insert(5, "eeeee"), []string{})
	assert.Equal(t, obj.Insert(4, "ddddd"), []string{"ddddd", "eeeee"})
}
