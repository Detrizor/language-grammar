#pragma once

class Visitor;

class LanguageCharacter
{
public:
	virtual ~LanguageCharacter() = default;

public:
	virtual void accept(Visitor& visitor) const = 0;
};

class NonTerminalCharacter : public LanguageCharacter
{
public:
	explicit NonTerminalCharacter(char d) : _data(d) {}

private:
	const char _data;

public:
	[[nodiscard]] char getChar() const { return _data; }

	void accept(Visitor& visitor) const override;
};

class TokenCharacter : public LanguageCharacter
{
public:
	explicit TokenCharacter(wchar_t d) : _data(d) {}

private:
	const wchar_t _data;

public:
	[[nodiscard]] wchar_t getChar() const { return _data; }

	void accept(Visitor& visitor) const override;
};
