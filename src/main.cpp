#include "pch.h"

#include "character.h"
#include "visitor.h"

#include <iostream>
#include <vector>
#include <ranges>
#include <random>

template<typename CharacterType>
void fill_chars(const char* str, char from, auto& dest)
{
	static std::random_device                 rd;
	static std::mt19937                       mt(rd());
	static std::uniform_int_distribution<int> dist(0, 25);

	std::cout << "Enter " << str << " characters count: ";
	size_t char_count;
	std::cin >> char_count;

	dest.reserve(dest.size() + char_count);
	for ([[maybe_unused]] auto _ : std::views::iota(0u, char_count))
#ifdef OOP_APPROACH
		dest.emplace_back(std::make_unique<CharacterType>(from + dist(mt)));
#else
		dest.emplace_back(CharacterType{ static_cast<char>(from + dist(mt)) });
#endif
}

int main()
{
#ifdef OOP_APPROACH
	std::vector<std::unique_ptr<LanguageCharacter>> chars;
#else
	std::vector<CharacterVariant> chars;
#endif
	fill_chars<NonTerminalCharacter>("non-terminal", 'A', chars);
	fill_chars<TokenCharacter>("token", wchar_t{ 'a' }, chars);

	JsonTranslator json;
	XmlTranslator  xml;

	for (auto&& ch : chars)
	{
#ifdef OOP_APPROACH
		ch->accept(json);
		ch->accept(xml);
#else
		std::visit(json, ch);
		std::visit(xml, ch);
#endif
	}

	std::cout << std::endl;
	std::cout << json.getResult();
	std::cout << xml.getResult();

	system("pause");

	return 0;
}
