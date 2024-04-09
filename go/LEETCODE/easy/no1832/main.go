package main

// stack
func checkIfPangram(sentence string) bool {
	m := map[string]struct{}{
		"a": {},
		"b": {},
		"c": {},
		"d": {},
		"e": {},
		"f": {},
		"g": {},
		"h": {},
		"i": {},
		"j": {},
		"k": {},
		"l": {},
		"m": {},
		"n": {},
		"o": {},
		"p": {},
		"q": {},
		"r": {},
		"s": {},
		"t": {},
		"u": {},
		"v": {},
		"w": {},
		"y": {},
		"x": {},
		"z": {},
	}

	for _, c := range sentence {
		delete(m, string(c))
		if len(m) == 0 {
			return true
		}
	}

	return false
}
