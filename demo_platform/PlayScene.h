/*
 * Mullemaus
 * Copyright (C) 2024   Frank Kartheuser <frank.kartheuser1988@gmail.com>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GmenuNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __PLAYSCENE
#define __PLAYSCENE

#include "../src/include/BaseScene.h"
#include "../src/include/GraphicalBaseObject.h"
#include <vector>

namespace MM {

    class PlayScene : public BaseScene {
    public:
        virtual void Update();
        virtual void Render();

        virtual bool OnEnter();
        virtual bool OnExit();

        virtual std::string GetID() const {return s_ID;}

    private:

        std::vector<BaseObject*> m_playerObjects;

        static const std::string s_ID;
    };
} //namespace MM

#endif //__PLAYSCENE
