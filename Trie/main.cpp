#include <string>;
#include <iostream>
#include "Trie.h"

using std::string;
using std::cout;
using std::endl;

int main() {
	Trie* trie = new Trie();
	trie->insert("programming");
	trie->insert("amm");
	trie->insert("am");
	trie->insert("dcfam");

	trie->print();

	//cout << trie->find("programming") << endl;
	//cout << "Deleting word" << endl;
	//cout << trie->remove("1programming");
	// cout << trie->find("programming");

	return 0;
}