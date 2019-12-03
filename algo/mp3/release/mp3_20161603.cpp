/**
 * @file mp3_20161603.cpp
 * @brief Machine Problem 3 for Algorithms
 * @author MJ Shin
 * @version 1.0
 * @date 2019-11-28
 */
#define ASCII_MAX_VALUE 127
#define BYTE_SIZE 8
#define CODEBLOCK_SIZE (ASCII_MAX_VALUE+1)/BYTE_SIZE
#define INVALID_CHAR -1

#include <iostream>
#include <fstream>
#include <queue>
#include <list>

using namespace std;

enum HuffmanOption {
   DECODE,
   ENCODE,
};

struct _huffman_node {
   char id;
   int freq;
   std::string code;
   _huffman_node* left;
   _huffman_node* right;

   /* initialise constructor */
   _huffman_node() {
      this->left = this->right = NULL;
      this->id = INVALID_CHAR;
   }
};
typedef _huffman_node* node_ptr;

/**
 * @brief Class for implementing Huffman Code Encryption & Decryption
 */
class Huffman {
   protected:
      std::string inFilename, outFilename;
      std::ifstream inFile;
      std::ofstream outFile;
      HuffmanOption option;
      node_ptr huffmanTree;
      std::vector<node_ptr> huffmanCode;

      /* compare class for priority queue */
      class compare {
         public:
            bool operator()(const node_ptr& v, const node_ptr& u) const {
               return v->freq > u->freq;
            }
      };
      priority_queue<node_ptr, std::vector<node_ptr>, compare> pq;

      void makeHuffmanTree(void);
      void assignBinaryCode(node_ptr, std::string);
      void initialize(void);
      void openFile(void);
      void writeToFile();
      void reconstructTree(void);
      char binToByte(string);
      string byteToBin(unsigned char*, int);
      void addToTree(node_ptr);

   public:
      Huffman(std::string, HuffmanOption);
      const string getHuffmanCodeOf(char);
      void encode(void);
      void decode(void);
};

/**
 * @brief Default constructor for Huffman class
 *
 * @param filename File name to use as input
 * @param opt      Decode/Encode option
 */
Huffman::Huffman(string filename, HuffmanOption opt) {
   this->inFilename = filename;
   this->outFilename = inFilename + ((opt == ENCODE) ? ".zz" : ".yy");
   this->option = opt;
   initialize();
}

/**
 * @brief converts 8-bit binary bit string to byte
 * 
 * @param bin String containing binary representation of bit string.
 */
char Huffman::binToByte(string bin) {
   char byte=0;
   for(std::string::size_type i=0 ; i<bin.length() ; i++) {
      byte = byte*2 + bin[i] - '0';
   }
   return byte;
}

/**
 * @brief Write encoded text to output file.
 *
 *    Bit string format is as follows.
 *
 *      1Byte
 *    [mapping #]
 *
 *    1Byte     128bit = 16Bytes
 *    [id][0000..padding|1|huffman code]
 *    [id][0000..padding|1|huffman code]
 *                  ...
 *    [id][0000..padding|1|huffman code]
 *
 *                 N-Bytes              1Byte
 *    [encoded bit string|0 padding][# of padding]
 */
void Huffman::writeToFile() {
   string out, cell;

   /* open output file in binary mode */
   outFile.open(outFilename, ios::out|ios::binary);
   if(!outFile.is_open()) {
      cout << "error opening file: " << outFilename << endl;
      exit(1);
   }

   /* first byte in file = number of mappings in huffman code */
   out += (char)huffmanCode.size();

   for(std::vector<node_ptr>::size_type i=0 ; i<huffmanCode.size() ; i++) {
      node_ptr node(huffmanCode[i]);

      /* first byte before block is character representation of the cell */
      out += node->id;

      /**
       * since code length cannot exceed 127,
       * creating 128-bit block with format:
       *
       *  127-n   1  n
       * [0000...|1|CODE]
       */

      /* padding with zero, padding ends with 1 */
      cell.assign(ASCII_MAX_VALUE - node->code.size(), '0');
      cell += '1';
      cell.append(node->code);

      /* convert cell's binary to byte. 128/8 = 16 */
      for(int i=0 ; i<15 ; i++) {
         out += binToByte(cell.substr(0, 8));
         cell = cell.substr(8);
      }
      out += binToByte(cell.substr(0, 8));
      cell.clear();
   }

   /* reset input file */
   inFile.seekg(0, ios::beg);

   char k;
   string codedBits;

   /* read from file, and encode simultaneously */
   while(inFile.good()) {
      inFile.get(k);

      /* retrieve huffman code */
      codedBits += getHuffmanCodeOf(k);

      /* break codedBits by 8-bit bitstring, which is converted to byte */
      while(codedBits.length() > 8) {
         out += binToByte(codedBits.substr(0, 8));
         codedBits = codedBits.substr(8);
      }
   }

   /* add padding to match 8-bit size */
   int num_of_padding = 8-codedBits.length();
   codedBits.append(num_of_padding, '0');
   out += binToByte(codedBits);

   /* length of padding is written just before eof */
   out += (char)num_of_padding;

   inFile.close();
   outFile.write(out.c_str(), out.size());
   outFile.close();
}

