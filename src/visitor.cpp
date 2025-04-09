#include "pch.h"
#include "visitor.h"

#include "character.h"

#ifdef OOP_APPROACH
void JsonTranslator::visit(const NonTerminalCharacter& ch)
#else
void JsonTranslator::operator()(const NonTerminalCharacter& ch)
#endif
{
	_buf += ch.getChar();
}

#ifdef OOP_APPROACH
void JsonTranslator::visit(const TokenCharacter& ch)
#else
void JsonTranslator::operator()(const TokenCharacter& ch)
#endif
{
	_buf += static_cast<char>(ch.getChar());
}

std::string JsonTranslator::getResult() const
{
	return "{\n\t\"type\": \"Json\",\n\t\"chars\": \"" + _buf + "\"\n}\n\n";
}

#ifdef OOP_APPROACH
void XmlTranslator::visit(const NonTerminalCharacter& ch)
#else
void XmlTranslator::operator()(const NonTerminalCharacter& ch)
#endif
{
	_buf += ch.getChar();
}

#ifdef OOP_APPROACH
void XmlTranslator::visit(const TokenCharacter& ch)
#else
void XmlTranslator::operator()(const TokenCharacter& ch)
#endif
{
	_buf += static_cast<char>(ch.getChar());
}

std::string XmlTranslator::getResult() const
{
	return "<Type name=\"Xml\">\n\t<Chars>" + _buf + "</Chars>\n</Type>\n\n";
}
