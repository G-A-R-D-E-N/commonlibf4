#include "RE/B/BSUIScaleformData.h"

namespace RE
{
	BSUIScaleformData::SendEventFunction BSUIScaleformData::GetSendUIScaleformEvent()
	{
		static REL::Relocation<SendEventFunction> func{ ID::BSUIScaleformData::SendUIScaleformEvent };
		return func.get();
	}

	void BSUIScaleformData::SendUIScaleformEvent(const BSFixedString& a_name, Scaleform::GFx::Event* a_event)
	{
		GetSendUIScaleformEvent()(a_name, a_event);
	}
}
