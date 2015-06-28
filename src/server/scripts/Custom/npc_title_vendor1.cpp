#include "ScriptPCH.h"
#include "ItemEnchantmentMgr.h"
#include "Language.h"

#define H_X             -1258.48f
#define H_Y             63.53f
#define H_Z             127.9f
#define A_X             -1208.98f
#define A_Y             -88.27f
#define A_Z             161.50f
#define TOKEN           20558
#define TOKEN_COUNT     8
#define TITLE_REWARDED  47 // title "The Conqueror"
#define ELEM_COUNT      25 // Amount of enchants showed per page
#define TXT_PREV_PG     "<- Previous page"
#define TXT_GO_BACK     "<-- back to item list"
#define TXT_NEXT_PG     "Next page ->"
#define TXT_LAST_PAGE   "you reach the last page !"
#define TXT_KTHXBY      "Nevermind.."
#define TXT_BAD_SKILL   "Profession NPC: received non-valid skill ID (LearnAllRecipesInProfession)"
#define TXT_ERR_SKILL   "you already have that skill"
#define TXT_ERR_MAX     "you already know two professions!"
#define TXT_PROBLEM     "Internal error occured!"
#define TXT_SPRINT      "Make me the fastest turtle ever!"
#define TXT_GET_TITLE   "Gimi my Title !"
#define TXT_VENDOR_LIST "Show me your goodies..."
#define TXT_ERR_TITLE   "you already have the Title :)"
#define TXT_NO_FLAG     "Gimi Vendor flags plz."
#define FORMAT_END      ":20:20|t "
#define TXT_REQ_TITLE   "you need to be at least : |TInterface/PvPRankBadges/PvPRank"
#define TXT_MAX_RANK    "You've achieved the highest Rank! New ranks are introduced every Arena Season."
#define TXT_WSG_MARK    " Warsong Gulch Mark of Ranking to go! We sell the same items as the Arena Vendors do."

enum Gossip_Option_Custom
{
	CUSTOM_OPTION_NONE = 20,
	CUSTOM_OPTION_UNLEARN = 21,
	CUSTOM_OPTION_EXIT = 22,
	CUSTOM_OPTION_TITLE_PVP = 23,
	CUSTOM_OPTION_TITLE_CLIMB = 24,
	CUSTOM_OPTION_SPRINT = 25,
	GOSSIP_OPTION_HELLO = 26,
	CUSTOM_OPTION_ITEM_MENU = 27,
	CUSTOM_OPTION_ITEM_MENU_P2 = 28,
	CUSTOM_OPTION_ITEM_MENU_P3 = 29,
	CUSTOM_OPTION_ITEM_MENU_P4 = 30,
	CUSTOM_OPTION_ITEM_MENU_P5 = 31,
	CUSTOM_OPTION_ITEM_MENU_P6 = 32,
	CUSTOM_OPTION_ITEM_MENU_P7 = 33,
	CUSTOM_OPTION_ITEM_MENU_MAX = 34,
	CUSTOM_OPTION_SUFFIX = 35,
	CUSTOM_OPTION_PROPERTY = 36,
	CUSTOM_OPTION_VENDOR = 37,
	CUSTOM_OPTION_MAX
};

enum NPCs {
	NPC_ALLIANCE_LOOK_BACK = 500113,
	NPC_ALLIANCE_LOOK_ARROUND = 500114,
	NPC_HORDE_LOOK_BACK = 500115,
	NPC_HORDE_LOOK_ARROUND = 500116
};

static char   *AtitlesNames[] =
{
	"Private",
	"Corporal",
	"Sergeant",
	"Master Sergeant",
	"Sergeant Major",
	"Knight",
	"Knight Lieutenant",
	"Knight Captain",
	"Knight Champion",
	"Lieutenant Commander",
	"Commander",
	"Marshal",
	"Field Marshal",
	"Grand Marshal",
	"Battlemaster"
};

static char *HtitlesNames[] =
{
	"Scout",
	"Grunt",
	"Sergeant",
	"Senior Sergeant",
	"First Sergeant",
	"Stone Guard",
	"Blood Guard",
	"Legionnaire",
	"Centurion",
	"Champion",
	"Lieutenant General",
	"General",
	"Warlord",
	"High Warlord",
	"Battlemaster"
};

