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


#include "../src/include/Game.h"
#include "../src/include/SceneManager.h"
#include "MenuScene.h"
#include "PlayScene.h"


MM::Game *g_game;

int main (){
    g_game = MM::Game::Instance();

    g_game->Init("Mullemaus demo");

    MM::SceneManager::Instance()->Push(new MM::MenuScene());


    while(g_game->Running()){
        g_game->HandleEvents();
        g_game->Update();
        g_game->Render();
    }
    g_game->Clean();
    return 0;

}