/**
 * @brief Get huffman code of given character.
 *
 * @param id The character to get huffman code for.
 * @return String representing the bit string of corresponding huffman code.
 */
const string Huffman::getHuffmanCodeOf(char id) {
   for(std::vector<node_ptr>::size_type i = 0 ; i < huffmanCode.size() ; i++) {
      if(huffmanCode[i]->id == id)
         return huffmanCode[i]->code;
   }
   return NULL;
}

/**
 * @brief Encode with initialised data, then write the result.
 */
void Huffman::encode(void) {
   writeToFile();
}

/**
 * @brief Open input file.
 */
void Huffman::openFile(void) {
   inFile.open(inFilename, ios::in|ios::binary);
   if(!inFile.is_open()) {
      cout << "error while opening file: " << inFilename << endl;
      exit(1);
   }
}

/**
 * @brief Initialise class, depending on the option.
 */
void Huffman::initialize(void) {
   openFile();
   if(option == ENCODE) {
      makeHuffmanTree();
      assignBinaryCode(huffmanTree, "");
   } else {
      reconstructTree();
   }
}

/**
 * @brief Assign binary code to huffman tree, recursively
 *
 * @param root Root node of huffman tree
 * @param code Current bitstring. Do assign "" when calling.
 */
void Huffman::assignBinaryCode(node_ptr root, string code) {
   if(!root) {
      cerr << "DFS error!" << endl;
      exit(1);
   }
   if(root->left == NULL and root->right == NULL) {
      root->code = code;
      return;
   }
   assignBinaryCode(root->left, code + "0");
   assignBinaryCode(root->right, code + "1");
}

/**
 * Create a huffman tree from given data.
 */
void Huffman::makeHuffmanTree(void) {
   int occurence[ASCII_MAX_VALUE+1] = {0};
   int len;
   char* buffer;

   if(!inFile.is_open())
      openFile();

   /* read whole file */
   inFile.seekg(0, ios::end);
   len = inFile.tellg();
   inFile.seekg(0, ios::beg);

   buffer = new char[len];
   
   inFile.read(buffer, len);

   /* record occurences of ASCII chars in file */
   for(int i=0 ; i<len ; i++) {
      occurence[(unsigned int)buffer[i]]++;
   }
   delete[] buffer;

   /* create priority queue from recorded characters */
   for(int i=0 ; i<ASCII_MAX_VALUE+1 ; i++) {
      if(!occurence[i])
         continue;
      node_ptr v = new _huffman_node();
      v->id = i;
      v->freq = occurence[i];
      pq.push(v);
      huffmanCode.push_back(v);
   }

   while(pq.size() > 1) {

      /* popping smallest & 2nd-smallest freq from priority queue */
      node_ptr v = pq.top();
      pq.pop();
      node_ptr u = pq.top();
      pq.pop();

      /* union two popped node, then add it to the priority queue again */
      node_ptr newNode = new _huffman_node();
      newNode->left = v;
      newNode->right = u;
      newNode->freq = v->freq + u->freq;
      pq.push(newNode);
   }

   /* huffman tree is stored in PQ's top */
   this->huffmanTree = pq.top();
   pq.pop();
}

/**
 * @brief Convert byte character to binary bitstring.
 *
 * @param byte Byte pointer for arrays.
 * @param n    Number of elements in byte array.
 *
 * @return    String instance representing binary bitstring.
 */
