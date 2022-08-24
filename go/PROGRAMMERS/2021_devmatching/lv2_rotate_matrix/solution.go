package lv2_rotate_matrix

import (
	"math"
)

type Point struct {
	y, x, v int
}

func rotate(arr *[][]int, points *[]Point) {
	for _, point := range *points {
		(*arr)[point.y][point.x] = point.v
	}
}

// rotate returns min value
func rotateAndFindMin(row, col int, arr *[][]int, query []int) int {
	min := math.MaxInt
	y1, x1, y2, x2 := query[0]-1, query[1]-1, query[2]-1, query[3]-1
	dy := []int{0, 1, 0, -1}
	dx := []int{1, 0, -1, 0}

	points := []Point{}
	cy, cx := y1, x1
	for i := 0; i < 4; i++ {
		for {
			v := (*arr)[cy][cx]
			ny := cy + dy[i]
			nx := cx + dx[i]

			if !(ny >= 0 && nx >= 0 && ny < row && nx < col) {
				break
			}
			if (i == 0 && nx > x2) || // right
				(i == 1 && ny > y2) || // down
				(i == 2 && nx < x1) || // left
				(i == 3 && ny < y1) { // up
				break
			}

			if min > v {
				min = v
			}
			points = append(points, Point{
				y: ny,
				x: nx,
				v: v,
			})
			cy, cx = ny, nx
		}
	}

	rotate(arr, &points)
	return min
}

func makeArray(row, col int) *[][]int {
	num := 1
	arr := make([][]int, row)
	for i := 0; i < row; i++ {
		line := make([]int, col)
		for j := 0; j < col; j++ {
			line[j] = num
			num++
		}
		arr[i] = line
	}
	return &arr
}

func solution(rows int, columns int, queries [][]int) (res []int) {
	arr := makeArray(rows, columns)

	for _, q := range queries {
		min := rotateAndFindMin(rows, columns, arr, q)
		res = append(res, min)
	}

	return
}
