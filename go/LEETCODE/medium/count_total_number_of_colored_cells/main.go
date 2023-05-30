package main

func coloredCells(n int) int64 {
	return 4*int64((n-1)*n/2) + 1
}
