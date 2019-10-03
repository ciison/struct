// Rabin-Karp
// 将每一个匹配的字符串映射为一个 hash值，
// 例如： 将子串看作一个多进制数字， 比较它的值与母串中长度相同子串的 hash 值
// 如果相同， 再细致地比较确认字符串中的字符是否相同，
package main

import (
	"crypto/md5"
	"encoding/hex"
	"fmt"
)

func rabinKarp(str, pattern string) int {
	// 如果 匹配串的长度小于模式串的长度， 直接退出
	if len(str) < len(pattern) {
		return -1
	}
	// 这里计算模式串的 hash
	hash := md5.New()
	hash.Write([]byte(pattern))
	bytes := hash.Sum(nil)

	hPattern := hex.EncodeToString(bytes)
	for i := 0; i <= len(str)-len(pattern); i++ {
		hash.Reset()
		hash.Write([]byte(str[i:i+len(pattern)]))
		data := hash.Sum(nil)
		hs := hex.EncodeToString(data)

		if hs == hPattern {
			// 如果这里的 hash 相同了，
			// 继续匹配内部是否相同， 如果相同的话直接退出， 否则继续进行下一轮的迭代
			return i
		}

	}

	// 如果函数进入到这里， 表示没有可以匹配的字符串
	return -1

}
func main() {
	fmt.Println(rabinKarp("hello", "world"))
	fmt.Println(rabinKarp("hello world", "world"))
	fmt.Println(rabinKarp("123 world world", "world"))
}
