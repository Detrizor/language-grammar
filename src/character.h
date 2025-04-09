#pragma once

class Visitor;

class LanguageCharacter
{
#ifdef OOP_APPROACH

public:
	virtual ~LanguageCharacter() = default;

public:
	virtual void accept(Visitor& visitor) const = 0;
#endif
};

class NonTerminalCharacter : public LanguageCharacter
{
public:
	explicit NonTerminalCharacter(char d) : _data(d) {}

private:
	const char _data;

public:
	[[nodiscard]] char getChar() const { return _data; }

#ifdef OOP_APPROACH
	void accept(Visitor& visitor) const override;
#endif
};

class TokenCharacter : public LanguageCharacter
{
public:
	explicit TokenCharacter(char d) : _data(static_cast<wchar_t>(d)) {}

private:
	const wchar_t _data;

public:
	[[nodiscard]] wchar_t getChar() const { return _data; }

#ifdef OOP_APPROACH
	void accept(Visitor& visitor) const override;
#endif
};

#ifndef OOP_APPROACH
#include <variant>
using CharacterVariant = std::variant<NonTerminalCharacter, TokenCharacter>;
#endif
