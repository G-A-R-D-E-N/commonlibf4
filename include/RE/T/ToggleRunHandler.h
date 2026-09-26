#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class __declspec(novtable) ToggleRunHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::ToggleRunHandler };
		static constexpr auto VTABLE{ VTABLE::ToggleRunHandler };
	};
	static_assert(sizeof(ToggleRunHandler) == 0x20);
}
