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
#include "InstanceScript.h"
#include "mogushan_palace.h"

/* Notes : What is missing ? : - Some visuals and texts
*/


class instance_mogushan_palace : public InstanceMapScript
{
	public:
		instance_mogushan_palace() : InstanceMapScript("instance_mogushan_palace", 994) { }

		struct instance_mogushan_palace_InstanceMapScript : public InstanceScript
		{
			instance_mogushan_palace_InstanceMapScript(Map* map) : InstanceScript(map)
			{
                		SetHeaders(DataHeader);
                		SetBossNumber(EncounterCount);
			}

			void OnCreatureCreate(Creature* creature)
			{
				switch (creature->GetEntry())
				{
                    			case BOSS_XIN_THE_WEAPONMASTER:
 						break;
                   			case BOSS_GEKKAN:
						break;
                    			case BOSS_TRIALOFKING:
						break;
					default:
						break;
				}
			}
			
			void OnGameObjectCreate(GameObject* go) 
            {
                switch (go->GetEntry())
                {
					case GO_DOOR_BEFORE_TRIAL:
						break;
					case GO_DOOR_AFTER_TRIAL:
						break;
					case GO_DOOR_BEFORE_KING:
						break;
					case GO_TRIAL_CHEST:
						break;
					default:
						break;
				}
			}
			

            bool SetBossState(uint32 type, EncounterState state) override
            {
                if (!InstanceScript::SetBossState(type, state))
                    return false;

                if (state != DONE)
                   return true;

                switch (type)
                {
                    			case DATA_BOSS_XIN_THE_WEAPONMASTER:
						break;
                    			case DATA_BOSS_GEKKAN:
						break;
                    			case DATA_BOSS_TRIALOFKING:
						break;
                    			default:
                        return true;
                }

                return true;
            }


        };


		InstanceScript* GetInstanceScript(InstanceMap* map) const 
		{
			return new instance_mogushan_palace_InstanceMapScript(map);
		}
};


void AddSC_instance_mogushan_palace()
{
   new instance_mogushan_palace();
}

