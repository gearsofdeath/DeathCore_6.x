/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */
 
#include "ScriptMgr.h"
#include "ScriptPCH.h"


class npc_battlemaster : public CreatureScript
{
public:
    npc_battlemaster() : CreatureScript("npc_battlemaster") { }

    bool OnGossipHello(Player* plr, Creature* npc)
    {
        if (plr->IsInCombat())
        {
            plr->GetSession()->SendNotification("You're in combat!");
            npc->Whisper("You're in combat!", LANG_UNIVERSAL, NULL);
            return false;
        }

        plr->ADD_GOSSIP_ITEM(2, "WoD BattleMaster", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 1);
        plr->ADD_GOSSIP_ITEM(9, "Nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
        plr->SEND_GOSSIP_MENU(1, npc->GetGUID());
        return true;
    }
    bool OnGossipSelect(Player* plr, Creature* npc, uint32 sender, uint32 uiAction)
    {
        if (!plr)
            return false;
        //------------------------------Menus------------------------------//
        plr->PlayerTalkClass->ClearMenus();
        switch (uiAction)
        {
        case GOSSIP_ACTION_INFO_DEF + 1:// teleportmaster
            if (plr->GetSession()->GetSecurity() <= 2)
            {
                plr->ADD_GOSSIP_ITEM(2, "WoD Battlegrounds", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(9, "nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            else{
                plr->ADD_GOSSIP_ITEM(2, "WoD Battlegrounds", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
                plr->ADD_GOSSIP_ITEM(9, "Nevermind..", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 5);
            }
            plr->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE, npc->GetGUID());
            break;
        case GOSSIP_ACTION_INFO_DEF + 12: //Battlegrounds
            plr->ADD_GOSSIP_ITEM(2, "BG TarrensMills vs Southside A", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 30);
            plr->ADD_GOSSIP_ITEM(2, "BG TarrensMills vs Southside B", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 31);
            plr->ADD_GOSSIP_ITEM(2, "Ashran Warshield", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 32);
            plr->ADD_GOSSIP_ITEM(2, "Ashran Stormshield", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 33);
            plr->ADD_GOSSIP_ITEM(1, "<- Back", GOSSIP_SENDER_MAIN, GOSSIP_ACTION_INFO_DEF + 12);
            break;

            //------------------------Battlegrounds-------------------------//
        case GOSSIP_ACTION_INFO_DEF + 30: //BG TarrensMills vs Southside A
            plr->TeleportTo(1280, 1873.94f, 1059.03f, 17.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 31: //BG TarrensMills vs Southside B
            plr->TeleportTo(1280, 2608.94f, 711.03f, 57.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 32: //Warshield
            plr->TeleportTo(1116, 5259.94f, -4005.03f, 14.428f, 2.03728f);
            break;
        case GOSSIP_ACTION_INFO_DEF + 33: //Stormshield
            plr->TeleportTo(1116, 3608.94f, -3970.03f, 13.428f, 2.03728f);
            break;

            //------------------------close---------------------------------//
        case GOSSIP_ACTION_INFO_DEF + 5: // Close Function
            plr->CLOSE_GOSSIP_MENU();
            break;
        }
        return true;
    }
};

void AddSC_npc_battlemaster()
{
    new npc_battlemaster();
}

