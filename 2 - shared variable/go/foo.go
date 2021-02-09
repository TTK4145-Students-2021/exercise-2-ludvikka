// Use `go run foo.go` to run your program

package main

import (
	"fmt"
	"runtime"
)

func number_server(add <-chan int, sub <-chan int, read chan<- int) {
	var number = 0

	// This for-select pattern is one you will become familiar with...
	for {
		select {
		case <- add:
			number = number + 1
			print("add")
			//read <- number
			
		case <- sub:
			number = number + 1	
			print("sub")
			//read <- number
			
        }
	}
}

func incrementer(add chan<- int, finishedAdd chan<- bool) {
	for j := 0; j < 10+1; j++ {
		add <- 1
	}
	//TODO: signal that the goroutine is finished
	finishedAdd <- true

}

func decrementer(sub chan<- int, finishedSub chan<- bool) {
	for j := 0; j < 10; j++ {
		sub <- 1
	}
	//TODO: signal that the goroutine is finished
	finishedSub <- true
}

func main() {
	runtime.GOMAXPROCS(runtime.NumCPU())

	// TODO: Construct the remaining channels
	read := make(chan int)
	add := make(chan int)
	sub := make(chan int)
	finishedSub := make(chan bool)
	finishedAdd := make(chan bool)
	

	// TODO: Spawn the required goroutines
	go number_server(add,sub,read)
	go incrementer(add, finishedAdd)
	go decrementer(sub, finishedSub)

	
	<- finishedSub
	<- finishedAdd
	
	

	
	fmt.Println("Ferdig")

	//fmt.Println("The magic number is:", <-read)
}
