package main

import "log"

type LRUCache struct {
	table            map[int]int
	recentlyUsedKeys []int // 가장 맨 앞(인덱스 0)에 있는 키가 가장 오래된 키
	keyNum           int
	capacity         int
}

func Constructor(capacity int) LRUCache {
	return LRUCache{
		table:            make(map[int]int, capacity),
		recentlyUsedKeys: []int{},
		keyNum:           0,
		capacity:         capacity,
	}
}

func (this *LRUCache) Get(key int) int {
	if v, ok := this.table[key]; !ok {
		return -1
	} else {
		this.updateRecentlyUsedKeys(key)
		return v
	}
}

func (this *LRUCache) Put(key int, value int) {
	if _, ok := this.table[key]; !ok {
		if this.capacity == this.keyNum {
			this.deleteLRUKey()
		}

		this.keyNum++
	}

	this.table[key] = value
	this.updateRecentlyUsedKeys(key)
}

func (this *LRUCache) deleteLRUKey() {
	if this.capacity == 0 {
		return
	}

	var target = this.recentlyUsedKeys[0]
	delete(this.table, target)
	this.recentlyUsedKeys = this.recentlyUsedKeys[1:]
	this.keyNum--
}

func (this *LRUCache) updateRecentlyUsedKeys(key int) {
	for idx, usedKey := range this.recentlyUsedKeys {
		if key == usedKey {
			this.recentlyUsedKeys = append(this.recentlyUsedKeys[:idx], this.recentlyUsedKeys[idx+1:]...)
		}
	}
	this.recentlyUsedKeys = append(this.recentlyUsedKeys, key)
}

/**
 * Your LRUCache object will be instantiated and called as such:
 * obj := Constructor(capacity);
 * param_1 := obj.Get(key);
 * obj.Put(key,value);
 */

func main() {
	lRUCache := Constructor(2)
	//lRUCache.Put(1, 1)           // cache is {1=1}
	//lRUCache.Put(2, 2)           // cache is {1=1, 2=2}
	//fmt.Println(lRUCache.Get(1)) // return 1
	//lRUCache.Put(3, 3)           // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
	//fmt.Println(lRUCache.Get(2)) // returns -1 (not found)
	//lRUCache.Put(4, 4)           // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
	//fmt.Println(lRUCache.Get(1)) // return -1 (not found)
	//fmt.Println(lRUCache.Get(3)) // return 3
	//fmt.Println(lRUCache.Get(4)) // return 4

	log.Println(lRUCache.Get(2))
	lRUCache.Put(2, 6)
	log.Println(lRUCache.Get(1))
	lRUCache.Put(1, 5)
	lRUCache.Put(1, 2)
	log.Println(lRUCache.Get(1))
	log.Println(lRUCache.Get(2))
}
