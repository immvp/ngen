#include "AchievementMgr.h"

class SeasonReward : public CreatureScript
{
public:
	SeasonReward() : CreatureScript("SeasonReward") { }

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		if (player->GetGUID() == 1746 || player->GetGUID() == 2135 || player->GetGUID() == 2702 || player->GetGUID() == 2705) // Rank 1's
		{
			uint32 achievementId = 419;
			if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievementId))
				player->CompletedAchievement(achievementEntry);
			player->GetSession()->SendAreaTriggerMessage("Congratulations on achieving Rank 1 this season!");
		}
		else if (player->GetGUID() == 39 || player->GetGUID() == 464) // Gladiator's
		{
			uint32 achievementId = 2091;
			if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievementId))
				player->CompletedAchievement(achievementEntry);
			player->GetSession()->SendAreaTriggerMessage("Congratulations on achieving Gladiator this season!");
		}
		else if (player->GetGUID() == 1913 || player->GetGUID() == 2015) // Dualist's
		{
			uint32 achievementId = 2092;
			if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievementId))
				player->CompletedAchievement(achievementEntry);
			player->GetSession()->SendAreaTriggerMessage("Congratulations on achieving Duelist this season!");
		}
		else if (player->GetGUID() == 9 || player->GetGUID() == 1418 || player->GetGUID() == 1926 || player->GetGUID() == 1928 || player->GetGUID() == 47) // Rival's
		{
			uint32 achievementId = 2093;
			if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievementId))
				player->CompletedAchievement(achievementEntry);
			player->GetSession()->SendAreaTriggerMessage("Congratulations on achieving Rival this season!");
		}
		else if (player->GetGUID() == 2388 || player->GetGUID() == 3436 || player->GetGUID() == 1261 || player->GetGUID() == 1726 || player->GetGUID() == 2038 || player->GetGUID() == 1923) // Rival's
		{
			uint32 achievementId = 2090;
			if (AchievementEntry const* achievementEntry = sAchievementMgr->GetAchievement(achievementId))
				player->CompletedAchievement(achievementEntry);
			player->GetSession()->SendAreaTriggerMessage("Congratulations on achieving Challenger this season!");
		}
		else
		{
			player->GetSession()->SendAreaTriggerMessage("You did not meet this season's requirements for rewards. Good luck next season!");
		}
		player->CLOSE_GOSSIP_MENU();
		return true;
	}
};

void AddSC_SeasonReward()
{
	new SeasonReward();
}