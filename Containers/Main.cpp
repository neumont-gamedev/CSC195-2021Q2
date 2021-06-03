#include <iostream>
#include <assert.h>

template <typename TValue>
class set
{
	struct node_t
	{
		node_t(const TValue& value) : _value{ value } {}

		TValue _value;
		node_t* _left{ nullptr };
		node_t* _right{ nullptr };
	};

public:
	~set()
	{
		clear(_root);
	}

	void insert(const TValue& value)
	{
		node_t* new_node = new node_t{ value };

		if (_root == nullptr)
		{
			_root = new_node;
		}
		else
		{
			node_t* node = _root;
			while (node)
			{
				if (value < node->_value)
				{
					if (node->_left == nullptr)
					{
						node->_left = new_node;
						break;
					}
					else node = node->_left;
				}
				else
				{
					if (node->_right == nullptr)
					{
						node->_right = new_node;
						break;
					}
					else node = node->_right;
				}
			}
		}
	}

	bool find(const TValue& value)
	{
		node_t* node = _root;
		while (node && node->_value != value)
		{
			node = (value < node->_value) ? node->_left : node->_right;
		}

		return (node);
	}

private:
	void clear(node_t* node)
	{
		if (node == nullptr) return;

		clear(node->_left);
		clear(node->_right);

		delete node;
	}

private:
	node_t* _root{};
};


template <typename TKey, typename TValue>
class map
{
	struct node_t
	{
		node_t(const TKey& key, const TValue& value) : _key{ key }, _value{ value } {}

		TKey _key;
		TValue _value;
		node_t* _left{ nullptr };
		node_t* _right{ nullptr };
	};

public:
	void insert(const TKey& key, const TValue& value)
	{
		node_t* new_node = new node_t{ key, value };

		if (_root == nullptr)
		{
			_root = new_node;
		}
		else
		{
			node_t* node = _root;
			while (node)
			{
				if (key < node->_key)
				{
					if (node->_left == nullptr)
					{
						node->_left = new_node;
						break;
					}
					else node = node->_left;
				}
				else
				{
					if (node->_right == nullptr)
					{
						node->_right = new_node;
						break;
					}
					else node = node->_right;
				}
			}
		}
	}

	TValue& at(const TKey& key)
	{
		node_t* node = find(key);

		if (node == nullptr)
		{
			insert(key, TValue{});
			node = find(key);
		}
		
		return node->_value;
	}

private:
	node_t* find(const TKey& key)
	{
		node_t* node = _root;
		while (node && node->_key != key)
		{
			std::cout << node->_value << std::endl;
			node = (key < node->_key) ? node->_left : node->_right;
		}

		return node;
	}

private:
	node_t* _root{};
};

template <typename TKey, typename TValue, size_t Capacity>
class unordered_map
{
public:
	unordered_map()
	{
		_table = new TValue * [Capacity] {};
	}

	void insert(const TKey& key, const TValue& value)
	{
		size_t hash_value = _hash(key);
		std::cout << "hash: " << hash_value << std::endl;
		size_t index = hash_value % Capacity;
		std::cout << "index: " << index << std::endl;

		_table[index] = new TValue{ value };
	}

	TValue& at(const TKey& key)
	{
		size_t hash_value = _hash(key);
		size_t index = hash_value % Capacity;

		assert(_table[index]);
		return *_table[index];
	}

private:
	std::hash<TKey> _hash;
	TValue** _table;
};

typedef int id_t;

int main()
{
	set<id_t> ids;
	ids.insert(15);
	ids.insert(23);
	ids.insert(43);

	std::cout << "found (43): " << ids.find(43) << std::endl;
	std::cout << "found (20): " << ids.find(20) << std::endl;

	map<id_t, std::string> names;
	names.insert(10, "Zack");
	names.insert(5, "James");
	names.insert(20, "Cole");
	names.insert(15, "Alex");
	names.insert(2, "Jesse");

	std::cout << names.at(15) << std::endl;

	unordered_map<std::string, int, 1024> hash_map;
	hash_map.insert("hello", 24);
	hash_map.insert("world", 36);

	std::cout << hash_map.at("hello") << std::endl;
	std::cout << hash_map.at("world") << std::endl;
	//std::cout << hash_map.at("error") << std::endl;
}