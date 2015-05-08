

enum Enchants
{
	ENCHANT_WEP_FIERY = 803,
	ENCHANT_WEP_ICEY = 1894,
	ENCHANT_WEP_SPELLPOWER = 2504,
	ENCHANT_WEP_SPIRIT = 2567,
	ENCHANT_WEP_CRUSADER = 1900,
	ENCHANT_WEP_AGILITY1H = 2564,
	ENCHANT_WEP_LIFESTEALING = 1898,
	ENCHANT_WEP_STRENGTH = 2563,
	ENCHANT_WEP_INTELLECT = 2568,
	ENCHANT_WEP_DAMAGE = 1897,
	ENCHANT_2WEP_FIERY = 803,
	ENCHANT_2WEP_ICEY = 1894,
	ENCHANT_2WEP_CRUSADER = 1900,
	ENCHANT_2WEP_SPELLPOWER = 2504,
	ENCHANT_2WEP_AGILITY = 2646,
	ENCHANT_2WEP_LIFESTEALING = 1898,
	ENCHANT_2WEP_DAMAGE = 1896,
	ENCHANT_2WEP_HASTE = 34,

	ENCHANT_SHIELD_PROTECTION = 848,
	ENCHANT_SHIELD_VITALITY = 1890,
	ENCHANT_SHIELD_BLOCK = 1984,
	ENCHANT_SHIELD_SPIKE = 2714,
	ENCHANT_SHIELD_SPIRIT = 4741,
	ENCHANT_SHIELD_STAM = 929,

	ENCHANT_CLOAK_DODGE = 2622,
	ENCHANT_CLOAK_ARMOR = 1889,
	ENCHANT_CLOAK_SUBLETY = 2621,
	ENCHANT_CLOAK_FIRE = 2619,
	ENCHANT_CLOAK_AGILITY = 2893,
	ENCHANT_CLOAK_STEALTH = 910,
	ENCHANT_CLOAK_NATURE = 2620,
	ENCHANT_CLOAK_RESIST = 1888,
	ENCHANT_CLOAK_SHADOW = 804,

	ENCHANT_GLOVES_STRENGTH = 927,
	ENCHANT_GLOVES_HASTE = 931,
	ENCHANT_GLOVES_SHADOW = 2614,
	ENCHANT_GLOVES_HEALING = 2320,
	ENCHANT_GLOVES_AGILITY = 883,
	ENCHANT_GLOVES_FIRE = 2616,
	ENCHANT_GLOVES_FROST = 2615,

	ENCHANT_BRACERS_INTELLECT = 1883,
	ENCHANT_BRACERS_STAM = 1885,
	ENCHANT_BRACERS_STRENGTH = 1886,
	ENCHANT_BRACERS_MP = 2565,
	ENCHANT_BRACERS_DEFLECTION = 923,
	ENCHANT_BRACERS_HEALING = 2319,
	ENCHANT_BRACERS_AGILITY = 247,

	ENCHANT_CHEST_ABSORB = 63,
	ENCHANT_CHEST_MANA = 1893,
	ENCHANT_CHEST_HEALTH = 1892,
	ENCHANT_CHEST_STATS = 1891,
	ENCHANT_CHEST_EXC_HEALTH = 2659,
	ENCHANT_CHEST_EXC_MANA = 2660,
	ENCHANT_CHEST_MP = 3150,
	ENCHANT_CHEST_GREATER_STATS = 2661,

	ENCHANT_BOOTS_SPEED = 911,
	ENCHANT_BOOTS_SPIRIT = 851,
	ENCHANT_BOOTS_AGILITY = 1887,
	ENCHANT_BOOTS_ACCURACY = 3858,
	ENCHANT_BOOTS_STAM = 929,

	ENCHANT_LEGARMOR = 1843,

	ENCHANT_SCOPE = 32,

};

#include "ScriptPCH.h"

