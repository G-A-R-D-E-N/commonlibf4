#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/I/IUIMessageData.h"

namespace Scaleform::GFx
{
	class Event;
}

namespace RE
{
	class __declspec(novtable) BSUIScaleformData :
		public IUIMessageData  // 00
	{
	public:
		static constexpr auto RTTI{ RTTI::BSUIScaleformData };
		static constexpr auto VTABLE{ VTABLE::BSUIScaleformData };
		using SendEventFunction = void (*)(const BSFixedString&, Scaleform::GFx::Event*);

		[[nodiscard]] static SendEventFunction GetSendUIScaleformEvent();
		static void                            SendUIScaleformEvent(const BSFixedString& a_name, Scaleform::GFx::Event* a_event);

		// members
		Scaleform::GFx::Event* scaleformEvent{ nullptr };  // 18
	};
	static_assert(sizeof(BSUIScaleformData) == 0x20);
}
