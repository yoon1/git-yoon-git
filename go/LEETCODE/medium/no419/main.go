package main

// y : right
// x : down
func countBattleships(board [][]byte) int {
	var (
		count      int
		ly         = len(board)
		lx         = len(board[0]) // 1 <= m, n <= 200
		recognized = make([][]bool, ly)
	)

	var initRecognized = func() {
		for y := 0; y < ly; y++ {
			recognized[y] = make([]bool, lx)
		}
	}

	var checkUnrecognized = func(y, x int) bool {
		return board[y][x] == 'X' && recognized[y][x] == false
	}

	var recognizeBattleshipPiece = func(y, x int) {
		recognized[y][x] = true
	}

	var getAndRecognizeBattleshipFromDirection = func(y, x int, isVertical bool) int {
		var (
			size = 0
			py   = &y
			px   = &x
			p    = py
			lp   = ly
		)

		if isVertical == false {
			p = px
			lp = lx
		}

		for *p < lp {
			if checkUnrecognized(*py, *px) == false {
				break
			}

			recognizeBattleshipPiece(*py, *px)
			*p++
			size++
		}

		return size
	}

	var recognizeBattleshipSize = func(y, x int) int {
		size := getAndRecognizeBattleshipFromDirection(y, x, true)

		if size == 1 {
			recognized[y][x] = false
			size = getAndRecognizeBattleshipFromDirection(y, x, false)
		}

		return size
	}

	//

	initRecognized()

	for y := 0; y < ly; y++ {
		for x := 0; x < lx; x++ {
			if checkUnrecognized(y, x) {
				_ = recognizeBattleshipSize(y, x)
				count++
			}
		}
	}

	return count
}