void Enchant(Player* player, Item* item, uint32 enchantid)
{
	if (!item)
	{
		player->GetSession()->SendNotification("You must equip the item you would like to enchant, in order to enchant it!");
		return;
	}

	if (!enchantid)
	{
		player->GetSession()->SendNotification("Something blew up! Sorry for the inconvenience, we'll send the troubleshooting gnomes right on it.");
		return;
	}
	player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, false);
	item->SetEnchantment(PERM_ENCHANTMENT_SLOT, enchantid, 0, 0);
	player->ApplyEnchantment(item, PERM_ENCHANTMENT_SLOT, true);
	player->GetSession()->SendNotification("|cff800080%s |cffFF0000 Successfully enchanted!", item->GetTemplate()->Name1.c_str());
}

void RemoveEnchant(Player* player, Item* item)
{
	if (!item)
	{
		player->GetSession()->SendNotification("You don't have the item equipped.");
		return;
	}

	item->ClearEnchantment(PERM_ENCHANTMENT_SLOT);
}

class enchanter : public CreatureScript
{
public:
	enchanter() : CreatureScript("enchanter") { }

	bool OnGossipHello(Player* player, Creature* creature)
	{
		player->PlayerTalkClass->ClearMenus();
		player->ADD_GOSSIP_ITEM(1, "Cloak", GOSSIP_SENDER_MAIN, 6);
		player->ADD_GOSSIP_ITEM(1, "Chest", GOSSIP_SENDER_MAIN, 7);
		player->ADD_GOSSIP_ITEM(1, "Bracers", GOSSIP_SENDER_MAIN, 8);
		player->ADD_GOSSIP_ITEM(1, "Gloves", GOSSIP_SENDER_MAIN, 9);
		player->ADD_GOSSIP_ITEM(1, "Boots", GOSSIP_SENDER_MAIN, 11);
		player->ADD_GOSSIP_ITEM(1, "Weapons: MH/2H", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(1, "Weapons: OH", GOSSIP_SENDER_MAIN, 13);
		//player->ADD_GOSSIP_ITEM(1, "2H Weapon", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(1, "Shield", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(1, "Legs (+40 Armour)", GOSSIP_SENDER_MAIN, 215);
		player->ADD_GOSSIP_ITEM(1, "Standard Scope (+2 damage)", GOSSIP_SENDER_MAIN, 226);
		//player->ADD_GOSSIP_ITEM(1, "I would like to remove an enchantment.", GOSSIP_SENDER_MAIN, 14);

		player->PlayerTalkClass->SendGossipMenu(100001, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 action)
	{
		player->PlayerTalkClass->ClearMenus();
		Item * item;

		switch (action)
		{

		case 1: // Enchant Weapon

			player->PlayerTalkClass->ClearMenus();
			player->ADD_GOSSIP_ITEM(1, "2H: +25 Agility", GOSSIP_SENDER_MAIN, 115);
			player->ADD_GOSSIP_ITEM(1, "2H: +9 Damage", GOSSIP_SENDER_MAIN, 212);
			player->ADD_GOSSIP_ITEM(1, "2H: Iron Counterweight", GOSSIP_SENDER_MAIN, 214);
			player->ADD_GOSSIP_ITEM(1, "+15 Agility", GOSSIP_SENDER_MAIN, 108);
			player->ADD_GOSSIP_ITEM(1, "+15 Strength", GOSSIP_SENDER_MAIN, 109);
			player->ADD_GOSSIP_ITEM(1, "+30 Spell Power", GOSSIP_SENDER_MAIN, 106);
			player->ADD_GOSSIP_ITEM(1, "+22 Intellect", GOSSIP_SENDER_MAIN, 110);
			player->ADD_GOSSIP_ITEM(1, "+20 Spirit", GOSSIP_SENDER_MAIN, 101);
			player->ADD_GOSSIP_ITEM(1, "Crusader", GOSSIP_SENDER_MAIN, 105);
			player->ADD_GOSSIP_ITEM(1, "Icy Weapon", GOSSIP_SENDER_MAIN, 100);
			player->ADD_GOSSIP_ITEM(1, "Lifestealing", GOSSIP_SENDER_MAIN, 107);
			player->ADD_GOSSIP_ITEM(1, "Fiery Weapon", GOSSIP_SENDER_MAIN, 104);
			player->ADD_GOSSIP_ITEM(1, "+5 Weapon Damage", GOSSIP_SENDER_MAIN, 213);
			//player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
			player->PlayerTalkClass->SendGossipMenu(100002, creature->GetGUID());
			break;

		case 2: // Enchant 2H Weapon
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

			if (!item)
			{
				player->GetSession()->SendNotification("You must equip a Two-Handed weapon first.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
			{
				player->ADD_GOSSIP_ITEM(1, "Crusader", GOSSIP_SENDER_MAIN, 105);
				player->ADD_GOSSIP_ITEM(1, "2H Agility (+25 Agility)", GOSSIP_SENDER_MAIN, 115);
				player->ADD_GOSSIP_ITEM(1, "Fiery Weapon", GOSSIP_SENDER_MAIN, 116);
				player->ADD_GOSSIP_ITEM(1, "Icy Weapon", GOSSIP_SENDER_MAIN, 117);
				player->ADD_GOSSIP_ITEM(1, "Spell power (+30 Spell Power)", GOSSIP_SENDER_MAIN, 106);
				player->ADD_GOSSIP_ITEM(1, "Lifestealing", GOSSIP_SENDER_MAIN, 107);
				player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
				player->PlayerTalkClass->SendGossipMenu(100003, creature->GetGUID());
				return true;
			}
			else
			{
				player->GetSession()->SendNotification("You don't have a Two-Handed weapon equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 3: // Enchant Shield
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendNotification("You must equip a shield first.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_SHIELD)
			{
				//player->ADD_GOSSIP_ITEM(1, "+30 Armor", GOSSIP_SENDER_MAIN, 118);
				player->ADD_GOSSIP_ITEM(1, "+4 Mana and Health Per 5", GOSSIP_SENDER_MAIN, 119);
				player->ADD_GOSSIP_ITEM(1, "+10 Block Rating", GOSSIP_SENDER_MAIN, 120);
				player->ADD_GOSSIP_ITEM(1, "26-38 Damage on Block", GOSSIP_SENDER_MAIN, 121);
				player->ADD_GOSSIP_ITEM(1, "+7 Spirit", GOSSIP_SENDER_MAIN, 122);
				player->ADD_GOSSIP_ITEM(1, "+7 Stamina", GOSSIP_SENDER_MAIN, 123);
				//player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
				player->PlayerTalkClass->SendGossipMenu(100004, creature->GetGUID());
				return true;
			}
			else
			{
				player->GetSession()->SendNotification("You do not have a shield equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 6: // Enchant Cloak
			player->ADD_GOSSIP_ITEM(1, "+10 Shadow Resistance", GOSSIP_SENDER_MAIN, 155);
			player->ADD_GOSSIP_ITEM(1, "+15 Fire Resistance", GOSSIP_SENDER_MAIN, 150);
			player->ADD_GOSSIP_ITEM(1, "+15 Nature Resistance", GOSSIP_SENDER_MAIN, 153);
			player->ADD_GOSSIP_ITEM(1, "+5 All Resistances", GOSSIP_SENDER_MAIN, 154);
			player->ADD_GOSSIP_ITEM(1, "+12 Dodge Rating", GOSSIP_SENDER_MAIN, 147);
			player->ADD_GOSSIP_ITEM(1, "+70 Armor", GOSSIP_SENDER_MAIN, 148);
			player->ADD_GOSSIP_ITEM(1, "+3 Agility", GOSSIP_SENDER_MAIN, 151);
			player->ADD_GOSSIP_ITEM(1, "Increased Stealth", GOSSIP_SENDER_MAIN, 152);
			//player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
			player->PlayerTalkClass->SendGossipMenu(100007, creature->GetGUID());
			return true;
			break;

		case 7: //Enchant chest
			//player->ADD_GOSSIP_ITEM(1, "Lesser Absorption", GOSSIP_SENDER_MAIN, 158);
			player->ADD_GOSSIP_ITEM(1, "+4 All Stats", GOSSIP_SENDER_MAIN, 161);
			player->ADD_GOSSIP_ITEM(1, "+100 Health", GOSSIP_SENDER_MAIN, 160);
			player->ADD_GOSSIP_ITEM(1, "+100 Mana", GOSSIP_SENDER_MAIN, 159);
			player->ADD_GOSSIP_ITEM(1, "+6 All Stats", GOSSIP_SENDER_MAIN, 211);
			player->ADD_GOSSIP_ITEM(1, "+150 Health", GOSSIP_SENDER_MAIN, 162);
			player->ADD_GOSSIP_ITEM(1, "+150 Mana", GOSSIP_SENDER_MAIN, 209);
			player->ADD_GOSSIP_ITEM(1, "7 Mana Per 5", GOSSIP_SENDER_MAIN, 210);
			//player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
			player->PlayerTalkClass->SendGossipMenu(100008, creature->GetGUID());
			return true;
			break;

		case 8: //Enchant Bracers
			player->ADD_GOSSIP_ITEM(1, "+9 Stamina", GOSSIP_SENDER_MAIN, 165);
			player->ADD_GOSSIP_ITEM(1, "+9 Strength", GOSSIP_SENDER_MAIN, 164);
			player->ADD_GOSSIP_ITEM(1, "+7 Intellect", GOSSIP_SENDER_MAIN, 163);
			player->ADD_GOSSIP_ITEM(1, "+5 Mana Per 5", GOSSIP_SENDER_MAIN, 166);
			//player->ADD_GOSSIP_ITEM(1, "Deflection", GOSSIP_SENDER_MAIN, 167);
			player->ADD_GOSSIP_ITEM(1, "+15 Spell Power", GOSSIP_SENDER_MAIN, 168);
			//player->ADD_GOSSIP_ITEM(1, "Minor Agility", GOSSIP_SENDER_MAIN, 169);
			//player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
			player->PlayerTalkClass->SendGossipMenu(100009, creature->GetGUID());
			return true;
			break;

		case 9: //Enchant Gloves
			player->ADD_GOSSIP_ITEM(1, "+10 Haste", GOSSIP_SENDER_MAIN, 185);
			player->ADD_GOSSIP_ITEM(1, "+20 Fire Power", GOSSIP_SENDER_MAIN, 183);
			player->ADD_GOSSIP_ITEM(1, "+20 Frost Power", GOSSIP_SENDER_MAIN, 184);
			player->ADD_GOSSIP_ITEM(1, "+20 Shadow Power", GOSSIP_SENDER_MAIN, 180);
			player->ADD_GOSSIP_ITEM(1, "+16 Spell Power", GOSSIP_SENDER_MAIN, 181);
			player->ADD_GOSSIP_ITEM(1, "+15 Agility", GOSSIP_SENDER_MAIN, 182);
			player->ADD_GOSSIP_ITEM(1, "+7 Strength", GOSSIP_SENDER_MAIN, 178);
			//player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
			player->PlayerTalkClass->SendGossipMenu(100010, creature->GetGUID());
			return true;
			break;

		case 11: //Enchant feet
			player->ADD_GOSSIP_ITEM(1, "Minor Speed", GOSSIP_SENDER_MAIN, 191);
			player->ADD_GOSSIP_ITEM(1, "+7 Stamina", GOSSIP_SENDER_MAIN, 195);
			player->ADD_GOSSIP_ITEM(1, "+7 Agility", GOSSIP_SENDER_MAIN, 193);
			player->ADD_GOSSIP_ITEM(1, "+5 Hit Rating", GOSSIP_SENDER_MAIN, 194);
			//            player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
			player->PlayerTalkClass->SendGossipMenu(100012, creature->GetGUID());
			return true;
			break;



		case 13: //Enchant Off-Hand weapons
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)

			{
				player->GetSession()->SendNotification("You must equip a weapon in your Off-hand");
				MainMenu(player, creature);
				return false;
			}
			else if (item->GetTemplate()->InventoryType == INVTYPE_WEAPONOFFHAND || INVTYPE_WEAPONMAINHAND)
			{
				player->ADD_GOSSIP_ITEM(1, "+15 Agility", GOSSIP_SENDER_MAIN, 221);
				player->ADD_GOSSIP_ITEM(1, "+15 Strength", GOSSIP_SENDER_MAIN, 222);
				player->ADD_GOSSIP_ITEM(1, "+30 Spell Power", GOSSIP_SENDER_MAIN, 219);
				player->ADD_GOSSIP_ITEM(1, "+22 Intellect", GOSSIP_SENDER_MAIN, 223);
				player->ADD_GOSSIP_ITEM(1, "+20 Spirit", GOSSIP_SENDER_MAIN, 216);
				player->ADD_GOSSIP_ITEM(1, "Crusader", GOSSIP_SENDER_MAIN, 218);
				player->ADD_GOSSIP_ITEM(1, "Icy Weapon", GOSSIP_SENDER_MAIN, 224);
				player->ADD_GOSSIP_ITEM(1, "Lifestealing", GOSSIP_SENDER_MAIN, 220);
				player->ADD_GOSSIP_ITEM(1, "Fiery Weapon", GOSSIP_SENDER_MAIN, 217);
				player->ADD_GOSSIP_ITEM(1, "+5 Weapon Damage", GOSSIP_SENDER_MAIN, 225);
				player->PlayerTalkClass->SendGossipMenu(100002, creature->GetGUID());
				return true;
			}
			else
			{
				player->GetSession()->SendNotification("Your Off-Hand is not a weapon.");
				MainMenu(player, creature);
			}
		}
		break;

		case 14: //Remove enchant menu
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Main-hand", GOSSIP_SENDER_MAIN, 400);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Off-hand", GOSSIP_SENDER_MAIN, 401);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Cloak", GOSSIP_SENDER_MAIN, 404);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Chest", GOSSIP_SENDER_MAIN, 405);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Bracers", GOSSIP_SENDER_MAIN, 406);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Gloves", GOSSIP_SENDER_MAIN, 407);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Feet", GOSSIP_SENDER_MAIN, 409);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Legs", GOSSIP_SENDER_MAIN, 411);
			player->ADD_GOSSIP_ITEM(1, "Remove the enchantment on my Helm.", GOSSIP_SENDER_MAIN, 412);
			player->ADD_GOSSIP_ITEM(1, "<-Back", GOSSIP_SENDER_MAIN, 300);
			player->PlayerTalkClass->SendGossipMenu(100014, creature->GetGUID());
			return true;
			break;

		case 100:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_ICEY);
			MainMenu(player, creature);
			break;

		case 101:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_SPIRIT);
			MainMenu(player, creature);
			break;

		case 104:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_FIERY);
			MainMenu(player, creature);
			break;

		case 105:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_CRUSADER);
			MainMenu(player, creature);
			break;

		case 106:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_SPELLPOWER);
			MainMenu(player, creature);
			break;

