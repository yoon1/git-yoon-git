package main

func exist(board [][]byte, word string) bool {
	var (
		my, mx = len(board), len(board[0])
		dy     = []int{-1, 1, 0, 0}
		dx     = []int{0, 0, -1, 1}
		wl     = len(word)
	)

	var search func(y, x int, idx int, cur byte) bool
	search = func(y, x int, idx int, cur byte) bool {
		if word[idx-1] != cur {
			return false
		}

		if idx == wl {
			return true
		}

		for i := 0; i < 4; i++ {
			var (
				t      byte
				ny, nx = y + dy[i], x + dx[i]
			)

			if !(ny >= 0 && ny < my && nx >= 0 && nx < mx) {
				continue
			}

			t, board[ny][nx] = board[ny][nx], '*'
			if search(ny, nx, idx+1, t) {
				return true
			}
			board[ny][nx] = t
		}

		return false
	}

	for y := 0; y < my; y++ {
		for x := 0; x < mx; x++ {
			var t byte
			t, board[y][x] = board[y][x], '*'
			if search(y, x, 1, t) {
				return true
			}
			board[y][x] = t
		}
	}

	return false
}
