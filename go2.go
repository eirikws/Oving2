
package main

import (
    . "fmt" // Using '.' to avoid prefixing functions with their package names
    . "runtime" // This is probably not a good idea for large projects...
    . "time"
)

var i = 0

func adder(mychan chan int) {
    for x := 0; x < 1000000; x++ {
        mychan<-1
        i++
        <-mychan
    }
}

func decr(mychan chan int) {
    for x := 0; x < 1000000; x++ {
        mychan<-1
        i--
        <-mychan
    }
}

func main() {
    myc:=make(chan int)
    GOMAXPROCS(NumCPU())
    go adder(myc)
    go decr(myc)
    Sleep(100*Millisecond)
    Println("Done:", i);
}
