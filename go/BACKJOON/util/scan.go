package util

import (
	"bufio"
	"os"
	"strconv"
	"strings"
)

var (
	r = bufio.NewReader(os.Stdin)
	w = bufio.NewWriter(os.Stdout)
)

func ScanInt() int {
	userVal, _ := r.ReadString('\n')
	input := strings.TrimSpace(userVal)
	n, _ := strconv.Atoi(input)
	return n
}

func ScanString() string {
	str, _ := r.ReadString('\n') // 여기서 text는 마지막에 줄바꿈 문자를 포함하므로
	str = strings.TrimSpace(str) // 줄바꿈 문자를 제거해야 함
	return str
}

func ScanWords() {
	str := ScanString()
	ss := strings.Split(str, " ")
	one, two, three = ss[0], ss[1], ss[2]
}
