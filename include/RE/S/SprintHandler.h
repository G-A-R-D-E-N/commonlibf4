#pragma once

#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class __declspec(novtable) SprintHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::SprintHandler };
		static constexpr auto VTABLE{ VTABLE::SprintHandler };

		std::uint16_t unk20;
	};
	static_assert(sizeof(SprintHandler) == 0x28);
}