static char *Atitleicons[53] =
{
	"|TInterface\\icons\\Achievement_PVP_A_01:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_02:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_03:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_04:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_05:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_06:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_07:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_08:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_09:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_10:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_11:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_12:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_13:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_14:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_A_15:50:50:-25:0|t"
};

static char *Htitleicons[53] =
{
	"|TInterface\\icons\\Achievement_PVP_H_01:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_02:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_03:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_04:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_05:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_06:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_07:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_08:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_09:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_10:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_11:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_12:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_13:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_14:50:50:-25:0|t",
	"|TInterface\\icons\\Achievement_PVP_H_15:50:50:-25:0|t"
};

uint32 titlecost[15] =
{
	// oki bois
	1,
	2,
	3,
	4,
	5,
	6,
	7,
	8,
	9,
	10,
	11,
	12,
	13,
	14,
	15 // Oki så de her changer du til de prices som du gerne vil have så 1 er self rank 1 2 er rank 2 etc.et
};

class npc_title_giver1 : public CreatureScript
{
public:
	npc_title_giver1() : CreatureScript("npc_title_giver1") {}

	void RewardTitles(Player *player, uint8 *nextTitle, const uint16 totalTokens, const uint8 faction)
	{
		while ((*nextTitle <= 15) && titlecost[*nextTitle] <= totalTokens)
		{
			(*nextTitle)++;
			if (*nextTitle == 15)
				player->SetTitle(sCharTitlesStore.LookupEntry(72));
			else
			{
				if (*nextTitle >= 16)
					return;
				else
					player->SetTitle(sCharTitlesStore.LookupEntry(*nextTitle + faction));
			}
		}
	}

	const char *GetNextTitleName(const uint8 nextTitle, const uint16 totalTokens, Player* player)
	{
		std::ostringstream  ss;

		if (nextTitle > 14 && player->GetTeam() == ALLIANCE)
			ss << "|TInterface\\icons\\Achievement_PVP_A_15:50:50:-25:0|tYou've achieved the highest Rank! New ranks are introduced every Arena Season.";
		else if (nextTitle > 14 && player->GetTeam() == HORDE)
			ss << "|TInterface\\icons\\Achievement_PVP_H_15:50:50:-25:0|tYou've achieved the highest Rank! New ranks are introduced every Arena Season.";
		else
		{
			if (player->GetTeam() == ALLIANCE)
				ss << Atitleicons[nextTitle] << "Next title: ";
			else
				ss << Htitleicons[nextTitle] << "Next title: ";
			if (nextTitle < 9)
				ss << '0';
			if (player->GetTeam() == ALLIANCE)
			{
				ss << 1 + nextTitle << "|cff8A0886" << AtitlesNames[nextTitle] << "|r";
				ss << " in " << titlecost[nextTitle] - totalTokens << " tokens.";
			}
			else
			{
				ss << 1 + nextTitle << "|cff8A0886" << HtitlesNames[nextTitle] << "|r";
				ss << " in " << titlecost[nextTitle] - totalTokens << " tokens.";
			}
		}
		return (ss.str().c_str());
	}

	bool OnGossipHello(Player* player, Creature* me)
	{
		const uint16  totalTokens = player->GetTotalTokens(player);
		const uint8   faction = (player->GetTeam() == ALLIANCE) ? 0 : 14;
		uint8         nextTitle = 0;


		RewardTitles(player, &nextTitle, totalTokens, faction);
		const char *gossipText = GetNextTitleName(nextTitle, totalTokens, player);
		player->PlayerTalkClass->ClearMenus();
		player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, gossipText, GOSSIP_SENDER_MAIN, CUSTOM_OPTION_EXIT);
		player->ADD_GOSSIP_ITEM(1, TXT_KTHXBY, GOSSIP_SENDER_MAIN, CUSTOM_OPTION_EXIT);
		player->PlayerTalkClass->SendGossipMenu(9425, me->GetGUID());
		return (true);
	}

	bool OnGossipSelect(Player* player, Creature* /*me*/, uint32 /*uiSender*/, uint32 /*uiAction*/)
	{
		player->PlayerTalkClass->SendCloseGossip();
		return (true);
	}
};
void AddSC_title_system1()
{
	new npc_title_giver1();
}