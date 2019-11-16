/**************************************************
* 这里演示的是 goroutine 的抢占式的设计,
* xiao 成
****************************************************/
// 更正一下, goroutine 的设计是抢占式的, 如果 一个协程的运行时间超过 10 ms, 切换当前的协程
// 但是下面的这一段代码, 在编译的时候可能编译器做了优化, 怎么说呢?
// 编译器可能将
//go func() {
//   for {
//  something ...
//}
//}
// 这一段代码优化为内联的代码, 也就是说, 这 这并不是一个 G  的对象, 而是一个代码的片段
//  也就是说 代码中的 go 不起作用了
// 相当于优化成了 
//  for {
//   something ....
// }
// 

// 怎么解决呢?  
// go build -gcflags=-l 加上编译的目标文件  // 在 go build 命令下加上 -gcflags=-l   这个是小写字母 l  
package main

import (
	"fmt"
	"runtime"
)

func init() {
	// 这里演示的是当前的协程一直占据 cpu 资源,
	// 如果是 GOMAXPROCS == 1 时, 其他的协程将会陷入饥饿的状态
	go func() {
		for {
			a := 1
			b := a
			a = b
		}
	}()
}

func main() {

	runtime.GOMAXPROCS(1)
	runtime.Gosched() // 这里释放当前的 cpu 调度,
	fmt.Println("hello world")
}
