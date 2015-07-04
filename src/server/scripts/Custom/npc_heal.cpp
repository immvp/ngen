#include "ScriptMgr.h"

class npc_heal : public CreatureScript
{
public:
	npc_heal() : CreatureScript("npc_heal") { }

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		player->ADD_GOSSIP_ITEM(1, "heal", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
		player->ADD_GOSSIP_ITEM(1, "nevermind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
		player->SEND_GOSSIP_MENU(1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 actions) override
	{

		switch (actions)
		{
		case GOSSIP_ACTION_INFO_DEF + 1:
			player->SetHealth(player->GetMaxHealth());
			player->GetSession()->SendAreaTriggerMessage("You've been healed.");
			player->CLOSE_GOSSIP_MENU();
		break;
		
		case GOSSIP_ACTION_INFO_DEF +2:
			player->CLOSE_GOSSIP_MENU();
			break;
		}
		return true;
	}
};
void AddSC_npc_heal()
{
	new npc_heal();
}