package main

import (
	"log"
)

type Encrypter struct {
	m          map[byte]string
	dictionary []string
}

func Constructor(keys []byte, values []string, dictionary []string) Encrypter {
	// key랑 value가 주어진다.
	// 원본 문자열을 포함하는 문자열 배열 dictionary.
	// index가 0 인 문자열을 암호화하거나,복호화할 수 있는 데이터구조 구현.

	m := make(map[byte]string, len(keys))
	for i := range keys {
		m[keys[i]] = values[i]
	}

	return Encrypter{
		m:          m,
		dictionary: dictionary,
	}
}

func (this *Encrypter) Encrypt(word1 string) string {
	// 1. For each character c in the string, we find the index i satisfying keys[i] == c in keys.
	// 2. Replace c with values[i] in the string.
	// * 문자열 키가 없으면, 빈 문자열을 반환한다.
	var s string
	for _, c := range word1 {
		if v, ok := this.m[byte(c)]; ok {
			s += v
		} else {
			return ""
		}
	}

	return s
}

// 방법1: brute force
// 방법2: trie
func (this *Encrypter) Decrypt(word2 string) int {
	// 1. For each substring s of length 2 occurring at an even index in the string, we find an i such that values[i] == s. If there are multiple valid i, we choose any one of them. This means a string could have multiple possible strings it can decrypt to.
	// 2. Replace s with keys[i] in the string
	var cnt = 0
	for _, v := range this.dictionary {
		if this.Encrypt(v) == word2 {
			cnt++
		}
	}

	return cnt
}

func main() {
	obj := Constructor([]byte{'a', 'b', 'c', 'd'}, []string{"ei", "zf", "ei", "am"}, []string{"abcd", "acbd", "adbc", "badc", "dacb", "cadb", "cbda", "abad"})
	//param_1 := obj.Encrypt("abcd")
	//log.Println(param_1) // "eizfeiam"

	param_2 := obj.Decrypt("eizfeiam")
	log.Println(param_2) // 2
}

/**
 * Your Encrypter object will be instantiated and called as such:
 * obj := Constructor(keys, values, dictionary);
 * param_1 := obj.Encrypt(word1);
 * param_2 := obj.Decrypt(word2);
 */
