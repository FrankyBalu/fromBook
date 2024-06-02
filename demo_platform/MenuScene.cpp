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

#include "MenuScene.h"
#include "../src/include/SceneManager.h"
#include "../src/include/Log.h"
#include "../src/include/Game.h"
#include "PlayScene.h"
#include "../src/include/InputManager.h"

////test
#include <raylib.h>
#define RAYGUI_IMPLEMENTATION
#include <raygui.h>

const std::string MM::MenuScene::s_menuID = "MENU";

void MM::MenuScene::Update(){
    if (IM::Instance()->IsKeyPressed(KEY_DOWN)){
        if (m_ActivButton == 1)
            m_ActivButton = 2;
        else
            m_ActivButton = 1;
    }
    if (IM::Instance()->IsKeyPressed(KEY_UP)){
        if (m_ActivButton == 2)
            m_ActivButton = 1;
        else
            m_ActivButton = 2;
    }
    if (IM::Instance()->IsKeyPressed(KEY_ENTER)){
        if (m_ActivButton == 1)
            MM::SceneManager::Instance()->Change(new PlayScene());
        else
            MM::Game::Instance()->Shutdown();
    }
}

void MM::MenuScene::Render(){
    GuiLabel(m_LableMainMenu, "Hauptmenu");

    if (m_ActivButton == 1)
        GuiSetState(STATE_FOCUSED);
    else
        GuiSetState(STATE_NORMAL);
    GuiButton(m_ButtonPlay, "Spielen");
    GuiSetState(STATE_NORMAL);
    if (m_ActivButton == 2)
        GuiSetState(STATE_FOCUSED);
        else
            GuiSetState(STATE_NORMAL);
    GuiButton(m_ButtonExit, "Beenden");
    GuiSetState(STATE_NORMAL);
}

bool MM::MenuScene::OnEnter(){
    float screenWidth = MM::Game::Instance()->GetWidth();
    float screenHeight = MM::Game::Instance()->GetHeight();

    float ButtonWidth = screenWidth / 3;
    float ButtonHeight = screenHeight / 7;

    m_LableMainMenu.x = m_ButtonPlay.x = m_ButtonExit.x = ButtonWidth;
    m_LableMainMenu.width = m_ButtonPlay.width = m_ButtonExit.width = ButtonWidth;
    m_LableMainMenu.height = m_ButtonPlay.height = m_ButtonExit.height = ButtonHeight;

    m_LableMainMenu.y = ButtonHeight;
    m_ButtonPlay.y = ButtonHeight * 3;
    m_ButtonExit.y = ButtonHeight * 5;

    m_ActivButton = 1;

    return true;
}

bool MM::MenuScene::OnExit(){
    LOG_D ("Exit Menu");
    return true;
}
