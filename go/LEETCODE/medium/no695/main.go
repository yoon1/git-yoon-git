package main

type point struct {
	y, x int
}

func maxAreaOfIsland(grid [][]int) int {
	var (
		dy = []int{-1, 1, 0, 0}
		dx = []int{0, 0, -1, 1}
		my = len(grid)
		mx = len(grid[0])
	)

	var (
		visited [][]bool
		res     int
		bfs     func(sy, sx int) int
	)

	bfs = func(sy, sx int) int {
		var (
			q    []point
			area = 0
		)

		q = append(q, point{sy, sx})

		for len(q) > 0 {
			cur := q[0]
			q = q[1:]
			y, x := cur.y, cur.x
			if !(y >= 0 && x >= 0 && y < my && x < mx) {
				continue
			}

			area++

			for i := 0; i < 4; i++ {
				ny, nx := y+dy[i], x+dx[i]
				if !(ny >= 0 && nx >= 0 && ny < my && nx < mx) ||
					visited[ny][nx] ||
					grid[ny][nx] == 0 {
					continue
				}

				visited[ny][nx] = true
				q = append(q, point{ny, nx})
			}
		}

		return area
	}

	visited = make([][]bool, my)
	for i := range visited {
		visited[i] = make([]bool, mx)
	}

	for y := 0; y < my; y++ {
		for x := 0; x < mx; x++ {
			if grid[y][x] == 0 || visited[y][x] {
				continue
			}

			visited[y][x] = true
			res = max(res, bfs(y, x))
		}
	}

	return res
}

func max(a, b int) int {
	if a > b {
		return a
	}
	return b
}
