package main

import (
	"fmt"
	"testing"
)

func Test_BrowserHistory(t *testing.T) {
	obj := Constructor("leetcode.com")
	obj.Visit("google.com")
	obj.Visit("facebook.com")
	obj.Visit("youtube.com")
	fmt.Println(obj.Back(1))    // , "facebook.com")
	fmt.Println(obj.Back(1))    // , "google.com")
	fmt.Println(obj.Forward(1)) // , "facebook.com")
	obj.Visit("linkedin.com")
	fmt.Println(obj.Forward(2)) // , "linkedin.com")
	fmt.Println(obj.Back(2))    // , "google.com")
	fmt.Println(obj.Back(7))    // , "leetcode.com")
}
