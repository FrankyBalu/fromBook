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
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef __GAME__
#define __GAME__

#include <string>
#include <vector>
#include "BaseObject.h"

namespace MM {

class Game {
public:

    static Game* Instance(){
        if(s_pInstance == nullptr){
            s_pInstance = new Game();
        }
        return s_pInstance;
    }

    ~Game();

    bool Init(std::string title);

    void Render();
    void Update();
    void HandleEvents();
    void Clean();

    bool Running();

    float GetWidth(){return 800;}
    float GetHeight() {return 600;}

    void Shutdown(){m_Running = false;}
private:

    static Game* s_pInstance;

    bool m_Running;

    Game();

};

} //namespace MM

#endif // __GAME__
