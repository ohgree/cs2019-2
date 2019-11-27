#define ASCII_MAX_VALUE 127
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
   _huffman_node() {
      this->left = this->right = NULL;
      this->id = INVALID_CHAR;
   }
};
typedef _huffman_node* node_ptr;

class Huffman {
   protected:
      std::string inFilename, outFilename;
      std::ifstream inFile;
      std::ofstream outFile;
      HuffmanOption option;
      node_ptr huffmanTree;
      std::vector<node_ptr> huffmanCode;
      class compare {
         public:
            bool operator()(const node_ptr& v, const node_ptr& u) const {
               return v->freq > u->freq;
            }
      };
      priority_queue<node_ptr, std::vector<node_ptr>, compare> pq;
      void makeHuffmanTree(void);
      void assignBinaryCode(node_ptr);
      void assignBinaryCode(node_ptr, std::string);
      void initialize(void);
      void openFile(void);
      void writeToFile(std::string);
      void reconstructTree(void);
      char binToByte(string);
   public:
      Huffman(std::string, HuffmanOption);
      const string getHuffmanCodeOf(char);
      void encode(void);
      void decode(void);
};

Huffman::Huffman(string filename, HuffmanOption opt) {
   this->inFilename = filename;
   this->outFilename = inFilename + ((opt == ENCODE) ? ".zz" : ".yy");
   this->option = opt;
   initialize();
}

char Huffman::binToByte(string bin) {
   char byte=0;
   for(std::string::size_type i=0 ; i<bin.length() ; i++) {
      byte = byte*2 + bin[i] - '0';
   }
   return byte;
}

/**
 *  Bit string format:
 *     1B
 *  [mapping #]
 *   1B           128bit = 16B
 *  [id][0000..padding|1|huffman code]
 *                ...
 *  [id][0000..padding|1|huffman code]
 *                N-B                  1B
 *  [encoded bit string|0 padding][# of padding]
 *
 */
void Huffman::writeToFile(std::string bits) {
   string out, cell;
   cout << "[Debug Info]" << endl;
   cout << bits << endl;
   for(std::vector<node_ptr>::size_type i=0 ; i<huffmanCode.size() ; i++) {
      cout << huffmanCode[i]->freq << " " << huffmanCode[i]->id << "[" << (int)huffmanCode[i]->id << "]" << huffmanCode[i]->code << endl;
   }

   /* open output file in binary mode */
   outFile.open(outFilename, ios::out|ios::binary);
   if(!outFile.is_open()) {
      cout << "error opening file " << outFilename << endl;
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
       * [0000...|1|CODE]
       */

      /* padding with zero */
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
   while(inFile.good()) {
      inFile.get(k);
      codedBits += getHuffmanCodeOf(k);
      while(codedBits.length() > 8) {
         out += binToByte(codedBits.substr(0, 8));
         codedBits = codedBits.substr(8);
      }
   }
   int num_of_padding = 8-codedBits.length();
   cout << "padding: " << num_of_padding << " to " <<  codedBits << endl;
   codedBits.append(num_of_padding, '0');
   out += binToByte(codedBits);
   out += (char)num_of_padding;

   inFile.close();
   outFile.write(out.c_str(), out.size());
   outFile.close();
}

const string Huffman::getHuffmanCodeOf(char id) {
   for(std::vector<node_ptr>::size_type i = 0 ; i < huffmanCode.size() ; i++) {
      if(huffmanCode[i]->id == id)
         return huffmanCode[i]->code;
   }
   return NULL;
}

void Huffman::encode(void) {
   string encrypted;
   int len;
   char* buffer;
   
   /* read whole file */
   inFile.seekg(0, ios::end);
   len = inFile.tellg();
   inFile.seekg(0, ios::beg);

   buffer = new char[len];
   
   inFile.read(buffer, len);

   for(int i=0 ; i<len ; i++) {
      encrypted += getHuffmanCodeOf(buffer[i]);
   }
   
   writeToFile(encrypted);
}

void Huffman::openFile(void) {
   inFile.open(inFilename, ios::in|ios::binary);
   if(!inFile.is_open()) {
      cout << "error while opening file " << inFilename << endl;
      exit(1);
   }
}

void Huffman::initialize(void) {
   openFile();
   if(option == ENCODE) {
      makeHuffmanTree();
      assignBinaryCode(huffmanTree, "");
   }
}

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

   delete[] buffer;

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

int main(int argc, const char* argv[]) {
   string filename, arg;
   HuffmanOption opt;
   if(argc != 3) {
      cout << "invalid number of arguments" << endl;
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
   hm.encode();
   return 0;
}
