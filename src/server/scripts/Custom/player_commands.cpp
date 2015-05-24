#include "Language.h"
#include "RBAC.h"
class vipcommands : public CommandScript
{
public:
	vipcommands() : CommandScript("vipcommands") { }

	ChatCommand* GetCommands() const
	{
		static ChatCommand vipCommandTable[] =

		{
			{ "summon", SEC_PLAYER, false, &HandleSummon, "", NULL },
			{ "appear", SEC_PLAYER, false, &HandleAppear, "", NULL },
			{ "mall", rbac::RBAC_PERM_COMMAND_VIPMALL, false, &HandleVipMallCommand, "", NULL },
			{ "changerace", rbac::RBAC_PERM_COMMAND_CHANGERACE, false, &HandleChangeRaceCommand, "", NULL },
			{ "changefaction", rbac::RBAC_PERM_COMMAND_CHANGEF, false, &HandleChangeFactionCommand, "", NULL },
			{ "maxskills", SEC_PLAYER, false, &HandleMaxSkillsCommand, "", NULL },
			{ "customize", SEC_PLAYER, false, &HandleCustomizeCommand, "", NULL },
			{ NULL, 0, false, NULL, "", NULL }
		};
		static ChatCommand commandTable[] =
		{
			{ "vip", rbac::RBAC_PERM_COMMAND_VIP, true, NULL, "", vipCommandTable },
			{ NULL, 0, false, NULL, "", NULL }
		};
		return commandTable;
	}
	static bool HandleSummon(ChatHandler * handler, const char* args)
	{

		return true;
	}

	static bool HandleAppear(ChatHandler * handler, const char* args)
	{

		return true;
	}


	static bool HandlevipCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();

		me->Say("vip command?", LANG_UNIVERSAL);
		return true;
	}


	/* The commands */

	static bool HandleChangeRaceCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_RACE);
		handler->PSendSysMessage("Relog to change race of your character.");
		return true;
	}

	static bool HandleChangeFactionCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CHANGE_FACTION);
		handler->PSendSysMessage("Relog to change faction of your character.");
		return true;
	}

	static bool HandleMaxSkillsCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();
		me->UpdateSkillsForLevel();
		handler->PSendSysMessage("Your weapon skills are now maximized.");
		return true;
	}

	static bool HandleCustomizeCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();
		me->SetAtLoginFlag(AT_LOGIN_CUSTOMIZE);
		handler->PSendSysMessage("Relog to customize your character.");
		return true;
	}

	static bool HandleVipMallCommand(ChatHandler* handler, const char* args)
	{

		Player* me = handler->GetSession()->GetPlayer();

		if (me->IsInCombat())
		{
			handler->SendSysMessage(LANG_YOU_IN_COMBAT);
			handler->SetSentErrorMessage(true);
			return false;
		}

		// stop flight if need
		if (me->IsInFlight())
		{
			me->GetMotionMaster()->MovementExpired();
			me->CleanupAfterTaxiFlight();
		}
		// stop flight if need
		if (me->IsInFlight())
		{
			me->GetMotionMaster()->MovementExpired();
			me->CleanupAfterTaxiFlight();
		}
		// save only in non-flight case
		else
			me->SaveRecallPosition();

		me->TeleportTo(209, 1648, 795, 12.5, 2.4); // MapId, X, Y, Z, O
		handler->PSendSysMessage("You Have Been Teleported!");
		return true;
	}

};

void AddSC_vipcommands()
{
	new vipcommands();
}