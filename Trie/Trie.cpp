#include "Trie.h"

bool Trie::hasChilds(Node* node) {
	bool hasChilds = false;
	int i = 0;
	while (!hasChilds && i < ALPHABET_SIZE) {
		hasChilds = node->symbols[i] != nullptr;
		i++;
	}
	return hasChilds;
}

bool Trie::remove(Node* node, string word, int h)
{
	if (node == nullptr && word.length() > 0) {
		return false;
	}

	if (word.length() == h) {
		node->eow = false;
		if (hasChilds(node) == false) {
			delete node;
			node = nullptr;
		}
		return true;
	}

	char symbol = word[h];
	int index = symbol - 'a';
	return remove(node->symbols[index], word, h + 1);
}

Trie::Trie()
{
	root = new Node('/');
}

Trie::~Trie()
{
} 

void Trie::insert(string word) {
	Node* current = root;
	for (int i = 0; i < word.size(); ++i)
	{
		char symbol = word[i];
		int index = symbol - 'a';
		if (current->symbols[index] == nullptr)
		{
			current->symbols[index] = new Node(symbol);
		}

		current = current->symbols[index];
	}
	current->eow = true;
}

bool Trie::find(string word)
{
	Node* current = root;
	for (int i = 0; i < word.size(); ++i)
	{
		char symbol = word[i];
		int index = symbol - 'a';
		if (current->symbols[index] == nullptr) {
			return false;
		}
		current = current->symbols[index];
	}
	return current->eow;
}


bool Trie::remove(string word)
{
	return remove(root, word, 0);
}


void Trie::clear()
{
}

void printRecursive(Node* node, string word, int h) {
	if (node != nullptr) {
		if (node->eow) {
			cout << word << endl;
		}

		for (int i = 0; i < ALPHABET_SIZE; i++) {
			printRecursive(node->symbols[i], word + node->c, h + 1);
		}
	}
}

void Trie::print()
{
	for (int i = 0; i < ALPHABET_SIZE; i++) {
		printRecursive(root->symbols[i], "", 1);
	}
}
