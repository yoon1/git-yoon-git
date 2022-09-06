package practices

import (
	"log"
	"testing"
)

func Test_solution(t *testing.T) {
	log.Println(solution([][]int{{1, 4}, {3, 2}, {4, 1}}, [][]int{{3, 3}, {3, 3}}))
}
