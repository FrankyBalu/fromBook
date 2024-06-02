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

#include "Player.h"
#include "../src/include/ObjectParams.h"
#include "../src/include/GraphicalBaseObject.h"
#include "../src/include/InputManager.h"
#include "../src/include/Game.h"
#include "../src/include/Log.h"

MM::Player::Player(const ObjectParams *param) :
GraphicalBaseObject(param){
    m_FrameCount = 0;
}

void MM::Player::Draw(){
    GraphicalBaseObject::Draw();
}

void MM::Player::Update(){
    if (IM::Instance()->IsKeyDown(KEY_RIGHT)){
        m_position.x += 2;
        if (m_position.x > MM::Game::Instance()->GetWidth() - m_width)
            m_position.x = MM::Game::Instance()->GetWidth() - m_width;
    }
    if (IM::Instance()->IsKeyDown(KEY_LEFT)){
        m_position.x -= 2;
        if (m_position.x <= 0)
            m_position.x = 0;
    }
    if (IM::Instance()->IsKeyDown(KEY_UP)){
        m_position.y -= 2;
        if (m_position.y < 0)
            m_position.y = 0;
    }
    if (IM::Instance()->IsKeyDown(KEY_DOWN)){
        m_position.y += 2;
        if (m_position.y > MM::Game::Instance()->GetHeight() - m_height)
            m_position.y = MM::Game::Instance()->GetHeight() - m_height;
    }

    LOG_E ("BIN HIER");
    if (m_FrameCount < 15 ){
        m_currentFrame = 0;
    }
    else if (m_FrameCount < 30 ){
        m_currentFrame = 1;
    }
    else if (m_FrameCount < 45 ){
        m_currentFrame = 2;
    }
    else if (m_FrameCount < 60 ){
        m_currentFrame = 3;
    }
    else {
        m_FrameCount = 0;
    }
    m_FrameCount++;
}

void MM::Player::Clean(){

}

void MM::Player::Input(){

}
