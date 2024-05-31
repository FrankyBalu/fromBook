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
#include "include/TextureManager.h"

#include "include/Player.h"
#include "include/Enemy.h"


MM::Game * MM::Game::s_pInstance = nullptr;

///FIXME: das sollte über Optionen und eine Configfile definiert werden
const float screenWidth = 800;
const float screenHeight = 600;

bool MM::Game::init(std::string title){

    Init_Log();
    SetTraceLogLevel(LOG_ERROR);


    LOG_I("Initialisiere Mullemaus Engine");

    InitWindow(static_cast<int>(screenWidth), static_cast<int>(screenHeight), title.c_str());

    /// Taste zum beenden des Programms festlegen, muss nach dem erstellen des Fensters passieren
    SetExitKey(KEY_END);

    if (IsWindowReady()){
        LOG_D("Fenster ({} x {}) wurde erstellt", screenWidth, screenHeight);
        m_bRunning = true;
    }
    else{
        LOG_E("Fenster ({} x {}) konnte nicht erstellt werden", screenWidth, screenHeight);
        m_bRunning = false;
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

    TextureManager::Instance()->Load("data/animate-alpha.png", "rider");

    m_objects.push_back(new Player(new ObjectParams(20,80, 128,82, "rider")));
    m_objects.push_back(new Enemy(new ObjectParams(20, 80, 128,82,"rider")));

    m_numFrames = 0;

    ///////////////////////////////////////////////////////////////////////////
    //
    //  Test Code ende
    //
    ///////////////////////////////////////////////////////////////////////////

    return m_bRunning;
}

void MM::Game::render(){
    BeginDrawing();
    ClearBackground(WHITE);
    DrawText("Mullemaus Engine Demo", 20, 20, 30, RED);

    for (std::vector<BaseObject*>::size_type i= 0; i != m_objects.size(); i++ ){
        m_objects[i]->Draw();
    }

    EndDrawing();
}

void MM::Game::clean(){
    LOG_I("Fahre Mullemaus Engine runter.");
    CloseWindow();
    MM::Shutdown_Log();
}

MM::Game::Game(){
}

MM::Game::~Game(){
    MM::TextureManager::Instance()->Clear();
    clean();
}

bool MM::Game::running(){
    return m_bRunning;
}

void MM::Game::handleEvents(){

    if (WindowShouldClose())
        m_bRunning = false;
}

void MM::Game::update(){


    for (std::vector<BaseObject*>::size_type i= 0; i != m_objects.size(); i++ ){
        m_objects[i]->Update();
    }
}
