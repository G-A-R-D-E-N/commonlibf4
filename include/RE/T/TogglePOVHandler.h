#pragma once

#include "RE/B/BSInputEnableLayer.h"
#include "RE/B/BSTSmartPointer.h"
#include "RE/P/PlayerInputHandler.h"

namespace RE
{
	class __declspec(novtable) TogglePOVHandler :
		public PlayerInputHandler
	{
	public:
		static constexpr auto RTTI{ RTTI::TogglePOVHandler };
		static constexpr auto VTABLE{ VTABLE::TogglePOVHandler };

		std::uint16_t                                                         unk20;
		BSTSmartPointer<BSInputEnableLayer, BSTSmartPointerIntrusiveRefCount> inputEnableLayer;
		bool                                                                  povButtonHeld;
		bool                                                                  nearWorkshop;
	};
	static_assert(sizeof(TogglePOVHandler) == 0x38);
}
