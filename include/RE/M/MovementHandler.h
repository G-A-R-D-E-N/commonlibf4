#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class __declspec(novtable) MovementHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::MovementHandler };
		static constexpr auto VTABLE{ VTABLE::MovementHandler };
	};
	static_assert(sizeof(MovementHandler) == 0x20);
}
