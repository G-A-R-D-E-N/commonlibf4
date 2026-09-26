#pragma once

#include "RE/B/BSFixedString.h"
#include "RE/N/NiPointer.h"

namespace RE
{
	class NiTexture;

	class BSScaleformExternalTexture
	{
	public:
		bool SetTexture(NiTexture* a_texture)
		{
			using func_t = decltype(&BSScaleformExternalTexture::SetTexture);
			static REL::Relocation<func_t> func{ ID::BSScaleformExternalTexture::SetTexture };
			return func(this, a_texture);
		}

		void ReleaseTexture()
		{
			using func_t = decltype(&BSScaleformExternalTexture::ReleaseTexture);
			static REL::Relocation<func_t> func{ ID::BSScaleformExternalTexture::ReleaseTexture };
			return func(this);
		}

		// members
		NiPointer<NiTexture> gamebryoTexture;  // 00
		std::uint32_t        renderTarget;     // 08
		BSFixedString        texturePath;      // 10
	};
	static_assert(sizeof(BSScaleformExternalTexture) == 0x18);
}
