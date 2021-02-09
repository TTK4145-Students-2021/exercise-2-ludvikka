
package main

import "fmt"
import "time"


func producer(input chan<- int){

    for i := 0; i < 10; i++ {
        time.Sleep(100 * time.Millisecond)
        fmt.Printf("[producer]: pushing %d\n", i)
        // TODO: push real value to buffer
    }

}

func consumer(output <-chan int){

    time.Sleep(1 * time.Second)
    for {
        i := 0 //TODO: get real value from buffer
        fmt.Printf("[consumer]: %d\n", i)
        time.Sleep(50 * time.Millisecond)
    }
    
}


func main(){
    
    // TODO: make a bounded buffer

    input :=make(chan int)
    output :=make(chan int)
    
    go consumer(output)
    go producer(input)

    select {}
}