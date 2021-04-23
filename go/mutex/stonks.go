package main

import (
	"fmt"
	"log"
	"math/rand"
	"sync"
	"time"
)

type Account struct {
	username string
	balance  int
}

var (
	mutex        sync.Mutex
	account      *Account = &Account{username: "xiuxiu62", balance: 1000}
	transactions []int
)

func must(err error) {
	if err != nil {
		log.Fatalf("Error: %v\n", err)
	}
}

func randInt(i int) int {
	rand.Seed(time.Now().UnixNano())
	return rand.Intn(i-1) + 1
}

func makeLatent(fn func(int, *sync.WaitGroup) error, amount int, wg *sync.WaitGroup) error {
	dur := time.Millisecond * time.Duration(randInt(250))
	time.Sleep(dur)
	return fn(amount, wg)
}

func Propogate(i int) {
	for {
		if i <= 0 {
			break
		}
		transactions = append(transactions, randInt(1000))
		i--
	}
}

func (a *Account) Deposit(amount int, wg *sync.WaitGroup) error {
	mutex.Lock()
	defer mutex.Unlock()
	defer wg.Done()

	fmt.Printf("Depositing %d into %s's account of $%d\n", amount, a.username, a.balance)
	a.balance += amount
	fmt.Printf("Success, %s now has $%d\n", a.username, a.balance)
	return nil
}

func (a *Account) Withdraw(amount int, wg *sync.WaitGroup) error {
	mutex.Lock()
	defer mutex.Unlock()
	defer wg.Done()

	fmt.Printf("Withdrawing %d from %s's account of $%d\n", amount, a.username, a.balance)
	a.balance -= amount
	fmt.Printf("Success, %s now has $%d\n", a.username, a.balance)
	return nil
}

func main() {
	len := 100
	Propogate(len)
	wg := new(sync.WaitGroup)
	wg.Add(len)

	for i := range transactions {
		amount := transactions[i]

		switch i % 2 {
		case 0:
			go must(makeLatent(account.Withdraw, amount, wg))
		case 1:
			go must(makeLatent(account.Deposit, amount, wg))
		}
	}

	wg.Wait()
	fmt.Printf("\n%s has $%d\n", account.username, account.balance)

	if account.balance > 0 {
		fmt.Printf(":)\n")
		return
	}
	fmt.Printf(":(\n")
}
