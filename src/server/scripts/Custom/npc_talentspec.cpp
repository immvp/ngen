class TalentGossip : public CreatureScript
{
public:
	TalentGossip() : CreatureScript("TalentGossip") { }

	bool OnGossipHello(Player* player, Creature* creature) override
	{
		switch (player->getClass())
		{
		case CLASS_WARRIOR:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Warrior_SavageBlow:50:50:-25:0|t |cff341C02Arms\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Warrior_InnerRage:50:50:-25:0|t |cff990606Fury\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Warrior_DefensiveStance:50:50:-25:0|t |cff112552Protection\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_PALADIN:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_HolyBolt:50:50:-25:0|t |cffB26D06Holy\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Paladin_ShieldoftheTemplar:50:50:-25:0|t |cff112552Protection\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_AuraofLight:50:50:-25:0|t |cffaa0ba8Retribution\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_HUNTER:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Hunter_BeastTaming:50:50:-25:0|t |cff21020aBeastmastery\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Hunter_FocusedAim:50:50:-25:0|t |cff081117Marksmanship\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Hunter_SwiftStrike:50:50:-25:0|t |cff1f1200Survival\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_ROGUE:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Rogue_Eviscerate:50:50:-25:0|t |cffb5351eAssassination\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Backstab:50:50:-25:0|t |cffb5351eCombat\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Stealth:50:50:-25:0|t |cffb5351eSublety\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_PRIEST:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_PowerWordShield:50:50:-25:0|t |cffFFFFFFDiscipline\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_GuardianSpirit:50:50:-25:0|t |cffFFFFFFHoly\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			//player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_ShadowWordPain:50:50:-25:0|t |cff160d1cShadow\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_DEATH_KNIGHT:
			/*
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Deathknight_BloodPresence:50:50:-25:0|t Blood\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Deathknight_FrostPresence:50:50:-25:0|t Frost\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Deathknight_UnholyPresence:50:50:-25:0|t Unholy\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			*/
			player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
			player->CLOSE_GOSSIP_MENU();
			break;

		case CLASS_SHAMAN:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_Lightning:50:50:-25:0|t |cff4000FFElemental\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_LightningShield:50:50:-25:0|t |cff013ADFEnhancement\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_MagicImmunity:50:50:-25:0|t |cff04B404Restoration\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_MAGE:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_MagicalSentry:50:50:-25:0|t |cff3fb7fcArcane|r\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nArcane Barrage, Counterspell", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Fire_Firebolt02:50:50:-25:0|t |cffb5351eFire|r\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nDragon's Breath", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Frost_Frostbolt02:50:50:-25:0|t |cff0c378cFrost|r\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nIcy Veins, Ice Block, Cold Snap", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_WARLOCK:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_DeathCoil:50:50:-25:0|t |cff279505Affliction\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_Metamorphosis:50:50:-25:0|t |cffb5351eDemonology\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_RainofFire:50:50:-25:0|t |cff613008Destruction\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;

		case CLASS_DRUID:
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_StarFall:50:50:-25:0|t |cff7c3f84Balance\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Druid_CatForm:50:50:-25:0|t |cff3c5e8aFeral\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
			player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_HealingTouch:50:50:-25:0|t |cff32946aRestoration\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
			break;


		default:
			return false;
			break;
		}
		player->SEND_GOSSIP_MENU(1, creature->GetGUID());
		return true;
	}

	bool OnGossipSelect(Player* player, Creature* creature, uint32 /*sender*/, uint32 actions) override
	{
		if (actions == GOSSIP_ACTION_INFO_DEF + 100)
		{
			player->SEND_GOSSIP_MENU(1, creature->GetGUID());
		}

		if (actions == GOSSIP_ACTION_INFO_DEF + 1) // Spec 1
		{
			switch (player->getClass())
			{
			case CLASS_WARRIOR: // Arms
				player->LearnSpell(6673, true);
				//player->LearnSpell(2, true); Fjern comment ( brugt til at vise det virker )
				//player->LearnSpell(3, true);
				//player->LearnSpell(4, true);
				//player->LearnSpell(5, true);

				player->RemoveSpell(71);
				player->RemoveSpell(469);
				//player->RemoveSpell(3); Fjern comment ( brugt til at vise det virker )
				//player->RemoveSpell(4);
				//player->RemoveSpell(5);
				break;

			case CLASS_PALADIN: // Holy
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_HUNTER: // BeastMastery
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_ROGUE: // Assassination
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_PRIEST: // Discipline
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_DEATH_KNIGHT: // Blood
				/*
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				*/
				player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
				break;

			case CLASS_SHAMAN: // Elemental
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_MAGE: // Arcane
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_WARLOCK: // Affliction
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_DRUID: // Balance
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			default:
				return false;
				break;
			}
			player->CLOSE_GOSSIP_MENU();
		}

		else if (actions == GOSSIP_ACTION_INFO_DEF + 2) // Spec 2
		{
			switch (player->getClass())
			{
			case CLASS_WARRIOR: // Fury
				player->LearnSpell(469, true);
				//player->LearnSpell(2, true); Fjern comment ( brugt til at vise det virker )
				//player->LearnSpell(3, true);
				//player->LearnSpell(4, true);
				//player->LearnSpell(5, true);

				player->RemoveSpell(6673);
				player->RemoveSpell(71);
				//player->RemoveSpell(3); Fjern comment ( brugt til at vise det virker )
				//player->RemoveSpell(4);
				//player->RemoveSpell(5);
				break;

			case CLASS_PALADIN: // Protection
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_HUNTER: // Marksmanship
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_ROGUE: // Combat
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_PRIEST: // Holy
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_DEATH_KNIGHT: // Frost
				/*
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				*/
				player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
				break;

			case CLASS_SHAMAN: // Enhancement
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_MAGE: // Fire
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_WARLOCK: // Demonology
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_DRUID: // Feral
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			default:
				return false;
				break;
			}
			player->CLOSE_GOSSIP_MENU();
		}

		else if (actions == GOSSIP_ACTION_INFO_DEF + 3) // Spec 3
		{
			switch (player->getClass())
			{
			case CLASS_WARRIOR: // Protection
				player->LearnSpell(71, true);
				//player->LearnSpell(2, true); Fjern comment ( brugt til at vise det virker )
				//player->LearnSpell(3, true);
				//player->LearnSpell(4, true);
				//player->LearnSpell(5, true);

				player->RemoveSpell(6673);
				player->RemoveSpell(469);
				//player->RemoveSpell(3); Fjern comment ( brugt til at vise det virker )
				//player->RemoveSpell(4);
				//player->RemoveSpell(5);
				break;

			case CLASS_PALADIN: // Retribution
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_HUNTER: // Survival
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_ROGUE: // Sublety
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_PRIEST: // Shadow
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_DEATH_KNIGHT: // Unholy
				/*
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				*/
				player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
				break;

			case CLASS_SHAMAN: // Restoration
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_MAGE: // Frost
				player->LearnSpell(12472, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_WARLOCK: // Destruction
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			case CLASS_DRUID: // Restoration
				player->LearnSpell(1, true);
				player->LearnSpell(2, true);
				player->LearnSpell(3, true);
				player->LearnSpell(4, true);
				player->LearnSpell(5, true);

				player->RemoveSpell(1);
				player->RemoveSpell(2);
				player->RemoveSpell(3);
				player->RemoveSpell(4);
				player->RemoveSpell(5);
				break;

			default:
				return false;
				break;
			}
			player->CLOSE_GOSSIP_MENU();
		}
		return true;
	}
};

void AddSC_TalentGossip()
{
	new TalentGossip();
}