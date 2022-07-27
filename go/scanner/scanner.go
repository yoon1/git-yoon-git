package scanner

import (
	"bufio"
	"os"
	"strconv"
)

var (
	w = bufio.NewWriter(os.Stdout)
	s = bufio.NewScanner(os.Stdin)
)

func ScanInt() int {
	s.Scan()
	n, _ := strconv.Atoi(s.Text())
	return n
}
