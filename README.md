Simple Blockchain in C++
🚀 Overview
This is a basic blockchain implementation written in C++ with a Proof-of-Work (PoW) consensus mechanism. It demonstrates core blockchain concepts such as:
✅ Block structure with hashing and nonce
✅ Mining (Proof-of-Work) to validate blocks
✅ Blockchain integrity check for security

📌 Features
SHA-256 hashing for block security
Proof-of-Work (PoW) with adjustable difficulty
Block validation to prevent tampering
Genesis block creation
🛠️ Installation & Compilation
1️⃣ Install OpenSSL (Required for SHA-256 hashing)
🔹 Linux (Ubuntu/Debian)

sh
sudo apt update && sudo apt install libssl-dev
🔹 MacOS (Homebrew)

sh
brew install openssl
🔹 Windows

Install OpenSSL from this link
Make sure OpenSSL is added to your system path
2️⃣ Compile the Code
Use g++ with OpenSSL libraries:

sh
g++ blockchain.cpp -o blockchain -lssl -lcrypto
🚀 Usage
Run the compiled program:

sh
./blockchain
Example Output
sh

Block mined! Hash: 000a3f9e8b0...
Block mined! Hash: 000b7c8e92c...
Blockchain is valid!
🏗️ Code Structure
📂 Classes Used

Block → Represents a block with hashing & PoW
Blockchain → Manages the chain, adds blocks, and validates
📂 Main Functions

calculateHash() → Generates SHA-256 hash
mineBlock() → Mines block by finding a valid nonce
isChainValid() → Ensures blockchain integrity
