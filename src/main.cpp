#include "pch.h"

#include "character.h"
#include "visitor.h"

#include <iostream>
#include <vector>
#include <ranges>
#include <random>

template<typename T>
void fill_chars(const char* str, char from, auto& dest)
{
	static std::random_device                 rd;
	static std::mt19937                       mt(rd());
	static std::uniform_int_distribution<int> dist(0, 26);

	std::cout << "Enter " << str << " characters count: ";
	size_t char_count;
	std::cin >> char_count;

	dest.reserve(dest.size() + char_count);
	for ([[maybe_unused]] auto _ : std::views::iota(0u, char_count))
		dest.emplace_back(std::make_unique<T>(from + dist(mt)));
}

int main()
{
	std::vector<std::unique_ptr<LanguageCharacter>> chars;
	fill_chars<NonTerminalCharacter>("non-terminal", 'A', chars);
	fill_chars<TokenCharacter>("token", 'a', chars);

	JsonTranslator json;
	XmlTranslator  xml;

	for (auto&& ch : chars)
	{
		ch->accept(json);
		ch->accept(xml);
	}

	std::cout << json.getResult() << '\n';
	std::cout << xml.getResult() << "\n\n";
}
