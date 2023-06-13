package maximum_69_number

import (
	"github.com/stretchr/testify/assert"
	"testing"
)

func Test_sortPeople(t *testing.T) {
	tcs := []struct {
		num    int
		output int
	}{
		{9669, 9969},
		//{9996, 9999},
	}

	for _, tc := range tcs {
		t.Run("성공", func(t *testing.T) {
			result := maximum69Number(tc.num)
			assert.Equal(t, result, tc.output)
		})
	}
}
