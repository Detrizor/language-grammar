#include "pch.h"

#ifdef OOP_APPROACH

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

#endif
