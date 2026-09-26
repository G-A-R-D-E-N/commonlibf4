# CommonLib RE Research

I went through the active CommonLibF4 forks and a few related FO4 projects to see what data we are missing.

This file is just keeping track of what we already pulled in, what GARDEN already had, and what still needs more checking. I am not adding runtime IDs just because another repo has them. If OG/NG/AE do not line up yet, it stays here until they do.

## Pulled in

### NiMatrix3::IDENTITY

Source: DCCStudios/commonlibf4 commit `795ee8683f2c4573128d3d444174ec3612e10de6`

This was just wrong in our fork.

All three rows were using `NiPoint4::IDENTITY0`.

Fixed it to:

- `IDENTITY0`
- `IDENTITY1`
- `IDENTITY2`

### NiObjectNET extra data

Source: Gistix/commonlibf4 commit `8321a127e7a207c9dd3914c2b2c11c68e056d842`

Pulled in:

- fix the backwards name check
- set the key when the extra data has no name
- reject a conflicting name
- reject null input
- create the extra-data container if it does not exist yet

### TESLeveledList count fields

Sources:

- hxef/CommonLibF4 commit `65e6922adb0d7d1d01cdde6882902d17f650b118`
- libxse PR #68
- LucaDotGit/CommonLibF4

These are unsigned bytes, not signed:

- `scriptListCount`
- `baseListCount`
- `maxUseAllCount`

Two separate CommonLib branches agree on this.

### TESDataHandler load functions

Source: Dear-Modding-FO4/Addictol

Added:

| Function | OG | NG/AE |
| --- | ---: | ---: |
| `TESDataHandler::CompileFiles(bool)` | `57137` | `2192321` |
| `TESDataHandler::ConstructObjectList(TESFile*, bool)` | `1043280` | `2192326` |
| `TESDataHandler::InitAllForms()` | `189223` | `2192344` |

Addictol is already validating these targets against the actual function signatures before hooking them, so this is a lot better than just copying IDs out of a table.

## Pulled in from this research pass

### Save/load manager

Added the missing native save/load calls that matched between the local RE reference and Luca's multi-runtime fork.

Sources:

