// #include "ScriptPCH.h"
// #include "Chat.h"
// #include "ArenaTeamMgr.h"
// #include "BattlegroundMgr.h"
// #include "WorldSession.h"
// #include "Player.h"
// #include "ArenaTeam.h"
// #include "Battleground.h"
// #include "BattlegroundMgr.h"
// #include "CreatureTextMgr.h"
// #include "Config.h"
// 
// enum NpcSpectatorAtions
// {
//     GOSSIP_ACTION_SHOW_MENU       = 100,
//     // GOSSIP_ACTION + ArenaTeamType
//     GOSSIP_ACTION_SHOW_GAMES_PAGE = 500,
//     GOSSIP_ACTION_SHOW_GAMES      = 1000,
//     GOSSIP_ACTION_TOP          = 2000,
//     // GOSSIP_ACTION + ArenaTeamType, sender = teamId
//     GOSSIP_ACTION_DETAIL_ON_TEAM  = 3000,
//     // GOSSIP_ACTION + ArenaTeamType, sender = playerGuid
//     GOSSIP_ACTION_DETAIL_ON_GAME  = 4000,
//     // GOSSIP_ACTION + playerGuid
//     GOSSIP_ACTION_SPECTATE        = 5000,
// };
// 
// #define MAX_PER_PAGE 15
// 
// class npc_arena_spectator : public CreatureScript
// {
// public:
//     npc_arena_spectator() : CreatureScript("npc_arena_spectator") { }
// 
//     bool OnGossipHello(Player* player, Creature* me)
//     {
//         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Ladder Menu :", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SHOW_MENU);
//         GetTopMenuByType(player, ARENA_TEAM_2v2);
//         GetTopMenuByType(player, ARENA_TEAM_3v3);
//         GetTopMenuByType(player, ARENA_TEAM_5v5);
//         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Spectate Menu :", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SHOW_MENU);
//         GetSpecateMenuByType(player, ARENA_TEAM_2v2);
//         GetSpecateMenuByType(player, ARENA_TEAM_3v3);
//         GetSpecateMenuByType(player, ARENA_TEAM_5v5);
// 
//         player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
//         return true;
//    	}
// 
//     void GetTopMenuByType(Player* player, const uint8 type)
//     {
//         std::stringstream ss;
//         ss << "|TInterface\\icons\\Achievement_Arena_" << (int)type << 'v' << (int)type << "_6:42|t Show the " << (int)type << 'v' << (int)type << " Top teams list";
//         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, ss.str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_TOP + type);
//     }
// 
//     void GetSpecateMenuByType(Player* player, const uint8 type)
//     {
//         std::stringstream ss;
//         uint32 action;
//         ss << "|TInterface\\icons\\Achievement_Arena_" << (int)type << 'v' << (int)type << '_';
//         const uint16 count = ListActiveArena(player, 0, true, type);
//         if (count == 1)
//         {
//             ss << "7:42|t Only one game avaible in " << (int)type << 'v' << (int)type;
//             action = GOSSIP_ACTION_SHOW_GAMES + type;
//         }
//         else if (count)
//         {
//             ss << "7:42|t Browse the " << (int)count << " games of " << (int)type << 'v' << (int)type;
//             action = GOSSIP_ACTION_SHOW_GAMES + type;
//         }
//         else
//         {
//             ss << urand(1, 4) << ":42|t " << (int)type << 'v' << (int)type << " : No games, click to refresh.";
//             action = GOSSIP_ACTION_SHOW_MENU;
//         }
//         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, ss.str(), GOSSIP_SENDER_MAIN, action);
//     }
// 
//     bool OnGossipSelect(Player* player, Creature* me, uint32 data, uint32 action)
//     {
//         player->PlayerTalkClass->ClearMenus();
// 
//         if (action >= GOSSIP_ACTION_SPECTATE)
//         {
//             if (Player* target = ObjectAccessor::FindPlayer(action - GOSSIP_ACTION_SPECTATE))
//             {
//                 ChatHandler handler(player->GetSession());
//                 char const* pTarget = target->GetName().c_str();
//                 m_usingGossip = true;
//                 arena_spectator_commands::HandleSpectateCommand(&handler, pTarget);
//                 return true;
//             }
//         }
//         else if (action >= GOSSIP_ACTION_DETAIL_ON_TEAM)
//             ShowTeamInfo(player, data, action - GOSSIP_ACTION_DETAIL_ON_TEAM);
//         else if (action >= GOSSIP_ACTION_TOP)
//             ListTopArena(player, action - GOSSIP_ACTION_TOP);
//         else if (action >= GOSSIP_ACTION_SHOW_GAMES)
//             ListActiveArena(player, 0, false, action - GOSSIP_ACTION_SHOW_GAMES);
//         else if (action >= GOSSIP_ACTION_SHOW_GAMES_PAGE) // data is for the page here
//             ListActiveArena(player, data, false, action - GOSSIP_ACTION_SHOW_GAMES_PAGE);
//         else
//         {
//             OnGossipHello(player, me);
//             return true;
//         }
//         player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, me->GetGUID());
//         return true;
//     }
// 
//     std::string GetClassColorById(uint8 id)
//     {
//         std::string sClass = "";
//         switch (id)
//         {
//             case CLASS_WARRIOR:
//                 sClass = "|cffC79C6E";
//                 break;
//             case CLASS_PALADIN:
//                 sClass = "|cffF58CBA";
//                 break;
//             case CLASS_HUNTER:
//                 sClass = "|cffABD473";
//                 break;
//             case CLASS_ROGUE:
//                 sClass = "|cffFFF569";
//                 break;
//             case CLASS_PRIEST:
//                 sClass = "|cffFFFFFF";
//                 break;
//             case CLASS_DEATH_KNIGHT:
//                 sClass = "|cffC41F3B";
//                 break;
//             case CLASS_SHAMAN:
//                 sClass = "|cff0070DE";
//                 break;
//             case CLASS_MAGE:
//                 sClass = "|cff69CCF0";
//                 break;
//             case CLASS_WARLOCK:
//                 sClass = "|cff9482C9";
//                 break;
//             case CLASS_DRUID:
//                 sClass = "|cffFF7D0A";
//                 break;
//         }
//         return sClass;
//     }
// 
// //Interface\BUTTONS\UI-GroupLoot-Dice-Up.blp //Interface\BUTTONS\UI-GroupLoot-Dice-Up.blp
//     std::string GetRankIcon(const int32 rating)
//     {
//         if (rating < 0) // skirmish
//             return (std::string("|TInterface\\BUTTONS\\UI-GroupLoot-Dice-Up:26|t"));
// 
//         uint8 iconID = 1;
//         for (uint16 min = 1000; iconID < 15 && rating > min; min += 100)
//             iconID++;
// 
//         std::stringstream ss;
//         ss << "|TInterface\\PvPRankBadges\\PvPRank";
//         if (iconID < 10)
//             ss << '0';
//         ss << (int)iconID << ":26|t";
//         return ss.str();
//     }
// 
//     std::string GetClassIconById(uint8 id)
//     {
//         std::string sClass = "";
//         switch (id)
//         {
//             case CLASS_WARRIOR:
//                 sClass = "|TInterface\\icons\\Inv_sword_27:26|t";
//                 break;
//             case CLASS_PALADIN:
//                 sClass = "|TInterface\\icons\\Ability_thunderbolt:26|t";
//                 break;
//             case CLASS_HUNTER:
//                 sClass = "|TInterface\\icons\\Inv_weapon_bow_07:26|t";
//                 break;
//             case CLASS_ROGUE:
//                 sClass = "|TInterface\\icons\\Inv_throwingknife_04:26|t";
//                 break;
//             case CLASS_PRIEST:
//                 sClass = "|TInterface\\icons\\Inv_staff_30:26|t";
//                 break;
//             case CLASS_DEATH_KNIGHT:
//                 sClass = "|TInterface\\CharacterFrame\\Button_ClassIcon_DeathKnight:26|t";
//                 break;
//             case CLASS_SHAMAN:
//                 sClass = "|TInterface\\icons\\Spell_nature_bloodlust:26|t";
//                 break;
//             case CLASS_MAGE:
//                 sClass = "|TInterface\\icons\\Inv_staff_13:26|t";
//                 break;
//             case CLASS_WARLOCK:
//                 sClass = "|TInterface\\icons\\Spell_nature_drowsy:26|t";
//                 break;
//             case CLASS_DRUID:
//                 sClass = "|TInterface\\icons\\inv_misc_monsterclaw_04:26|t";
//                 break;
//         }
//         return sClass;
//     }
// 
//     inline bool IsValidArenaType(uint8 type)
//     {
//         switch (type)
//         {
//             case ARENA_TEAM_2v2:
//             case ARENA_TEAM_3v3:
//             case ARENA_TEAM_5v5:
//                 return true;
//             default:
//                 return false;
//         }
//     }
// 
//     void ShowTeamInfo(Player* player, uint32 teamId, uint8 type)
//     {
//         const uint32 action = IsValidArenaType(type) ? GOSSIP_ACTION_TOP + type : GOSSIP_ACTION_SHOW_MENU;
//         ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(teamId);
//         if (!at)
//         {
//             player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Team not found, click to return.", GOSSIP_SENDER_MAIN, action);
//             return;
//         }
//         std::
//         stringstream ss;
//         const ArenaTeamStats stats = at->GetStats();
//         // build team info msg
//         ss << "Rank: " << stats.Rank << " - " << at->GetName() << '\n';
//         ss << "Rating: " << stats.Rating << '\n';
// //        ss << "Average MMR: " << at->GetAverageMMR() << '\n';
//         ss << "Week Games: " << stats.WeekGames << '\n';
//         ss << "Week Wins: " << stats.WeekWins << '\n';
// 
//         ss << "Season Games: " << stats.SeasonGames << '\n';
//         ss << "Season Wins: " << stats.SeasonWins << '\n';
//         // send gossip
//         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, ss.str(), GOSSIP_SENDER_MAIN, action);
// 
//         for (ArenaTeam::MemberList::iterator itr = at->m_membersBegin(); itr != at->m_membersEnd(); ++itr)
//         {
//             ss.str(std::string());
//             ss << GetClassIconById(itr->Class) << ' ' << itr->Name << " (" << itr->PersonalRating << "), MMR: " << itr->MatchMakerRating;
//             player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, ss.str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SPECTATE + itr->Guid);
//         }
//         if (at->IsFighting())
//         {
//             for (ArenaTeam::MemberList::iterator itr = at->m_membersBegin(); itr != at->m_membersEnd(); ++itr)
//             {
//                 if (Player* member = ObjectAccessor::FindPlayer(itr->Guid))
//                 {
//                     if (!member->isSpectator() && member->InArena())
//                     {
//                         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Team is playing, spectate now !", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SPECTATE + itr->Guid);
//                         break;
//                     }
//                 }
//             }
//         }
// 
//         //GetChanceAgainst()
//     }
// 
//     std::string GetGamesStringData(Battleground* arena)
//     {
//         std::stringstream ss;
//         for (Battleground::BattlegroundPlayerMap::const_iterator itr = arena->GetPlayers().begin(); itr != arena->GetPlayers().end(); ++itr)
//         {
//             if (Player* player = ObjectAccessor::FindPlayer(itr->first))
//             {
//                 if (player->isSpectator())
//                     continue;
//                 ss << GetClassIconById(player->getClass());
//             }
//         }
//         return ss.str();
//     }
// 
//     std::string GetGameIcons(Battleground* arena)
//     {
//         std::string teamsMember[BG_TEAMS_COUNT];
//         for (Battleground::BattlegroundPlayerMap::const_iterator itr = arena->GetPlayers().begin(); itr != arena->GetPlayers().end(); ++itr)
//         {
//             if (Player* player = ObjectAccessor::FindPlayer(itr->first))
//             {
//                 if (!player->isSpectator())
//                     teamsMember[player->GetTeamId()] += GetClassIconById(player->getClass());
//             }
//         }
//         if (arena->isRated())
//             return GetRankIcon(arena->GetArenaMatchmakerRatingByIndex(0)) + teamsMember[0] + "  |TInterface\\RAIDFRAME\\UI-RaidFrame-Threat:26|t  " + teamsMember[1] + GetRankIcon(arena->GetArenaMatchmakerRatingByIndex(1));
//         return GetRankIcon(-1) + teamsMember[0] + "  |TInterface\\RAIDFRAME\\UI-RaidFrame-Threat:26|t  " + teamsMember[1] + GetRankIcon(-1);
//     }
// 
//     uint64 GetFirstPlayerGuid(Battleground* arena)
//     {
//         for (Battleground::BattlegroundPlayerMap::const_iterator itr = arena->GetPlayers().begin(); itr != arena->GetPlayers().end(); ++itr)
//         {
//             if (ObjectAccessor::FindPlayer(itr->first))
//                 return itr->first;
//         }
//         return 0;
//     }
// 
//     uint16 ListActiveArena(Player* player, uint16 page, bool ammountOnly, const uint8 type)
//     {
//         uint16 elemCount = 0;
//         bool haveNextPage = false;
//         if (!ammountOnly)
//             player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "<- return to menu", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SHOW_MENU);
//         for (uint8 i = 0; i <= MAX_BATTLEGROUND_TYPE_ID; ++i)
//         {
//             if (!sBattlegroundMgr->IsArenaType(BattlegroundTypeId(i)))
//                 continue;
// 
//             const BattlegroundContainer arenas = sBattlegroundMgr->GetBattlegroundsByType(BattlegroundTypeId(i));
// 
//             if (arenas.empty())
//                 continue;
// 
//             for (BattlegroundContainer::const_iterator itr = arenas.begin(); itr != arenas.end(); ++itr)
//             {
//                 Battleground* arena = itr->second;
// 
//                 if (!arena->GetPlayersSize())
//                     continue;
// 
//                 if (type != arena->GetArenaType())
//                     continue;
// 
//                 elemCount++;
// 
//                 if (ammountOnly)
//                     continue;
// 
//                 if (elemCount > (page + 1) * MAX_PER_PAGE)
//                 {
//                     haveNextPage = true;
//                     break;
//                 }
//                 //std::stringstream ss;
// 
//                 //if (ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(bg->GetArenaTeamIdByIndex(type)))
//                 //    ss << at->GetName();
// 
//                 if (!page || elemCount >= page * MAX_PER_PAGE)
//                     player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, GetGameIcons(arena), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SPECTATE + GetFirstPlayerGuid(arena));
//             }
//         }
// 
//         if (!ammountOnly)
//         {
//             if (page > 0)
//                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Prev..",  page - 1, GOSSIP_ACTION_SHOW_GAMES_PAGE + type);
// 
//             if (haveNextPage)
//                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Next..", page + 1, GOSSIP_ACTION_SHOW_GAMES_PAGE + type);
//         }
//         return elemCount;
//     }
// 
//     void ListTopArena(Player* player, const uint8 type)
//     {
//         // first give a return option
//         player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "<- return to menu", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SHOW_MENU);
// 
//         uint8 rank = 0;
//         while (rank < MAX_TOP)
//         {
//             std::stringstream ss;
//             const uint32 teamId = sBattlegroundMgr->GetTopArenaTeamByRank(type, rank);
//             rank++;
//             if (!teamId)
//             {
//                 if (!rank)
//                 {
//                     player->GetSession()->SendNotification("Arena teams not found...");
//                     player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, "Arena teams not found...", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SHOW_MENU);
//                 }
//                 else
//                 {
//                     ss << "Only " << (int)rank << " team";
//                     if (rank > 1)
//                         ss << 's';
//                     ss << " found."; 
//                     player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, ss.str(), GOSSIP_SENDER_MAIN, GOSSIP_ACTION_SHOW_MENU);
//                 }
//                 return;
//             }
// 
//             ss << "|TInterface\\PvPRankBadges\\PvPRank";
//             if (rank > 5)
//                 ss << '0';
//             ss << MAX_TOP - (rank - 1) << ":18|t ";
//             if (ArenaTeam* at = sArenaTeamMgr->GetArenaTeamById(teamId))
//             {
//                 int8 crop = 27;
//                 if (at->IsFighting())
//                 {
//                     ss << "(Fighting) ";
//                     crop = 18;
//                 }
//                 std::string name = at->GetName();
//                 if (name.length() < crop + 1)
//                     ss << at->GetRating() << " - " << name;
//                 else
//                 {
//                     name.erase(crop, std::string::npos);
//                     ss << at->GetRating() << " - " << name << "...";
//                 }
//             }
//             else
//                 ss << "couldn't get arena team stats.";
// 
//             player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT, ss.str(), teamId, GOSSIP_ACTION_DETAIL_ON_TEAM + type);
//         }
//     }
// 
// };
// 
// 
// void AddSC_arena_spectator_script()
// {
//     new arena_spectator_commands();
//     new npc_arena_spectator();
// }