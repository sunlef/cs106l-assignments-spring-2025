#include "spellcheck.h"

#include <algorithm>
#include <iostream>
#include <numeric>
#include <ranges>
#include <set>
#include <vector>

template <typename Iterator, typename UnaryPred>
std::vector<Iterator> find_all(Iterator begin, Iterator end, UnaryPred pred);

Corpus tokenize(std::string &source) {
  auto spacesIts = find_all(source.begin(), source.end(),
                            static_cast<int (*)(int)>(std::isspace));

  Corpus tokens;

  std::transform(spacesIts.begin(), spacesIts.end() - 1, spacesIts.begin() + 1,
                 std::inserter(tokens, tokens.end()),
                 [&source](auto const &it1, auto const &it2) {
                   return Token{source, it1, it2};
                 });

  std::erase_if(tokens, [](Token const &ti) { return ti.content.empty(); });

  return tokens;
}

std::set<Misspelling> spellcheck(const Corpus &source,
                                 const Dictionary &dictionary) {
  auto checks = source |
                std::ranges::views::filter([&dictionary](Token const &ti) {
                  return !dictionary.contains(ti.content);
                }) |
                std::ranges::views::transform([&dictionary](Token const &ti) {
                  auto view = dictionary |
                              std::views::filter([&ti](std::string const &di) {
                                return levenshtein(di, ti.content) == 1;
                              });

                  return Misspelling{ti, std::set(view.begin(), view.end())};
                }) |
                std::ranges::views::filter([](Misspelling const &mi) {
                  return !mi.suggestions.empty();
                });

  return std::set(checks.begin(), checks.end());
}

/* Helper methods */

#include "utils.cpp"