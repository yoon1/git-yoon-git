package main

func uniquePathsIII(grid [][]int) int {
	var (
		res            = 0
		m, n           = len(grid), len(grid[0])
		sy, sx, ey, ex int
		dy             = [4]int{1, -1, 0, 0}
		dx             = [4]int{0, 0, 1, -1}
		ground         = 1
		dfs            func(y, x, depth int)
	)

	dfs = func(y, x, depth int) {
		if y == ey && x == ex {
			if depth == ground {
				res++
			}

			return
		}

		for i := 0; i < 4; i++ {
			ny, nx := y+dy[i], x+dx[i]
			if ny >= 0 && ny < m && nx >= 0 && nx < n &&
				grid[ny][nx] >= 0 {
				grid[ny][nx] = -2
				dfs(ny, nx, depth+1)
				grid[ny][nx] = 0
			}
		}
	}

	for i := 0; i < m; i++ {
		for j := 0; j < n; j++ {
			switch grid[i][j] {
			case 0:
				ground++
			case 1:
				sy, sx = i, j
			case 2:
				ey, ex = i, j
			}
		}
	}

	grid[sy][sx] = -2
	dfs(sy, sx, 0)

	return res
}
