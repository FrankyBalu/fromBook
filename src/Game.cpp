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

#include "include/Game.h"
#include "include/Log.h"
#include "include/ObjectParams.h"
#include "include/SceneManager.h"
#include "include/TextureManager.h"



MM::Game * MM::Game::s_pInstance = nullptr;

///FIXME: das sollte über Optionen und eine Configfile definiert werden
const float screenWidth = 800;
const float screenHeight = 600;

bool MM::Game::Init(std::string title){

    Init_Log();
    SetTraceLogLevel(LOG_ERROR);


    LOG_I("Initialisiere Mullemaus Engine");

    InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), title.c_str());

    /// Taste zum beenden des Programms festlegen, muss nach dem erstellen des Fensters passieren
    SetExitKey(KEY_END);

    //std::string ff = MULLEMAUS_DATA_DIR
    LOG_D ("DIR: {}", MULLEMAUS_DATA_DIR);
    if (IsWindowReady()){
        LOG_D("Fenster ({} x {}) wurde erstellt", screenWidth, screenHeight);
        m_Running = true;
    }
    else{
        LOG_E("Fenster ({} x {}) konnte nicht erstellt werden", screenWidth, screenHeight);
        m_Running = false;
    }

  ///Zum Vollbild wechseln
    // ToggleFullscreen();

    /// FPS einstellen
    SetTargetFPS(60);

    ///////////////////////////////////////////////////////////////////////////
    //
    //  Test Code kommt hier hin
    //
    ///////////////////////////////////////////////////////////////////////////

    ///////////////////////////////////////////////////////////////////////////
    //
    //  Test Code ende
    //
    ///////////////////////////////////////////////////////////////////////////

    return m_Running;
}

void MM::Game::Render(){
    BeginDrawing();
    ClearBackground(WHITE);

    MM::SceneManager::Instance()->Render();

    EndDrawing();
}

void MM::Game::Clean(){
    LOG_I("Fahre Mullemaus Engine runter.");
    CloseWindow();
    MM::Shutdown_Log();
}

MM::Game::Game(){
}

MM::Game::~Game(){
    MM::TextureManager::Instance()->Clear();
    Clean();
}

bool MM::Game::Running(){
    return m_Running;
}

void MM::Game::HandleEvents(){

    if (WindowShouldClose())
        m_Running = false;
}

void MM::Game::Update(){
    MM::SceneManager::Instance()->Update();
}
