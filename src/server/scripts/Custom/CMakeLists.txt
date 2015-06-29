# Copyright (C) 2008-2014 TrinityCore <http://www.trinitycore.org/>
#
# This file is free software; as a special exception the author gives
# unlimited permission to copy and/or distribute it, with or without
# modifications, as long as this notice is preserved.
#
# This program is distributed in the hope that it will be useful, but
# WITHOUT ANY WARRANTY, to the extent permitted by law; without even the
# implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.

# file(GLOB_RECURSE sources_Custom Custom/*.cpp Custom/*.h)

set(scripts_STAT_SRCS
  ${scripts_STAT_SRCS}
#  ${sources_Custom}
Custom/player_commands.cpp
Custom/world_chat.cpp
Custom/npc_top_arena.cpp
Custom/npc_profession.cpp
Custom/npc_suffixvendor.cpp
Custom/npc_beastmaster.cpp
Custom/npc_profession2.cpp
Custom/npc_enchanter.cpp
Custom/npc_glyph_template.cpp
Custom/npc_item_template.cpp
Custom/npc_title_vendor.cpp
Custom/npc_talentspec.cpp
Custom/npc_heal.cpp
Custom/npc_changer.cpp
Custom/go_respawn.cpp
Custom/npc_title_vendor1.cpp
Custom/FastArenaCrystal.cpp
Custom/npc_templatenew.cpp
)

message("  -> Prepared: Custom")
