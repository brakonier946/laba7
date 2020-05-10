#pragma once

#include "univer.h"
#include <functional>
#include <list>

using namespace std;

class Spisok
{
private:
	list<univer> _data;
public:

	Spisok() { }

	void add(univer data) {
		_data.push_back(data);
	}

	void print() {
		for (auto it = _data.begin(); it != _data.end(); it++) {
			cout << *it << endl;
		}
	}

	void sort(function<bool(univer, univer)> comparator) {
		for (auto it1 = _data.begin(); it1 != _data.end(); it1++) {
			for (auto it2 = _data.begin(); it2 != _data.end(); it2++) {
				if (comparator(*it2, *it1)) {
					std::swap(*it1, *it2);
				}
			}
		}
	}

	int size() { return _data.size(); }

	void removeDuplicate(function<bool(univer, univer)> comparator) {
		_data.unique(comparator);
	}

	int firstInclude(list<univer>::iterator b, list<univer>::iterator e, function<bool(univer, univer)> comparator) {
		int index = 0;

		for (auto it1 = _data.begin(); it1 != _data.end(); it1++) {
			index++;
			auto it2 = b;
			if (comparator(*it1, *it2)) {
				for (auto it3 = it1; it2 != e; it2++) {
					if (!comparator(*it2, *it3))
						break;
				}
				it2++;
				if (it2 == e)
					return index - 1;
			}
		}

		return -1;
	}

	list<univer>::iterator begin() { return _data.begin(); }
	list<univer>::iterator end() { return _data.end(); }
};

