#include "ScriptPCH.h"
 
enum  defines
{
 hat_token = 100, // Hat Token
};
 
class hat_redeemer : public CreatureScript
{
        public:
                hat_redeemer () : CreatureScript("hat_redeemer "){}
 
                bool OnGossipHello(Player * pPlayer, Creature * pCreature)
                {
                       
                       
                        pPlayer->ADD_GOSSIP_ITEM(4, "Redeem a Hat Token", GOSSIP_SENDER_MAIN, 0);
                        pPlayer->PlayerTalkClass->SendGossipMenu(9425, pCreature->GetGUID());
                        return true;
                }
 
                bool OnGossipSelect(Player * Player, Creature * Creature, uint32 /*uiSender*/, uint32 uiAction)
                {
                        if(!Player)
                                return true;
 
                        switch(uiAction)
                        {
                                case 0:
                                        if(Player->HasItemCount(hat_token, 1))
                                        {
                                                Player->DestroyItemCount(hat_token, 1, true, false);
												
												
                                                Player->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
                                                Player->GetSession()->SendNotification("You need to relog, to change your race!");
                                                Player->PlayerTalkClass->SendCloseGossip();
                                        }
                                        else
                                        {
                                                Player->GetSession()->SendNotification("You need atleast one race change token!");
                                                Player->PlayerTalkClass->SendCloseGossip();
                                        }
                                        break;
                        }
                        return true;
                }
 
 
 
 		bool OnGossipSelectCode(Player* player, Creature* creature, uint32 sender, uint32 action, char const* code)
		{
			player->PlayerTalkClass->ClearMenus();
			uint32 codeUINT = (uint32)atol(code);
			if (!codeUINT)
				return false;
			QueryResult SearchForCode = WorldDatabase.PQuery("SELECT item FROM promotion_codes WHERE code = %u AND collection = %u AND used = 0", codeUINT, SelectedReward);
			if (!SearchForCode)
			{
				creature->AI()->Talk(SAY_WRONG);
			}
			else
			{
				creature->AI()->Talk(SAY_CORRECT);
				do
				{
					Field *fields = SearchForCode->Fetch();
					player->AddItem(fields[0].GetUInt32(), 1);
					WorldDatabase.PQuery("Update promotion_codes SET USED = 1 WHERE code = %u", codeUINT);
				} while (SearchForCode->NextRow());
			}

			player->PlayerTalkClass->SendCloseGossip();
			return true;
		}
};
 
void AddSC_npc_changer()
{
        new npc_changer();
}