package main

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_RecentCounter_Ping(t *testing.T) {
	obj := Constructor()
	assert.Equal(t, obj.Ping(1), 1)
	assert.Equal(t, obj.Ping(100), 2)
	assert.Equal(t, obj.Ping(3001), 3)
	assert.Equal(t, obj.Ping(3002), 3)
}
