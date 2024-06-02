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

#include "include/SceneManager.h"

MM::SceneManager *MM::SceneManager::s_pInstance = nullptr;

MM::SceneManager::SceneManager(){}

void MM::SceneManager::Push (BaseScene *scene){
    m_Scenes.push_back(scene);
    m_Scenes.back()->OnEnter();
}

void MM::SceneManager::Pop (){
    if(!m_Scenes.empty()){
        if (m_Scenes.back()->OnExit()){
            delete m_Scenes.back();
            m_Scenes.pop_back();
        }
    }
}

void MM::SceneManager::Change (BaseScene *scene){
    if (!m_Scenes.empty()){
        if (m_Scenes.back()->GetID() == scene->GetID()){
            return;
        }

        if (m_Scenes.back()->OnExit()){
            delete m_Scenes.back();
            m_Scenes.pop_back();
        }
    }

    m_Scenes.push_back(scene);
    m_Scenes.back()->OnEnter();
}

void MM::SceneManager::Update(){
    if(!m_Scenes.empty()){
        m_Scenes.back()->Update();
    }
}

void MM::SceneManager::Render(){
    if(!m_Scenes.empty()){
        m_Scenes.back()->Render();
    }
}
