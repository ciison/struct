/**************************************************
* 这里演示的是 goroutine 的非抢占式的设计,
* xiao 成
****************************************************/
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

		}
	}()
}

func main() {

	runtime.GOMAXPROCS(1)
	runtime.Gosched() // 这里释放当前的 cpu 调度,
	fmt.Println("hello world")
}
