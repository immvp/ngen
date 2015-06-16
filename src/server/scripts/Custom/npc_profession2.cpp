#include "Language.h"
 
 
#define TXT_BAD_SKILL   "Profession NPC: received non-valid skill ID (LearnAllRecipesInProfession)"
#define TXT_ERR_SKILL   "you already have that skill"
#define TXT_PROBLEM     "Internal error occured!"
#define TXT_ERR_MAX     "you already know two professions!"

enum Gossip_Option_Custom
{
    CUSTOM_OPTION_NONE          = 20,
    CUSTOM_OPTION_UNLEARN       = 21,
    CUSTOM_OPTION_EXIT          = 22,
    CUSTOM_OPTION_TITLE_PVP     = 23,
    CUSTOM_OPTION_TITLE_CLIMB   = 24,
    CUSTOM_OPTION_SPRINT        = 25,
    GOSSIP_OPTION_HELLO         = 26,
    CUSTOM_OPTION_ITEM_MENU     = 27,
    CUSTOM_OPTION_ITEM_MENU_P2  = 28,
    CUSTOM_OPTION_ITEM_MENU_P3  = 29,
    CUSTOM_OPTION_ITEM_MENU_P4  = 30,
    CUSTOM_OPTION_ITEM_MENU_P5  = 31,
    CUSTOM_OPTION_ITEM_MENU_P6  = 32,
    CUSTOM_OPTION_ITEM_MENU_P7  = 33,
    CUSTOM_OPTION_ITEM_MENU_MAX = 34,
    CUSTOM_OPTION_SUFFIX        = 35,
    CUSTOM_OPTION_PROPERTY      = 36,
    CUSTOM_OPTION_VENDOR        = 37,
    CUSTOM_OPTION_MAX
};

class npc_profession : public CreatureScript
{
public:
    npc_profession() : CreatureScript("npc_profession") { }
 
    bool LearnAllRecipesInProfession(Player* player, SkillType skill)
    {
        SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(skill);
        uint16 skill_level = 225;
        if (!SkillInfo)
        {
            TC_LOG_ERROR("entitles.player.skills", TXT_BAD_SKILL);
            return false;
        }
        if (skill == SKILL_ENGINEERING)
            skill_level = 150;
        player->SetSkill(SkillInfo->id, player->GetSkillStep(SkillInfo->id), skill_level, skill_level);

        return true;
    }
 
    bool ForgotSkill(Player* player, SkillType skill)
    {
        if (!player->HasSkill(skill))
            return false;
        SkillLineEntry const* SkillInfo = sSkillLineStore.LookupEntry(skill);
        if (!SkillInfo)
        {
            TC_LOG_ERROR("entitles.player.skills", TXT_BAD_SKILL);
            return false;
        }
        player->SetSkill(SkillInfo->id, player->GetSkillStep(SkillInfo->id), 0, 0);

        return true;
    }
 
    bool PlayerAlreadyHasTwoProfessions(Player* player)
    {
        uint32 skillCount = player->HasSkill(SKILL_MINING) + player->HasSkill(SKILL_SKINNING)
                          + player->HasSkill(SKILL_HERBALISM) + player->HasSkill(SKILL_ENGINEERING);
        if (skillCount >= 2)
            return true;

        return false;
    }
 
    void CompleteLearnProfession(Player* player, SkillType skill)
    {
        if (PlayerAlreadyHasTwoProfessions(player))
            player->GetSession()->SendNotification(TXT_ERR_MAX);
        else if (!LearnAllRecipesInProfession(player, skill))
            player->GetSession()->SendNotification(TXT_PROBLEM);
    }
 
    bool OnGossipHello(Player* player, Creature* me)
    {
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,    "Engineering", GOSSIP_SENDER_MAIN,    SKILL_ENGINEERING);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,    "Herbalism",   GOSSIP_SENDER_MAIN,    SKILL_HERBALISM);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,    "Skinning",    GOSSIP_SENDER_MAIN,    SKILL_SKINNING);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER,    "Mining",      GOSSIP_SENDER_MAIN,    SKILL_MINING);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_INTERACT_1, "Unlearn All", CUSTOM_OPTION_UNLEARN, 0);
        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_DOT,        "Bye..", CUSTOM_OPTION_EXIT,    0);
        player->SEND_GOSSIP_MENU(907, me->GetGUID());
        return true;
    }
 
    bool OnGossipSelect(Player* player, Creature* me, uint32 sender, uint32 skill)
    {
	player->PlayerTalkClass->ClearMenus();
        if (sender == CUSTOM_OPTION_UNLEARN)
        {
            ForgotSkill(player, SKILL_ENGINEERING);
            ForgotSkill(player, SKILL_HERBALISM);
            ForgotSkill(player, SKILL_SKINNING);
            ForgotSkill(player, SKILL_MINING);
        }
        else if (sender == GOSSIP_SENDER_MAIN)
        {
            if(player->HasSkill(skill))
                player->GetSession()->SendNotification(TXT_ERR_SKILL);
            else
                CompleteLearnProfession(player, (SkillType)skill);
        }
        if (sender == CUSTOM_OPTION_EXIT)
            player->PlayerTalkClass->SendCloseGossip();
        else
            OnGossipHello(player, me);

        return true;
    }
};
 
void AddSC_cyclone_customs()
{
    new npc_profession();
}
