#include "pch.h"
#include "character.h"

#include "visitor.h"

void NonTerminalCharacter::accept(Visitor& visitor) const
{
	visitor.visit(*this);
}

void TokenCharacter::accept(Visitor& visitor) const
{
	visitor.visit(*this);
}
