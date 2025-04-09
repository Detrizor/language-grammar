#pragma once

#include <string>

class NonTerminalCharacter;
class TokenCharacter;

class Visitor
{
public:
	virtual ~Visitor() = default;

public:
#ifdef OOP_APPROACH
	virtual void visit(const NonTerminalCharacter&) = 0;
	virtual void visit(const TokenCharacter&)       = 0;
#endif

protected:
	std::string _buf{};
};

class JsonTranslator : public Visitor
{
public:
#ifdef OOP_APPROACH
	void visit(const NonTerminalCharacter& ch) override;
	void visit(const TokenCharacter& ch) override;
#else
	void operator()(const NonTerminalCharacter& ch);
	void operator()(const TokenCharacter& ch);
#endif

	[[nodiscard]] std::string getResult() const;
};

class XmlTranslator : public Visitor
{
public:
#ifdef OOP_APPROACH
	void visit(const NonTerminalCharacter& ch) override;
	void visit(const TokenCharacter& ch) override;
#else
	void operator()(const NonTerminalCharacter& ch);
	void operator()(const TokenCharacter& ch);
#endif

	[[nodiscard]] std::string getResult() const;
};
