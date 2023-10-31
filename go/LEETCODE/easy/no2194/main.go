package main

func cellsInRange(s string) []string {
	var res = []string{}
	sc, si, ec, ei := s[0], s[1], s[3], s[4]
	for c := sc; c <= ec; c++ {
		for i := si; i <= ei; i++ {
			res = append(res, string(c)+string(i))
		}
	}

	return res
}
