package main

import (
	"fmt"
	"log"

	"github.com/gofiber/fiber/v2"
)

func main() {
	app := fiber.New()
	count := 0

	app.Use(func(c *fiber.Ctx) error {
		count++
		return c.Next()
	})

	app.Get("/", func(c *fiber.Ctx) error {
		result := fmt.Sprint("Requests made: ", count, "\n")

		return c.SendString(result)
	})

	log.Fatal(app.Listen(":8080"))
}
