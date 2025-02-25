#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <sstream>
#include <iomanip>
#include <openssl/sha.h>

using namespace std;

string sha256(const string& data) {
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256((unsigned char*)data.c_str(), data.length(), hash);
    stringstream ss;
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}

class Block {
public:
    int index;
    time_t timestamp;
    string data;
    string previousHash;
    string hash;
    int nonce;

    Block(int idx, const string& d, const string& prevHash) 
        : index(idx), data(d), previousHash(prevHash), nonce(0) {
        timestamp = time(nullptr);
        hash = calculateHash();
    }

    string calculateHash() const {
        stringstream ss;
        ss << index << timestamp << data << previousHash << nonce;
        return sha256(ss.str());
    }

    void mineBlock(int difficulty) {
        string target(difficulty, '0');  
        do {
            nonce++;
            hash = calculateHash();
        } while (hash.compare(0, difficulty, target) != 0);
        
        cout << "Block mined! Hash: " << hash << endl;
    }
};

class Blockchain {
private:
    vector<Block> chain;
    int difficulty;

public:
    Blockchain(int diff = 3) : difficulty(diff) {
        Block genesis(0, "Genesis Block", "0");
        genesis.hash = genesis.calculateHash();  // Precompute instead of mining
        chain.push_back(genesis);
    }

    void addBlock(const string& data) {
        Block newBlock(chain.size(), data, chain.back().hash);
        newBlock.mineBlock(difficulty);
        chain.push_back(newBlock);
    }

    bool isChainValid() const {
        if (chain[0].hash != chain[0].calculateHash()) {
            cout << "Genesis block hash invalid!" << endl;
            return false;
        }
        for (size_t i = 1; i < chain.size(); i++) {
            const Block& current = chain[i];
            const Block& previous = chain[i - 1];
            if (current.hash != current.calculateHash() || current.previousHash != previous.hash) {
                cout << "Blockchain is invalid at block " << i << endl;
                return false;
            }
        }
        return true;
    }
};
