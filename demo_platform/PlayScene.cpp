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

#include "PlayScene.h"
#include "../src/include/Log.h"
#include "Player.h"
#include "../src/include/ObjectParams.h"
#include "../src/include/TextureManager.h"
#include "../src/include/InputManager.h"
#include "../src/include/SceneManager.h"
#include "MenuScene.h"
#include "PausMenu.h"


const std::string MM::PlayScene::s_ID = "PLAY";

void MM::PlayScene::Update(){
    if (IM::Instance()->IsKeyPressed(KEY_ESCAPE)){
        MM::SceneManager::Instance()->Push(new PausMenu());
    }
    for (auto i = 0; i < m_playerObjects.size(); i++){
        m_playerObjects[i]->Update();
    }
}

void MM::PlayScene::Render(){
    for (auto i = 0; i < m_playerObjects.size(); i++){
        m_playerObjects[i]->Draw();
    }
}

bool MM::PlayScene::OnEnter(){
    bool returnValue;
    returnValue =
    MM::TextureManager::Instance()->Load(std::string(MULLEMAUS_DATA_DIR)
+ std::string("helicopter.png"), "player");

    m_playerObjects.push_back(new Player(new ObjectParams(20, 20, 128, 55,
                                                          "player")));
    return returnValue;
}

bool MM::PlayScene::OnExit(){
    LOG_D ("Exit Play");
    return true;
}
