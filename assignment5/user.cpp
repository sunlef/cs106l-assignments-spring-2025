#include "user.h"
#include <algorithm>

/**
 * Creates a new User with the given name and no friends.
 */
User::User(const std::string &name) : _name(name), _friends(nullptr), _size(0), _capacity(0) {}

/**
 * Adds a friend to this User's list of friends.
 * @param name The name of the friend to add.
 */
void User::add_friend(const std::string &name) {
  if (_size == _capacity) {
    _capacity = 2 * _capacity + 1;
    std::string *newFriends = new std::string[_capacity];
    for (size_t i = 0; i < _size; ++i) {
      newFriends[i] = _friends[i];
    }
    delete[] _friends;
    _friends = newFriends;
  }

  _friends[_size++] = name;
}

/**
 * Returns the name of this User.
 */
std::string User::get_name() const { return _name; }

/**
 * Returns the number of friends this User has.
 */
size_t User::size() const { return _size; }

/**
 * Sets the friend at the given index to the given name.
 * @param index The index of the friend to set.
 * @param name The name to set the friend to.
 */
void User::set_friend(size_t index, const std::string &name) { _friends[index] = name; }

User::~User() { delete[] _friends; }

User::User(User const &other)
    : _name(other._name), _friends(nullptr), _size(other._size), _capacity(other._capacity) {
  if (_capacity > 0) {
    _friends = new std::string[_capacity];
    for (size_t i = 0; i < _size; i++) {
      _friends[i] = other._friends[i];
    }
  }
}

User &User::operator=(User const &other) {
  if (this != &other) {
    std::string *nfriends = nullptr;
    if (other._capacity > 0) {
      nfriends = new std::string[other._capacity];
      for (size_t i = 0; i < other._size; i++) {
        nfriends[i] = other._friends[i];
      }
    }

    delete[] _friends;

    _name = other._name;
    _friends = nfriends;
    _size = other._size;
    _capacity = other._capacity;
  }
  return *this;
}

bool User::operator<(User const &other) const { return _name < other._name; }

void User::print(std::ostream &os) const {
  os << "User(name=" << _name << ", friends=[";
  for (size_t i = 0; i < _size; i++) {
    os << _friends[i];
    if (i != _size - 1) {
      os << ", ";
    }
  }
  os << "])";
}

User &User::operator+=(User &other) {
  if (this != &other) {
    bool already_is_friend = (std::count(_friends, _friends + _size, other._name) > 0);
    if (already_is_friend) {
      return *this;
    }

    add_friend(other._name);
    other.add_friend(_name);
  }
  return *this;
}

std::ostream &operator<<(std::ostream &os, User const &user) {
  user.print(os);
  return os;
}
