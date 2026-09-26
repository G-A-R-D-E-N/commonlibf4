#pragma once

#include "Scaleform/A/Array.h"

namespace Scaleform::GFx
{
	class MemberValue;

	class MemberValueSet :
		public Array<MemberValue>
	{
	};
	static_assert(sizeof(MemberValueSet) == 0x18);
}
