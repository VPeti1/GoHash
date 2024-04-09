package main

import (
	"crypto/sha256"
	"fmt"
	"io"
	"os"
)

func main() {
	// Ask for file path
	fmt.Print("Enter the file path: ")
	var filePath string
	fmt.Scanln(&filePath)

	// Open the file
	file, err := os.Open(filePath)
	if err != nil {
		fmt.Println("Error opening file:", err)
		return
	}
	defer file.Close()

	// Create SHA256 hash
	hash := sha256.New()

	// Copy the file content into the hash object
	if _, err := io.Copy(hash, file); err != nil {
		fmt.Println("Error reading file:", err)
		return
	}

	// Calculate the hash
	hashInBytes := hash.Sum(nil)

	// Print the hash
	fmt.Printf("SHA256 hash of %s: %x\n", filePath, hashInBytes)
}
