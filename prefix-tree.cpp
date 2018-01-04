#include <iostream>
#include <string>
#include <iomanip>
#include <memory>
#include <ios>

class Trie
{
private:

	std::unique_ptr<Trie> nodes[26] = {};

public:

	/** Initialize your data structure here. */
	Trie() = default;

	/** Inserts a word into the trie. */
	void insert(std::string const &word)
	{
		Trie *current = this;
		for (auto c : word)
		{
			int i = c - 'a';
		
			if (!current->nodes[i])
				current->nodes[i] = std::make_unique<Trie>();

			current = current->nodes[i].get();
		}
	}

	/** Returns true if the word is in the trie. */
	bool search(std::string const &word)
	{
		Trie *current = this;
		for (auto c : word)
		{
			int i = c - 'a';

			if (!current->nodes[i])
				return false;

			current = current->nodes[i].get();
		}

		return true;
	}

	/** Returns true if there is any word in the trie that starts with the given prefix. */
	bool startsWith(std::string const &prefix) 
	{
		return search(prefix);
	}

	/**
	* Your Trie object will be instantiated and called as such:
	* Trie obj = Trie();
	* obj.insert(word);
	* bool param_2 = obj.search(word);
	* bool param_3 = obj.startsWith(prefix);
	*/

};

int main()
{
	Trie obj = Trie();
	obj.insert("fuck");

	std::cout << "The word \"fcuk\" is found: " << std::boolalpha << obj.search("fcuk") << std::endl;
	std::cout << "The word \"fuck\" is found: " << std::boolalpha << obj.search("fuck") << std::endl;
	std::cout << "A word with \"fc\" prefix exists: " << std::boolalpha << obj.startsWith("fc") << std::endl;
	std::cout << "A word with \"fu\" prefix exists: " << std::boolalpha << obj.startsWith("fu") << std::endl;

	return 0;
}