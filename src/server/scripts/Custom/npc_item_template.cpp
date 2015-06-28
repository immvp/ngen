#include "ScriptMgr.h"
#include "ScriptedCreature.h"
#include "ScriptedGossip.h"
#include "Player.h"
#include "ScriptPCH.h"
#include "cstring"
bool EquipRPBearItem(Player* player, uint32 entry, uint32 slot)
{
	if (slot >= INVENTORY_SLOT_BAG_END)
		return false;

	// Make the item
	uint16 dest = 0;
	Item* item = Item::CreateItem(entry, 1, player);
	if (!item)
		return false;

	// Set the random prop if needed
	if (int32 randomPropertyId = Item::GenerateItemRandomPropertyId(entry))
		item->SetItemRandomProperties(1191);

	// Check that it can be equipped
	InventoryResult result = player->CanEquipItem(slot, dest, item, false);
	if (result != EQUIP_ERR_OK)
	{
		delete item;
		return false;
	}

	player->EquipItem(dest, item, true);
	return true;
}

bool EquipNewItem(Player* player, uint32 entry, uint32 slot)
{
	if (slot >= INVENTORY_SLOT_BAG_END)
		return false;

	// Make the item
	uint16 dest = 0;
	Item* item = Item::CreateItem(entry, 1, player);
	if (!item)
		return false;

	// Set the random prop if needed
	if (int32 randomPropertyId = Item::GenerateItemRandomPropertyId(entry))
		item->SetItemRandomProperties(randomPropertyId);

	// Check that it can be equipped
	InventoryResult result = player->CanEquipItem(slot, dest, item, false);
	if (result != EQUIP_ERR_OK)
	{
		delete item;
		return false;
	}

	// Add quest and achievement checks and equip the item
	player->ItemAddedQuestCheck(entry, 1);
	player->UpdateAchievementCriteria(ACHIEVEMENT_CRITERIA_TYPE_RECEIVE_EPIC_ITEM, entry, 1);
	player->EquipItem(dest, item, true);
	return true;
}

void ApplyGlyph(Player* player, uint8 slot, uint32 glyphID)
{
	if (GlyphPropertiesEntry const* gp = sGlyphPropertiesStore.LookupEntry(glyphID))
	{
		if (uint32 oldGlyph = player->GetGlyph(slot))
			player->RemoveAurasDueToSpell(sGlyphPropertiesStore.LookupEntry(oldGlyph)->SpellId);
		player->CastSpell(player, gp->SpellId, true);
		player->SetGlyph(slot, glyphID);
		player->SendTalentsInfoData(false);
	}
}

class npc_item_template : public CreatureScript
{
public:
	npc_item_template() : CreatureScript("npc_item_template") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		if (player->getClass() == CLASS_WARRIOR)
		{
			player->ADD_GOSSIP_ITEM(1, "Give me stuff!", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(1, "Nevermind.", GOSSIP_SENDER_MAIN, 2);

		}
		player->SEND_GOSSIP_MENU(player->GetGossipTextId(creature), creature->GetGUID());
		return true;

	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();
		switch (action)
		{
		case 1:
			EquipNewItem(player, 19972, 0);
			EquipNewItem(player, 42949, 2);
			EquipNewItem(player, 48689, 4);
			EquipNewItem(player, 6087, 6);
			EquipNewItem(player, 6460, 5);
			EquipNewItem(player, 12982, 7);
			EquipNewItem(player, 14147, 8);
			EquipNewItem(player, 50255, 10);
			EquipNewItem(player, 6414, 11);
			EquipNewItem(player, 19024, 12);
			EquipNewItem(player, 19024, 13);
			EquipNewItem(player, 2059, 14);
			EquipNewItem(player, 5815, 15);
			EquipNewItem(player, 29201, 17);
			EquipNewItem(player, 21933, 1);
			EquipNewItem(player, 12994, 9);
			ApplyGlyph(player, 0, 495);
			player->PlayerTalkClass->SendCloseGossip();
			break;

		case 2:
			player->PlayerTalkClass->SendCloseGossip();
			break;
		}
		return true;
	}
};

void AddSC_npc_item_template()
{
	new npc_item_template();
}
