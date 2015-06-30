class TalentGossip : public CreatureScript
{
public:
        TalentGossip() : CreatureScript("TalentGossip") { }
 
        bool OnGossipHello(Player* player, Creature* creature) override
        {
                switch (player->getClass())
                {
                case CLASS_WARRIOR: // Done
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Warrior_SavageBlow:50:50:-25:0|t |cff341C02Arms\n|cffaa0ba8Passives:|r\nImproved Slam 2/2\n|cff6722d6Actives:|r\nSlam", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Warrior_InnerRage:50:50:-25:0|t |cff990606Fury\n|cffaa0ba8Passives:|r\nBloodsurge 3/3\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Warrior_DefensiveStance:50:50:-25:0|t |cff112552Protection\n|cffaa0ba8Passives:|r\nShield Mastery 2/2\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_PALADIN: // Done
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_HolyBolt:50:50:-25:0|t |cffB26D06Holy\n|cffaa0ba8Passives:|r\nConcentration Aura\n|cff6722d6Actives:|r\nAura Mastery", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Paladin_ShieldoftheTemplar:50:50:-25:0|t |cff112552Protection\n|cffaa0ba8Passives:|r\nSacred Duty 2/2, One-Handed Weapon Specialization 3/3, Redoubt 3/3\n|cff6722d6Actives:|r\nBlessing of Sanctuary", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_AuraofLight:50:50:-25:0|t |cffaa0ba8Retribution\n|cffaa0ba8Passives:|r\nPursuit of Justice 2/2\n|cff6722d6Actives:|r\nSeal of Command", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_HUNTER: // Done
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Hunter_BeastTaming:50:50:-25:0|t |cff21020aBeastmastery\n|cffaa0ba8Passives:|r\nNone\n|cff6722d6Actives:|r\nIntimidation", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Hunter_FocusedAim:50:50:-25:0|t |cff081117Marksmanship\n|cffaa0ba8Passives:|r\nWild Quiver 3/3\n|cff6722d6Actives:|r\nAspect of Viper", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Hunter_SwiftStrike:50:50:-25:0|t |cff1f1200Survival\n|cffaa0ba8Passives:|r\nNone\n|cff6722d6Actives:|r\nDeterrence", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_ROGUE: // NOT DONE
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Rogue_Eviscerate:50:50:-25:0|t |cffb5351eAssassination\n|cffaa0ba8Passives:|r\nVigor and Overkill\n|cff6722d6Actives:|r\nCloak of Shadows", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Backstab:50:50:-25:0|t |cffb5351eCombat\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nRupture", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Stealth:50:50:-25:0|t |cffb5351eSublety\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nVanish, Cheap Shot", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_PRIEST: // Done
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_PowerWordShield:50:50:-25:0|t |cffFFFFFFDiscipline\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nSmite (rank 4), Holy Fire (rank 1)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_GuardianSpirit:50:50:-25:0|t |cffFFFFFFHoly\n|cffaa0ba8Passives:|r\nBody and Soul 2/2\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_ShadowWordPain:50:50:-25:0|t |cff160d1cShadow\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_DEATH_KNIGHT:
                        /*
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Deathknight_BloodPresence:50:50:-25:0|t Blood\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TIntefrace/ICONS/Spell_Deathknight_FrostPresence:50:50:-25:0|t Frost\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Deathknight_UnholyPresence:50:50:-25:0|t Unholy\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        */
                        player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
                        player->CLOSE_GOSSIP_MENU();
                        break;
 
                case CLASS_SHAMAN: // done
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_Lightning:50:50:-25:0|t |cff4000FFElemental\n|cffaa0ba8Passives:|r\nStorm, Earth and Fire 3/3, Lightning Mastery\n|cff6722d6Actives:|r\nLava Burst", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_LightningShield:50:50:-25:0|t |cff013ADFEnhancement\n|cffaa0ba8Passives:|r\nDual Wield\nImproved Stormstrike\nShamanistic Focus\n|cff6722d6Actives:|r\nStormstrike\nHealing Wave(rank 4)", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_MagicImmunity:50:50:-25:0|t |cff04B404Restoration\n|cffaa0ba8Passives:|r\nNone\n|cff6722d6Actives:|r\nGrounding Totem, Nature's Swiftness", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_MAGE: // done
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Holy_MagicalSentry:50:50:-25:0|t |cff3fb7fcArcane|r\n|cffaa0ba8Passives:|rNone\n|cff6722d6Actives:|r\nPresence of Mind", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Fire_Firebolt02:50:50:-25:0|t |cffb5351eFire|r\n|cffaa0ba8Passives:|r\nImpact 3/3, Blazing Speed 2/2\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Frost_Frostbolt02:50:50:-25:0|t |cff0c378cFrost|r\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nDeep Freeze", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_WARLOCK: // NOT DONE
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_DeathCoil:50:50:-25:0|t |cff279505Affliction\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nDeath Coil", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_Metamorphosis:50:50:-25:0|t |cffb5351eDemonology\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nSoul Link", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Shadow_RainofFire:50:50:-25:0|t |cff613008Destruction\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nConflagrate", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
                        break;
 
                case CLASS_DRUID: // done
                        //player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_StarFall:50:50:-25:0|t |cff7c3f84Balance\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nN/A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Ability_Druid_CatForm:50:50:-25:0|t |cff3c5e8aFeral\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nFrenzied Regeneration", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 2);
                        player->ADD_GOSSIP_ITEM(GOSSIP_ICON_CHAT, "|TInterface/ICONS/Spell_Nature_HealingTouch:50:50:-25:0|t |cff32946aRestoration\n|cffaa0ba8Passives:|r\nN/A\n|cff6722d6Actives:|r\nSwiftmend", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 3);
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
#pragma region
                if (actions == GOSSIP_ACTION_INFO_DEF + 1) // Spec 1
                {
                        switch (player->getClass())
                        {
                        case CLASS_WARRIOR: // Arms                            
                                player->LearnSpell(12330, false);
                                player->LearnSpell(1464, false);
 
                                player->RemoveSpell(29599);
                                break;
 
                        case CLASS_PALADIN: // Holy
                                player->LearnSpell(19746, false);
                                player->LearnSpell(31821, false);
 
                                player->RemoveSpell(20375);
                                player->RemoveSpell(26023);
                                player->RemoveSpell(31849);
                                player->RemoveSpell(20198);
                                player->RemoveSpell(20911);
                                player->RemoveSpell(20135);
                                break;
 
                        case CLASS_HUNTER: // BeastMastery
                                player->LearnSpell(19577, false);
 
                                player->RemoveSpell(53217);
                                player->RemoveSpell(34074);
                                player->RemoveSpell(19263);
                                break;
 
                        case CLASS_ROGUE: // Assassination
                                player->LearnSpell(58426, false);
                                player->LearnSpell(14983, false);
                                player->LearnSpell(31224, false);
 
                                player->RemoveAura(58426);
                                player->RemoveSpell(31230);
                                player->RemoveSpell(1943);
                                player->RemoveSpell(1833);
                                player->RemoveSpell(1856);
                                break;
 
                        case CLASS_PRIEST: // Discipline
                                player->LearnSpell(14914, false);
                                player->LearnSpell(984, false);
 
                                player->RemoveSpell(64129);
                                break;
 
                        case CLASS_DEATH_KNIGHT: // Blood
                                player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
                                break;
 
                        case CLASS_SHAMAN: // Elemental
                                player->LearnSpell(51486, false);
                                player->LearnSpell(16580, false);
                                player->LearnSpell(51505, false);
                                
                                player->RemoveSpell(16188);
                                player->RemoveSpell(8177);
                                player->RemoveSpell(17116);
                                break;
 
                        case CLASS_MAGE: // Arcane
                                player->LearnSpell(12043, false);
 
                                player->RemoveSpell(44572);
                                player->RemoveSpell(12358);
                                player->RemoveSpell(31642);
                                break;
 
                        case CLASS_WARLOCK: // Affliction
                                player->LearnSpell(6789, false);
 
                                player->RemoveSpell(19028);
								player->RemoveSpell(17962);
                                break;
 
                        case CLASS_DRUID: // Balance
                                break;
 
                        default:
                                return false;
                                break;
                        }
                        player->CLOSE_GOSSIP_MENU();
                }
#pragma endregion Spec1
#pragma region
                else if (actions == GOSSIP_ACTION_INFO_DEF + 2) // Spec 2
                {
                        switch (player->getClass())
                        {
                        case CLASS_WARRIOR: // Fury
                                break;
 
                        case CLASS_PALADIN: // Protection
                                player->LearnSpell(31849, false);
                                player->LearnSpell(20198, false);
                                player->LearnSpell(20911, false);
                                player->LearnSpell(20135, false);
 
                                player->RemoveSpell(19746);
                                player->RemoveSpell(31821);
                                player->RemoveSpell(20375);
                                player->RemoveSpell(26023);
                                break;
 
                        case CLASS_HUNTER: // Marksmanship
                                player->LearnSpell(53217, false);
                                player->LearnSpell(34074, false);
 
                                player->RemoveSpell(19577);
                                player->RemoveSpell(24394);
                                player->RemoveSpell(19263);
                                break;
 
                        case CLASS_ROGUE: // Combat
                                player->LearnSpell(1943, false);
 							
 				player->RemoveSpell(58426);
                                player->RemoveAura(58426);
                                player->RemoveSpell(14983);
                                player->RemoveSpell(31230);
                                player->RemoveSpell(31224);
                                player->RemoveSpell(1833);
                                player->RemoveSpell(1856);
                                break;
 
                        case CLASS_PRIEST: // Holy
                                player->LearnSpell(64129, false);
 
                                player->RemoveSpell(14914);
                                player->RemoveSpell(984);
                                break;
 
                        case CLASS_DEATH_KNIGHT: // Frost
                                player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
                                break;
 
                        case CLASS_SHAMAN: // Enhancement
                                break;
 
                        case CLASS_MAGE: // Fire
                                player->LearnSpell(12358, false);
                                player->LearnSpell(31642, false);
 
                                player->RemoveSpell(12043);
                                player->RemoveSpell(44572);
                                player->RemoveSpell(29976);
                                break;
 
                        case CLASS_WARLOCK: // Demonology
                                player->LearnSpell(19028, false);
 
                                player->RemoveSpell(17962);
                                player->RemoveSpell(6789);
                                break;
 
                        case CLASS_DRUID: // Feral
                                player->LearnSpell(22842, false);
 
                                player->RemoveSpell(18562);
                                break;
 
                        default:
                                return false;
                                break;
                        }
                        player->CLOSE_GOSSIP_MENU();
                }
#pragma endregion Spec2
#pragma region
                else if (actions == GOSSIP_ACTION_INFO_DEF + 3) // Spec 3
                {
                        switch (player->getClass())
                        {
                        case CLASS_WARRIOR: // Protection
                                player->LearnSpell(29599, false);
 
                                player->RemoveSpell(12330);
                                player->RemoveSpell(1464);
                                break;
 
                        case CLASS_PALADIN: // Retribution
                                player->LearnSpell(20375, false);
                                player->LearnSpell(26023, false);
 
                                player->RemoveSpell(19746);
                                player->RemoveSpell(31821);
                                player->RemoveSpell(31849);
                                player->RemoveSpell(20198);
                                player->RemoveSpell(20911);
                                player->RemoveSpell(20135);
                                break;
 
                        case CLASS_HUNTER: // Survival
                                player->LearnSpell(19263, false);
 
                                player->RemoveSpell(19577);
                                player->RemoveSpell(53217);
                                player->RemoveSpell(34074);
                                player->RemoveSpell(24394);
                                break;
 
                        case CLASS_ROGUE: // Sublety
                                player->LearnSpell(1833, false);
                                player->LearnSpell(1856, false);
 								
                                player->RemoveAura(58426);
                                player->RemoveSpell(31224);
                                player->RemoveSpell(31230);
                                player->RemoveSpell(1943);
                                player->RemoveSpell(14983);
                                player->RemoveSpell(58426);
                                break;
 
                        case CLASS_PRIEST: // Shadow
                                break;
 
                        case CLASS_DEATH_KNIGHT: // Unholy
                                player->GetSession()->SendAreaTriggerMessage("Death Knights are currently not supported.");
                                break;
 
                        case CLASS_SHAMAN: // Restoration
                                player->LearnSpell(8177, false);
                                player->LearnSpell(16188, false);
 
                                player->RemoveSpell(51505);
                                player->RemoveSpell(16580);
                                player->RemoveSpell(51486);
                                break;
 
                        case CLASS_MAGE: // Frost
                                player->LearnSpell(44572, false);
 
                                player->RemoveSpell(12043);
                                player->RemoveSpell(12358);
                                player->RemoveSpell(31642);
                                player->RemoveSpell(29976);
                                break;
 
                        case CLASS_WARLOCK: // Destruction
                                player->LearnSpell(17962, false);
 
                                player->RemoveSpell(19028);
                                player->RemoveSpell(6789);
                                break;
 
                        case CLASS_DRUID: // Restoration
                                player->LearnSpell(18562, false);
                                player->RemoveSpell(22842);
                                break;
 
                        default:
                                return false;
                                break;
                        }
                        player->CLOSE_GOSSIP_MENU();
                }
#pragma endregion Spec3
                return true;
        }
};
 
void AddSC_TalentGossip()
{
        new TalentGossip();
}