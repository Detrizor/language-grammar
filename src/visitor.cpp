#include "pch.h"
#include "visitor.h"

#include "character.h"

void JsonTranslator::visit(const NonTerminalCharacter& ch)
{
	_buf += ch.getChar();
}

void JsonTranslator::visit(const TokenCharacter& ch)
{
	_buf += static_cast<char>(ch.getChar());
}

std::string JsonTranslator::getResult() const
{
	return R"({ "language": "English", "chars": ")" + _buf + "\" }";
}

void XmlTranslator::visit(const NonTerminalCharacter& ch)
{
	_buf += ch.getChar();
}

void XmlTranslator::visit(const TokenCharacter& ch)
{
	_buf += static_cast<char>(ch.getChar());
}

std::string XmlTranslator::getResult() const
{
	return "<Language name=\"English\"><Chars>" + _buf + "</Chars></Language>";
}
