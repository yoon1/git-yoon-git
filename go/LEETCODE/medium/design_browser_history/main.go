package main

type BrowserHistory struct {
	current  string
	backs    []string
	forwards []string
}

func Constructor(homepage string) BrowserHistory {
	return BrowserHistory{
		current:  homepage,
		backs:    []string{},
		forwards: []string{},
	}
}

func (this *BrowserHistory) Visit(url string) {
	this.forwards = []string{}
	this.backs = append(this.backs, this.current)
	this.current = url
}

func (this *BrowserHistory) Back(steps int) string {
	return this.move(&this.backs, &this.forwards, steps)
}

func (this *BrowserHistory) Forward(steps int) string {
	return this.move(&this.forwards, &this.backs, steps)
}

func (this *BrowserHistory) move(direction *[]string, oppositeDirection *[]string, steps int) string {
	for i := 0; len(*direction) > 0 && i < steps; i++ {
		*oppositeDirection = append(*oppositeDirection, this.current)
		this.current = (*direction)[len(*direction)-1]
		*direction = (*direction)[:len(*direction)-1]
	}

	return this.current
}