		case 107:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_LIFESTEALING);
			MainMenu(player, creature);
			break;

		case 108:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_AGILITY1H);
			MainMenu(player, creature);
			break;

		case 109:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_STRENGTH);
			MainMenu(player, creature);
			break;

		case 110:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_INTELLECT);
			MainMenu(player, creature);
			break;


		case 113:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a 2H weapon equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_2WEP_CRUSADER);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a Two-Handed weapon equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 115:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a 2H weapon equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_2WEP_AGILITY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a Two-Handed weapon equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 116:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a 2H weapon equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_2WEP_FIERY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a Two-Handed weapon equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 117:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a 2H weapon equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_2WEP_ICEY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a Two-Handed weapon equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 118:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a shield equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_SHIELD)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_PROTECTION);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a shield equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 119:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a shield equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_SHIELD)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_VITALITY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a shield equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 120:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a shield equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_SHIELD)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_BLOCK);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a shield equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 121:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a shield equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_SHIELD)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_SPIKE);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a shield equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 122:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a shield equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_SHIELD)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_SPIRIT);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a shield equipped.");
				MainMenu(player, creature);
			}
		}
		break;

		case 123:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a shield equipped.");
				MainMenu(player, creature);
				return false;
			}

			if (item->GetTemplate()->InventoryType == INVTYPE_SHIELD)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_SHIELD_STAM);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You don't have a shield equipped.");
				MainMenu(player, creature);
			}
		}
		break;



		case 147:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_DODGE);
			MainMenu(player, creature);
			break;

		case 148:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_ARMOR);
			MainMenu(player, creature);
			break;

		case 149:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_SUBLETY);
			MainMenu(player, creature);
			break;

		case 150:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_FIRE);
			MainMenu(player, creature);
			break;

		case 151:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_AGILITY);
			MainMenu(player, creature);
			break;

		case 152:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_STEALTH);
			MainMenu(player, creature);
			break;

		case 153:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_NATURE);
			MainMenu(player, creature);
			break;

		case 154:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_RESIST);
			MainMenu(player, creature);
			break;

		case 155:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK), ENCHANT_CLOAK_SHADOW);
			MainMenu(player, creature);
			break;

		case 158:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_ABSORB);
			MainMenu(player, creature);
			break;

		case 159:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_MANA);
			MainMenu(player, creature);
			break;

		case 160:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_HEALTH);
			MainMenu(player, creature);
			break;

		case 161:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_STATS);
			MainMenu(player, creature);
			break;

		case 162:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
			if (item)
			{
				if (item->GetTemplate()->ItemLevel == 40)
				{

					Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_EXC_HEALTH);
					MainMenu(player, creature);
				}
				else
				{
					player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel for 35+!");
					MainMenu(player, creature);
				}
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel at 35+!");
				MainMenu(player, creature);
			}
		}
		break;

		case 163:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_INTELLECT);
			MainMenu(player, creature);
			break;

		case 164:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_STAM);
			MainMenu(player, creature);
			break;

		case 165:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_STRENGTH);
			MainMenu(player, creature);
			break;

		case 166:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_MP);
			MainMenu(player, creature);
			break;

		case 167:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_DEFLECTION);
			MainMenu(player, creature);
			break;

		case 168:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_HEALING);
			MainMenu(player, creature);
			break;

		case 169:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_WRISTS), ENCHANT_BRACERS_AGILITY);
			MainMenu(player, creature);
			break;

		case 178:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_STRENGTH);
			MainMenu(player, creature);
			break;

		case 179:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_HASTE);
			MainMenu(player, creature);
			break;

		case 180:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_SHADOW);
			MainMenu(player, creature);
			break;

		case 181:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_HEALING);
			MainMenu(player, creature);
			break;

		case 182:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_AGILITY);
			MainMenu(player, creature);
			break;

		case 183:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_FIRE);
			MainMenu(player, creature);
			break;

		case 184:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_FROST);
			MainMenu(player, creature);
			break;

		case 185:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_HANDS), ENCHANT_GLOVES_HASTE);
			MainMenu(player, creature);
			break;

		case 191:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_SPEED);
			MainMenu(player, creature);
			break;

		case 192:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_SPIRIT);
			MainMenu(player, creature);
			break;

		case 193:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_AGILITY);
			MainMenu(player, creature);
			break;

		case 194:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_ACCURACY);
			MainMenu(player, creature);
			break;

		case 195:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_FEET), ENCHANT_BOOTS_STAM);
			MainMenu(player, creature);
			break;


		case 205:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
				return false;
			}

			if (item)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_FIERY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
			}
		}
		break;

		case 206:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{

				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
				return false;
			}

			if (item)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_ICEY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
			}
		}
		break;

		case 207:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
				return false;
			}

			if (item)
			{

				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_CRUSADER);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
			}
		}
		break;

		case 208:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
				return false;
			}

			if (item)
			{
				(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND));
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_AGILITY1H);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
			}
		}
		break;

		case 209:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
			if (item)
			{
				if (item->GetTemplate()->ItemLevel == 40)
				{

					Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_EXC_MANA);
					MainMenu(player, creature);
				}
				else
				{
					player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel for 35+!");
					MainMenu(player, creature);
				}
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel for 35+!");
				MainMenu(player, creature);
			}
		}
		break;

		case 210:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);
			if (item)
			{
				if (item->GetTemplate()->ItemLevel == 40)
				{

					Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_MP);
					MainMenu(player, creature);
				}
				else
				{
					player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel for 35+!");
					MainMenu(player, creature);
				}
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel for 35+!");
				MainMenu(player, creature);
			}
		}
		break;

		case 211:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST);

			if (item)
			{
				if (item->GetTemplate()->ItemLevel == 40)
				{

					Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_CHEST), ENCHANT_CHEST_GREATER_STATS);
					MainMenu(player, creature);
				}
				else
				{
					player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel for 35+!");
					MainMenu(player, creature);
				}
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("You need a chest with an itemlevel for 35+!");
				MainMenu(player, creature);
			}
		}
		break;

		case 212:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a Two-handed weapon equipped.");
				MainMenu(player, creature);
				return false;
			}
			if (item->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
			{
				(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND));
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_AGILITY1H);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
			}
		}
		break;

		case 213:

			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_WEP_DAMAGE);
			MainMenu(player, creature);

			break;

		case 214:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND);

			if (!item)
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a Two-handed weapon equipped.");
				MainMenu(player, creature);
				return false;
			}
			if (item->GetTemplate()->InventoryType == INVTYPE_2HWEAPON)
			{
				(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND));
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_MAINHAND), ENCHANT_2WEP_HASTE);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant needs a one-hand weapon equipped in the off-hand.");
				MainMenu(player, creature);
			}
		}
		break;

		case 215:
			Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_LEGS), ENCHANT_LEGARMOR);
			MainMenu(player, creature);
			break;

		case 224:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_ICEY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 216:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_SPIRIT);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 217:

		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_FIERY);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 218:

		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_CRUSADER);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 219:

		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_SPELLPOWER);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 220:

		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_LIFESTEALING);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 221:

		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_AGILITY1H);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 222:

		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_STRENGTH);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 223:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_INTELLECT);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a Weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 225:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND);

			if (item->GetTemplate()->InventoryType == INVTYPE_WEAPON)
			{
				Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_OFFHAND), ENCHANT_WEP_DAMAGE);
				MainMenu(player, creature);
			}
			else
			{
				player->GetSession()->SendAreaTriggerMessage("This enchant requires a weapon");
				MainMenu(player, creature);
			}
		}
		break;

		case 226:
		{
			item = player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED);
			
			if (item)
			{
				if ((item->GetTemplate()->Class == 2 && item->GetTemplate()->SubClass == 2) || (item->GetTemplate()->Class == 2 && item->GetTemplate()->SubClass == 3))
				{
					Enchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_RANGED), ENCHANT_SCOPE);
					MainMenu(player, creature);
				}
				else
				{
					player->GetSession()->SendAreaTriggerMessage("You need a ranged weapon equipped!");
					MainMenu(player, creature);
				}
			}
				else
				{
					player->GetSession()->SendAreaTriggerMessage("You need a ranged weapon equipped!");
					MainMenu(player, creature);
				}
			}
		break;

		case 300: //<-Back menu
			player->ADD_GOSSIP_ITEM(1, "Weapon", GOSSIP_SENDER_MAIN, 1);
			player->ADD_GOSSIP_ITEM(1, "Off-Hand Weapon", GOSSIP_SENDER_MAIN, 13);
			player->ADD_GOSSIP_ITEM(1, "2H Weapon", GOSSIP_SENDER_MAIN, 2);
			player->ADD_GOSSIP_ITEM(1, "Shield", GOSSIP_SENDER_MAIN, 3);
			player->ADD_GOSSIP_ITEM(1, "Cloak", GOSSIP_SENDER_MAIN, 6);
			player->ADD_GOSSIP_ITEM(1, "Chest", GOSSIP_SENDER_MAIN, 7);
			player->ADD_GOSSIP_ITEM(1, "Bracers", GOSSIP_SENDER_MAIN, 8);
			player->ADD_GOSSIP_ITEM(1, "Gloves", GOSSIP_SENDER_MAIN, 9);
			player->ADD_GOSSIP_ITEM(1, "Feet", GOSSIP_SENDER_MAIN, 11);
			break;

		case 400: //Remove enchant for mainhand

			MainMenu(player, creature);
			break;

		case 401: //Remove enchant for offhand

			MainMenu(player, creature);
			break;

		case 404: //remove enchant for cloak
			RemoveEnchant(player, player->GetItemByPos(INVENTORY_SLOT_BAG_0, EQUIPMENT_SLOT_BACK));
			MainMenu(player, creature);
			break;

		case 405: //remove enchant for chest

			MainMenu(player, creature);
			break;

		case 406: //remove enchant for bracers

			MainMenu(player, creature);
			break;

		case 407: //remove enchant for gloves

			MainMenu(player, creature);
			break;


		case 409: //remove enchant for feet

			MainMenu(player, creature);
			break;

		}
		return true;
	}
	void MainMenu(Player* player, Creature* creature)
	{
		player->PlayerTalkClass->ClearMenus();
		player->ADD_GOSSIP_ITEM(1, "Cloak", GOSSIP_SENDER_MAIN, 6);
		player->ADD_GOSSIP_ITEM(1, "Chest", GOSSIP_SENDER_MAIN, 7);
		player->ADD_GOSSIP_ITEM(1, "Bracers", GOSSIP_SENDER_MAIN, 8);
		player->ADD_GOSSIP_ITEM(1, "Gloves", GOSSIP_SENDER_MAIN, 9);
		player->ADD_GOSSIP_ITEM(1, "Boots", GOSSIP_SENDER_MAIN, 11);
		player->ADD_GOSSIP_ITEM(1, "Weapons: MH/2H", GOSSIP_SENDER_MAIN, 1);
		player->ADD_GOSSIP_ITEM(1, "Weapons: OH", GOSSIP_SENDER_MAIN, 13);
		//player->ADD_GOSSIP_ITEM(1, "2H Weapon", GOSSIP_SENDER_MAIN, 2);
		player->ADD_GOSSIP_ITEM(1, "Shield", GOSSIP_SENDER_MAIN, 3);
		player->ADD_GOSSIP_ITEM(1, "Legs (+40 Armour)", GOSSIP_SENDER_MAIN, 215);
		player->ADD_GOSSIP_ITEM(1, "Standard Scope (+2 damage)", GOSSIP_SENDER_MAIN, 226);
		//player->ADD_GOSSIP_ITEM(1, "I would like to remove an enchantment.", GOSSIP_SENDER_MAIN, 14);

		player->PlayerTalkClass->SendGossipMenu(100001, creature->GetGUID());
	}

};

void AddSC_enchanter()
{
	new enchanter();
}

