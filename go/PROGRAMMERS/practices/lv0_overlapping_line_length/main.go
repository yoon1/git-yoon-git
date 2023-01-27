package main

const maxLength = 200

type Line []bool

func (l Line) Over(overedLine *Line, op Line) {
	for i := 0; i < maxLength; i++ {
		if l[i] && op[i] {
			(*overedLine)[i] = true
		}
	}
}

func (l Line) Length() (length int) {
	for i := 0; i < maxLength; i++ {
		if l[i] {
			length++
		}
	}
	return
}

func solution(lines [][]int) int {
	lns := []Line{}
	for _, line := range lines {
		ln := make(Line, maxLength)
		for i := line[0] + maxLength/2; i < line[1]+maxLength/2; i++ {
			ln[i] = true
		}
		lns = append(lns, ln)
	}

	overedLine := make(Line, maxLength)
	lns[0].Over(&overedLine, lns[1])
	lns[0].Over(&overedLine, lns[2])
	lns[1].Over(&overedLine, lns[2])

	return overedLine.Length()
}