string Huffman::byteToBin(unsigned char* byte, int n) {
   string result;
   for(int i=0 ; i<n ; i++) {
      for(int j=ASCII_MAX_VALUE+1 ; j>0 ; j/=2) {
         result += (char)(byte[i] / j + '0');
         byte[i] %= j;
      }
   }
   return result;
}

/**
 * @brief Add given node to huffman tree.
 *
 * @param node Node to add.
 */
void Huffman::addToTree(node_ptr node) {
   char id = node->id;
   string code = node->code;

   node_ptr now = this->huffmanTree;

   for(int i=0 ; i < (int)code.size() ; i++) {
      if(code[i] == '0') {
         if(!now->left)
            now->left = new _huffman_node();
         now = now->left;
      } else {
         if(!now->right)
            now->right = new _huffman_node();
         now = now->right;
      }
   }
   now->id = id;
   now->code = string(code);
}

/**
 * @brief Reconstruct tree based on read bit string header.
 */
void Huffman::reconstructTree(void) {
   int nodeCount, padCount;
   unsigned char buffer[CODEBLOCK_SIZE];
   node_ptr temp;
   nodeCount = inFile.get();

   /* initialize root of huffman tree */
   this->huffmanTree = new _huffman_node();

   /* read headers */
   for(int i=0 ; i<nodeCount ; i++) {
      temp = new _huffman_node();

      /* get a id byte from file */
      temp->id = inFile.get();
      
      /* read 128-bit(16Byte) block containing code */
      inFile.read((char*)buffer, CODEBLOCK_SIZE);

      string codeBit = byteToBin(buffer, CODEBLOCK_SIZE);

      /* count number of 0 paddings in code bits */
      for(padCount = 0 ; codeBit[padCount] == '0' ; padCount++);

      /* remove 0 paddings and leading 1 from code bits */
      codeBit = codeBit.substr(padCount+1);
      temp->code = codeBit;

      /* add new node to code list, and add to tree */
      this->huffmanCode.push_back(temp);
      addToTree(temp);
   }
   inFile.close();
}

/**
 * @brief Decode input file's contents, and writes decoded text to file
 */
void Huffman::decode() {
   outFile.open(outFilename, ios::out);
   inFile.open(inFilename, ios::in|ios::binary);
   unsigned char mapSize;
   unsigned char trailing0s;
   unsigned char temp;
   vector<unsigned char> text;
   string decoded;
   string binary;

   mapSize = inFile.get();

   /* go to the end of the file, get 1 byte: number of trailing zeros */
   inFile.seekg(-1, ios::end);
   trailing0s = inFile.get();

   /* get to the start of bit stream */
   inFile.seekg(1 + (CODEBLOCK_SIZE+1)*mapSize, ios::beg);

   temp = inFile.get();
   while(inFile.good()){
      text.push_back(temp);
      temp = inFile.get();
   }
   text.pop_back(); // remove trailing 1 byte: number of trailing zeros

   binary += byteToBin(&text[0], text.size());
   binary = binary.substr(0, binary.size()-trailing0s);

   /* decoding by traversing huffman tree according to read data */
   node_ptr now = this->huffmanTree;
   for(std::vector<unsigned char>::size_type i=0 ; i<binary.size() ; i++) {
      if(now->left == NULL and now->right == NULL) {
         decoded += now->id;
         now = this->huffmanTree;
      }
      if(binary[i] == '0') {
         now = now->left;
      } else {
         now = now->right;
      }
   }

   outFile.write(decoded.c_str(), decoded.size());
   outFile.close();
   inFile.close();
}

int main(int argc, const char* argv[]) {
   string filename, arg;
   HuffmanOption opt;
   if(argc != 3) {
      cout << "error: invalid number of arguments" << endl;
      cout << "usage: " << string(argv[0]) << " [-c|-d] filename" << endl;
      exit(1);
   }
   filename = string(argv[2]);
   arg = string(argv[1]);
   if(arg == "-c") {
      opt = ENCODE;
   } else if(arg == "-d") {
      opt = DECODE;
   } else {
      cout << "invalid option: " << arg << endl;
      exit(1);
   }
   Huffman hm(filename, opt);

   if(opt == ENCODE)
      hm.encode();
   else
      hm.decode();
   return 0;
}
