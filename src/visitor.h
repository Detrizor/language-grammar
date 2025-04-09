#pragma once

#include <string>

class NonTerminalCharacter;
class TokenCharacter;

class Visitor
{
public:
	virtual ~Visitor() = default;

public:
	virtual void visit(const NonTerminalCharacter&) = 0;
	virtual void visit(const TokenCharacter&)       = 0;

protected:
	std::string _buf{};
};

class JsonTranslator : public Visitor
{
public:
	void visit(const NonTerminalCharacter& ch) override;
	void visit(const TokenCharacter& ch) override;

	[[nodiscard]] std::string getResult() const;
};

class XmlTranslator : public Visitor
{
public:
	void visit(const NonTerminalCharacter& ch) override;
	void visit(const TokenCharacter& ch) override;

	[[nodiscard]] std::string getResult() const;
};
