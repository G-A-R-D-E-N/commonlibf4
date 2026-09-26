#pragma once

#include "Scaleform/G/GFx_Value.h"
#include "Scaleform/S/String.h"

namespace Scaleform::GFx
{
	class MemberValue
	{
	public:
		String name;
		Value  value;
	};
	static_assert(sizeof(MemberValue) == 0x28);
}
