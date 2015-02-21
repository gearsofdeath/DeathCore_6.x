/*
 * Copyright (C) 2013-2015 DeathCore <http://www.noffearrdeathproject.net/>
 * Copyright (C) 2006-2009 ScriptDev2 <https://scriptdev2.svn.sourceforge.net/>
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

enum DoorLever{
    max_now       =  3
};

int32 Bonemaw_lever[max_now] = 
{
126071,
126072,
126073
};

int32 Bonemaw_door[max_now] = 
{
233988,
233989,
233990
};

class Bonemaw_doorlevers : public GameObjectScript
{
public:
    Bonemaw_doorlevers() : GameObjectScript("Bonemaw_doorlevers") { }

    bool OnGossipHello(Player* player, GameObject* go)
    {
        for (int i = 0; i < max_now; i++){
        if (GameObject * Bonemaw_Door = go->FindNearestGameObject(Bonemaw_door[i], 100.0f))
        {
                Bonemaw_Door->UseDoorOrButton();
                go->UseDoorOrButton();
        }
        }
            return true;

    }
};

void AddSC_Bonemaw_doorlevers()
{
	new Bonemaw_doorlevers();
}
