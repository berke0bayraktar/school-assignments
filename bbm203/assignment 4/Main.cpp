#include <iostream>
#include "IO.h"
#include "Huffman.h"

void encode_op(std::string& MESSAGE_PATH, std::string ENCODING_PATH, std::string TREE_PATH) {
    // read message to be encoded
    std::string message = IO::read_from_file(MESSAGE_PATH);

    // generate huffman tree from the message
    BTNode* huffman_tree = Huffman::generate_tree(message);

    // use huffman tree to generate an encoding for the message
    std::string encoded_message = Huffman::encode(message, huffman_tree);

    // serialize and save the tree for later use
    IO::save_tree(huffman_tree, TREE_PATH);

    // save encoded message for later use
    IO::save_to_file(encoded_message, ENCODING_PATH);

    std::cout << encoded_message << std::endl;
}

void decode_op(std::string& ENCODING_PATH, std::string& TREE_PATH) {
    // read the previously saved encoded message
    std::string encoded_message = IO::read_from_file(ENCODING_PATH);

    // read and deserialize the previously saved huffman tree
    BTNode* huffman_tree = IO::read_tree(TREE_PATH);

    // use huffman tree for decoding the encoded message
    std::string decoded_message = Huffman::decode(encoded_message, huffman_tree);

    std::cout << decoded_message << std::endl;
}

void char_op(std::string c, std::string& TREE_PATH) {
    // read and deserialize the previously saved huffman tree
    BTNode* huffman_tree = IO::read_tree(TREE_PATH);

    //lowercase the string
    c[0] = (char) tolower(c[0]);

    // use huffman tree for encoding a single character
    std::string char_encoding = Huffman::get_huffman_encoding(c, huffman_tree);

    std::cout << "encoding for '" << c << "' is:" << char_encoding << std::endl;
}

void list_tree(std::string& TREE_PATH) {
    // read and deserialize the previously saved huffman tree
    BTNode* huffman_tree = IO::read_tree(TREE_PATH);

    // get a human-readable string representation for huffman tree
    std::string listed_tree = Huffman::list(huffman_tree);

    std::cout << std::endl <<listed_tree << std::endl;
}


int main(int argc, char *argv[]) {
    std::string command, ENCODING_PATH, TREE_PATH;
    command = argv[1];
    ENCODING_PATH = "./encoding.txt";
    TREE_PATH = "./tree.txt";
    if (command == "-i") {
        std::string FILE_PATH, operation;
        FILE_PATH = argv[2];
        operation = argv[3];

        if (operation == "-encode") {
            encode_op(FILE_PATH, ENCODING_PATH, TREE_PATH);
        }
        else if (operation == "-decode") {
            decode_op(FILE_PATH, TREE_PATH);
        }
    }
    else if (command == "-s") {
        std::string c = argv[2];
        char_op(c, TREE_PATH);
    }
    else if (command == "-l") {
        list_tree(TREE_PATH);
    }
}