- [commonlib_NonVR BGSSaveLoadManager](https://git.nomadicinteractive.dev/ReverseEng/commonlib_NonVR/src/branch/main/include/RE/B/BGSSaveLoadManager.h)
- [Luca BGSSaveLoadManager implementation](https://github.com/LucaDotGit/CommonLibF4/blob/main/src/RE/B/BGSSaveLoadManager.cpp)
- [Luca runtime IDs](https://github.com/LucaDotGit/CommonLibF4/blob/main/include/RE/IDs.hpp)

Added:

- `BufferSceneScreenShot`
- `GetFullPath`
- `IsLoadingAllowed`
- `IsSavingAllowed`
- `Quickload`
- `Quicksave`
- `DeleteSaveFileImpl`
- `GenerateSaveFileNameImpl`
- `LoadGameImpl`
- `SaveGameImpl`

I left the autosave wrapper alone because the two sources expose the same target with different wrapper semantics.

### Inventory serialization

Added the inventory item, stack, and inventory-list save/load functions from the runtime RE work.

Sources:

- [commonlib_NonVR inventory item](https://git.nomadicinteractive.dev/ReverseEng/commonlib_NonVR/src/branch/main/include/RE/B/BGSInventoryItem.h)
- [commonlib_NonVR inventory list](https://git.nomadicinteractive.dev/ReverseEng/commonlib_NonVR/src/branch/main/include/RE/B/BGSInventoryList.h)
- [runtime RE findings](https://git.nomadicinteractive.dev/ReverseEng/commonlib_NonVR/src/branch/main/RE-Work/Runtime/03-FINDINGS.md)

The runtime notes include the OG and AE RVAs used to verify these IDs.

### Character tinting

Added the two tint setters where frakkin and Luca agree on the same runtime targets:

- `PlayerCharacter::SetTintingData`
- `TESNPC::SetTintingData`

Sources:

- [frakkin tint/head-part commit](https://github.com/frakkin64/commonlibf4/commit/32eec000d87bad4c93d438a835fd6f989bfabbc9)
- [Luca PlayerCharacter implementation](https://github.com/LucaDotGit/CommonLibF4/blob/main/src/RE/P/PlayerCharacter.cpp)
- [Luca TESNPC implementation](https://github.com/LucaDotGit/CommonLibF4/blob/main/src/RE/T/TESNPC.cpp)
- [Luca runtime IDs](https://github.com/LucaDotGit/CommonLibF4/blob/main/include/RE/IDs.hpp)

The other frakkin tint/head-part functions are still single-source, so I did not add them yet.

### Texture loading

Added the texture functions where the signatures from alandtse line up with the runtime IDs in `commonlib_NonVR`:

- `BSGraphics::LoadTextureData`
- the three `NiTexture::Create` overloads

Sources:

- [alandtse BSGraphics](https://github.com/alandtse/CommonLibF4/blob/master/CommonLibF4/include/RE/Bethesda/BSGraphics.h)
- [alandtse NiTexture](https://github.com/alandtse/CommonLibF4/blob/master/CommonLibF4/include/RE/NetImmerse/NiTexture.h)
- [commonlib_NonVR runtime IDs](https://git.nomadicinteractive.dev/ReverseEng/commonlib_NonVR/src/branch/main/include/RE/IDs.h)

The render-target manager and external Scaleform texture functions are still only backed by the local reference in this pass, so they stay out for now.

## Already in GARDEN

I checked these and we already have them:

- `CombatFormulas::CalcWeaponDamage` OG ID `651643`
- `bhkPickData::GetHitFraction` NG/AE ID `2277771`
- fixed `MenuTopicManager::Singleton`
- `hkMemoryRouter::tlsSlotID` NG/AE ID `2787927`
- `DialogueMenuUtils::ShowButtons`
- `Actor::PlaySoundByEditorName`
- `MenuControls::ForcePauseGame`
- `MenuControls::ForceResumeGame`
- `MenuControls::RegisterHandler`
- `MenuControls::UnregisterHandler`
- fixed `BSSoundHandle::Play`
- initialized `BSSoundHandle` state
- `BGSAudio::GetUIOutputModel`
- runtime-specific console function count
- Gistix OG IDs for terrain, audio, culling, LOD roots, Pip-Boy map data, player animation, TES visibility, and map coordinates
- frakkin64 pathing and quest data
- powerof3 save/load data
- `BSTempEffectWeaponBlood::ClearEffectForWeapon`
- `ActorState::IsSwimming`
- `BGSDecalNode`
- `MainMenu`

So there is no reason to pull any of that in again.

## Still needs work

### BGSDefaultObjectManager::Singleton

This one is still messy.

Different repos disagree on what this actually is.

- GARDEN/Luca: callable singleton getter, old NG/AE ID `2192850`
- DCCStudios: callable getter at `2192468`
- hxef/libxse PR #68: direct singleton data at `4796209`

I am not touching this until we prove what OG, NG, and AE are actually doing.

### BSAudioManager::GetSoundHandleByFile

DCCStudios commit:

`12beba2a89fe117a14f1707b88c99ecb1b12f8c0`

They say the CK PDB shows a fifth argument:

`const char* a_fileName`

GARDEN and Luca still use four arguments.

This looks believable, but it changes the public function signature, so I want another check before pulling it in.

### Pip-Boy SortItems

libxse PR #67 has:

- `PipboyInventoryData::SortItems` = `2225244`
- `PipboyInventoryMenu::SortItems` = `2224164`

Those are AE IDs.

Still need OG IDs.

### libxse PR #68

This PR has a lot of good 1.11.240 RE in it, but most of the IDs are AE-only right now.

Things worth pulling once we find OG mappings:

| Binding | AE ID |
| --- | ---: |
| `MagicCaster::Cast` | `2226296` |
| `Actor::GetEquippedItemHealth` | `2231099` |
| `Actor::OnMagazineEmpty` | `2231137` |
| `BGSAudio::PlaySoundDescriptor` | `2214755` |
| `BGSInventoryList::AddStack` | `2194191` |
| `BipedAnim::SetObjectGraphVariableInt` | `2194367` |
| `Console::RunQueuedCommands` | `2248538` |
| `Explosion::ProcessTargets` | `2236664` |
| `GamePlayFormulas::CalculateItemValue` | `2209074` |
| `HitData::ApplyDamageTypes` | `2236861` |
| `InventoryUserUIUtils::PopulateItemCardInfo_Helper` | `2222625` |
| `BGSLocalizedStringIL::LookupByID` | `2194243` |
| `HUDQuickContainerDataModel::AddItemRows` | `2221647` |
| `LoadingMenu::CollectLoadScreens` | `2249240` |
| `MessageMenuManager::QueueMessage` | `2249457` |

It also adds:

- `MagicCaster`
- `ActorMagicCaster`
- `ExtraMagicCaster`
- `NonActorMagicCaster`
- `HUDComponentBase`
- `HUDQuickContainerDataModel`
- message-box layout fixes
- more 1.11.240 layout/type fixes

I do not want to pretend those layouts are the same on OG/NG until we actually verify them.

### frakkin64

They have three files we do not have yet:

- `BSFaceGenAnimationData`
- `BSFaceGenNiNode`
- `Stars`

We already have NiRTTI IDs for the first two, but the full RTTI/VTABLE data is not there yet.

`Stars` is also missing the generated IDs needed to make it a clean addition.

They also split `TESClimate::data[6]` into actual named fields for sunrise, sunset, volatility, and moon data.

That is useful, but I only found one source for it so far.

### alandtse texture functions

They have some useful texture stuff:

- `BSGraphics::CreateTexture`
- `BSGraphics::LoadTextureData`
- `BSScaleformExternalTexture::SetTexture`
- `BSScaleformExternalTexture::ReleaseTexture`
- multiple `NiTexture::Create` overloads

The problem is those use older raw IDs instead of our OG/NG/AE mapping.

Need to map them properly before pulling them in.

## Repos checked

- G-A-R-D-E-N/commonlibf4
- Dear-Modding-FO4/commonlibf4
- libxse/commonlibf4
- DCCStudios/commonlibf4
- Gistix/commonlibf4
- frakkin64/commonlibf4
- LucaDotGit/CommonLibF4
- alandtse/CommonLibF4
- powerof3/CommonLibF4
- Ryan-rsm-McKenzie/CommonLibF4
- hxef/CommonLibF4
- FalloutCascadia/CommonLibF4
- Dear-Modding-FO4/Addictol
