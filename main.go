package main

import (
	"crypto/sha256"
	"fmt"
	"io"
	"os"
)

func main() {
	// Check if at least one argument is provided
	if len(os.Args) < 2 {
		fmt.Println("Usage: gohash file_path1 [file_path2 ...]")
		return
	}

	// Iterate over provided file paths
	for _, filePath := range os.Args[1:] {
		// Open the file
		file, err := os.Open(filePath)
		if err != nil {
			fmt.Printf("Error opening file %s: %s\n", filePath, err)
			continue
		}
		defer file.Close()

		// Create SHA256 hash
		hash := sha256.New()

		// Copy the file content into the hash object
		if _, err := io.Copy(hash, file); err != nil {
			fmt.Printf("Error reading file %s: %s\n", filePath, err)
			continue
		}

		// Calculate the hash
		hashInBytes := hash.Sum(nil)

		// Print the hash
		fmt.Printf("SHA256 hash of %s: %x\n", filePath, hashInBytes)
	}
}
