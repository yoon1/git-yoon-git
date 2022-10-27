package main

import (
	"github.com/stretchr/testify/assert"
	"log"
	"testing"
)

//
//func Test_ConvertString(t *testing.T) {
//	tcs := []struct {
//		Width  int
//		N      int
//		Answer string
//	}{
//		{3, 1, "001"},
//	}
//
//	for _, tc := range tcs {
//		t.Run("PASS", func(t *testing.T) {
//			res := ConvertString(tc.Width, tc.N)
//			assert.Equal(t, tc.Answer, res)
//		})
//	}
//}
//func Test_NextPermutation(t *testing.T) {
//	tcs := []struct {
//		S   []string
//		Ret bool
//	}{
//		{[]string{"0", "1", "2"}, true},
//	}
//
//	for _, tc := range tcs {
//		t.Run("PASS", func(t *testing.T) {
//			log.Println(tc.S)
//			for NextPermutation(tc.S) {
//			}
//		})
//	}
//}

func Test_Permutation(t *testing.T) {
	tcs := []struct {
		Data  []string
		Depth int
		N     int
		R     int
		Res   *[][]string
	}{
		//{[]string{"0", "1", "2", "3", "4", "5", "6", "7", "8", "9"}, 0, 10, 3, &[][]string{}},
		{[]string{"a", "b", "c", "d"}, 0, 4, 3, &[][]string{}},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			//Permutation(tc.Data, tc.Depth, tc.N, tc.R, tc.Res)
			Permutation(tc.Data, tc.Depth, tc.N, tc.R)
			log.Printf("%+v", tc.Res)
		})
	}
}

func Test_Check(t *testing.T) {
	tcs := []struct {
		Signs  []string
		Width  int
		Num    []string
		Answer bool
	}{
		{[]string{"<", ">"}, 2, []string{"8", "9", "7"}, true},
		//{[]string{"<", ">"}, 2, []string{"8", "9", "8"}, false},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			res := Check(tc.Signs, tc.Width, tc.Num)
			assert.Equal(t, tc.Answer, res)
		})
	}
}

func Test_Solve2529(t *testing.T) {
	tcs := []struct {
		Num   int
		Signs string
		Max   string
		Min   string
	}{
		{2, "< >", "897", "021"},
		{9, "> < < < > > > < <", "9567843012", "1023765489"},
	}

	for _, tc := range tcs {
		t.Run("PASS", func(t *testing.T) {
			vmax, vmin := Solve(tc.Num, tc.Signs)
			assert.Equal(t, tc.Max, vmax)
			assert.Equal(t, tc.Min, vmin)
		})
	}
}

func Test_Min(t *testing.T) {
	t.Run("PASS", func(t *testing.T) {
		res := Min([]string{"021"}, []string{"897"})
		log.Println("VALUE!!:", res)

		resMax := Max([]string{"021"}, []string{"897"})
		log.Println("VALUE!!:", resMax)
	})
}
