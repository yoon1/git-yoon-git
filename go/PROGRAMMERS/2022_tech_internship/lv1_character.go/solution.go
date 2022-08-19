package lv1_character_go

import "strings"

func NewCharacter() *Character {
	return &Character{
		rt: &Type{"R", "T", 0},
		cf: &Type{"C", "F", 0},
		jm: &Type{"J", "M", 0},
		an: &Type{"A", "N", 0},
	}
}

type Character struct {
	rt, cf, jm, an *Type
}

// bool(reverse)
func (c *Character) Select(name string) (*Type, bool) {
	switch name {
	case "RT":
		return c.rt, false
	case "TR":
		return c.rt, true
	case "CF":
		return c.cf, false
	case "FC":
		return c.cf, true
	case "JM":
		return c.jm, false
	case "MJ":
		return c.jm, true
	case "AN":
		return c.an, false
	case "NA":
		return c.an, true
	}
	return nil, false
}

func (c *Character) Result() string {
	return strings.Join([]string{c.rt.Closer(), c.cf.Closer(), c.jm.Closer(), c.an.Closer()}, "")
}

type Type struct {
	a     string
	b     string
	point int // 음수면 a, 양수면 b
}

func (t *Type) Closer() string {
	switch {
	case t.point > 0:
		return t.b
	case t.point < 0:
		return t.a
	default:
		return minStr(t.a, t.b)
	}
}

func check(t *Type, choice int) {
	switch {
	case choice <= 3:
		t.point -= 4 - choice
	case choice == 4:
	case choice >= 5:
		t.point += choice - 4
	}
}

func minStr(a, b string) string {
	if a < b {
		return a
	}
	return b
}

func reversePoint(point int) int {
	return (point - 8) * -1
}

func solution(survey []string, choices []int) string {
	character := NewCharacter()
	for i, sv := range survey {
		choice := choices[i]
		tp, reverse := character.Select(sv)
		if reverse {
			choice = reversePoint(choice)
		}
		check(tp, choice)
	}
	return character.Result()
}
