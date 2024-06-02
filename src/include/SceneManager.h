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

#ifndef __SCENEMANAGER
#define __SCENEMANAGER

#include "BaseScene.h"
#include <vector>

namespace MM{

    class SceneManager {
    public:

        static SceneManager* Instance(){
            if (s_pInstance == nullptr){
                s_pInstance = new SceneManager();
            }
            return s_pInstance;
        }
        void Push (BaseScene *scene);
        void Change (BaseScene *scene);
        void Pop ();

        void Update();
        void Render();

    private:

        SceneManager();
        virtual ~SceneManager(){}

        static SceneManager *s_pInstance;

        std::vector<BaseScene*> m_Scenes;
    };

}//namespace MM

#endif //__SCENEMANAGER
