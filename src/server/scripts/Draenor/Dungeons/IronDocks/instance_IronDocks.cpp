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

/*
This placeholder for the instance is needed for dungeon finding to be able
to give credit after the boss defined in lastEncounterDungeon is killed.
Without it, the party doing random dungeon won't get satchel of spoils and
gets instead the deserter debuff.
*/

/* # Script : IronDocks Dungeon # */

#include "ScriptMgr.h"
#include "InstanceScript.h"
#include "IronDocks.h"

/* Notes : What is missing ? : - Some visuals and texts
*/


class instance_IronDocks : public InstanceMapScript
{
    public:
        instance_IronDocks() : InstanceMapScript("instance_IronDocks", 1195) { }

        struct instance_IronDocks_InstanceMapScript : public InstanceScript
        {
            instance_IronDocks_InstanceMapScript(Map* map) : InstanceScript(map)
            {
                SetHeaders(DataHeader);
                SetBossNumber(EncounterCount);

            }

            void OnCreatureCreate(Creature* creature) override
            {
                switch (creature->GetEntry())
                {
                    case BOSS_GRIMRAILENFORCERS:
                    case BOSS_NOKGAR:
                    case BOSS_OSHIR:
                    case BOSS_SKULLOC:
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
                    case DATA_GRIMRAILENFORCERS:
                    case DATA_NOKGAR:
                    case DATA_OSHIR:
                    case DATA_SKULLOC:
                        break;
                    default:
                        return true;
                }

                return true;
            }


        };

        InstanceScript* GetInstanceScript(InstanceMap* map) const override
        {
            return new instance_IronDocks_InstanceMapScript(map);
        }
};

void AddSC_instance_IronDocks()
{
    new instance_IronDocks();
}
