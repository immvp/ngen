#include "ScriptPCH.h"

enum defines
{
    HAT_TOKEN = 100, // Hat Token
};

class hat_redeemer : public CreatureScript
{
public:
    hat_redeemer() : CreatureScript("hat_redeemer") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature) override
    {
        pPlayer->ADD_GOSSIP_ITEM_EXTENDED(4, "Redeem a Hat Token", GOSSIP_SENDER_MAIN, 1, "", 0, true);
        pPlayer->SEND_GOSSIP_MENU(9425, pCreature->GetGUID());
        return true;
    }

    static void CloseGossipMsg(Player* player, char const* msg)
    {
        player->GetSession()->SendNotification(msg);
        ChatHandler(player->GetSession()).SendSysMessage(msg);
        player->CLOSE_GOSSIP_MENU();
    }

    bool OnGossipSelectCode(Player* player, Creature* creature, uint32 /*sender*/, uint32 action, char const* code) override
    {
        player->PlayerTalkClass->ClearMenus();

        if (action != 1)
        {
            player->CLOSE_GOSSIP_MENU();
            return false;
        }

        if (!player->HasItemCount(HAT_TOKEN, 1, false))
        {
            CloseGossipMsg(player, "You need atleast one hat token");
            return true;
        }

        uint32 hatid = atoul(code);
        const ItemTemplate* temp = hatid ? sObjectMgr->GetItemTemplate(hatid) : NULL;
        if (!temp || temp->InventoryType != INVTYPE_HEAD)
        {
            CloseGossipMsg(player, "This item is not a hat");
            return true;
        }

        if (!player->AddItem(hatid, 1))
        {
            CloseGossipMsg(player, "Not enough space in bags");
            return true;
        }

        player->DestroyItemCount(HAT_TOKEN, 1, true, false);
        player->CLOSE_GOSSIP_MENU();
        return true;
    }
};

void AddSC_hat_redeemer()
{
    new hat_redeemer();
}