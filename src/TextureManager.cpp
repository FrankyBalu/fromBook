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

#include "include/Log.h"
#include "include/TextureManager.h"


MM::TextureManager * MM::TextureManager::s_pInstance = nullptr;


MM::TextureManager * MM::TextureManager::Instance(){
    if (s_pInstance == nullptr)
        s_pInstance = new TextureManager();

    return s_pInstance;
}

MM::TextureManager::TextureManager() = default;

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Das stammt aus einem Buch, aber wird zurzeit nicht aufgerufen.           //
//  Bin mir auch nicht sicher ob es so überhaupt Funktioniert                //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
MM::TextureManager::~TextureManager(){
    //FIXME Funktioniert scheinbar noch nicht richtig
    LOG_D ("Lösche die Instanz vom RenderManager!");
    //RenderManager *tmp = pInstance;
    //pInstance = nullptr;
    //delete tmp;
    LOG_D ("Lösche alle Texturen aus dem RenderManager:");
    for (auto it = m_textureMap.cbegin(); it != m_textureMap.cend(); ++it) {
        SPDLOG_DEBUG ("\t\t", (*it).first);
        UnloadTexture((*it).second);
        m_textureMap.erase((*it).first);
    }
    delete s_pInstance;
}


void MM::TextureManager::Clear(){
    this->~TextureManager();
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Läd eine Texture aus einer Datei auf der Festplatte.                     //
//  Die ID sollte eindeutig sein, ist sie schon vorhanden wird nichts        //
//  geladen.                                                                 //
//  Eventuell sollte die vorhandene Texture überschrieben werden,            //
//  das würde Mods ermöglichen bzw vereinfachen                              //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
bool MM::TextureManager::Load(const std::string &file, const std::string &id){
    ///Überprüfen ob die ID schon vorhanden ist
    if (m_textureMap.count(id) != 0){
        LOG_W ("Texture mit ID ({}) existiert bereits!", id);
        return false;
    }

    Texture2D tempTexture = LoadTexture(file.c_str());
    ///Überprüfen ob die Texture geladen werden konnte
    if(!IsTextureReady(tempTexture)){
        LOG_E ("Konnte Texture ({}) nicht laden!", file);
        return false;
    }
    ///Texture dem Pool hinzufügen
    m_textureMap[id] = tempTexture;
    LOG_D ("Texture {} mit ID: {} erfolgreich geladen!", file, id);
    return true;
}

///////////////////////////////////////////////////////////////////////////////
//                                                                           //
//  Stellt die Texture, in voller größe an der angegebenen stelle da         //
//                                                                           //
///////////////////////////////////////////////////////////////////////////////
bool MM::TextureManager::DrawSimple(const std::string& id, float x, float y){
    if (m_textureMap.count(id) == 0){
        LOG_E ("Texture {} nicht vorhanden!", id);
        return false;
    }
    DrawTexture(m_textureMap[id], static_cast<int>(x), static_cast<int>(y), WHITE); //FIXME FARBE selbst festlegen?
    return true;
}


void MM::TextureManager::BeginDrawing(){
    ::BeginDrawing();
}

void MM::TextureManager::EndDrawing(){
    ::EndDrawing();
}

bool MM::TextureManager::DrawFrame(const std::string& id, float x, float y, float width, float height, int frame, int row, [[maybe_unused]]FLIP flip){
    if (m_textureMap.count(id) == 0){
        LOG_E ("Texture {} nicht vorhanden!", id);
        return false;
    }
    Rectangle srcRect = {0.0f, 0.0f, width, height};
    Rectangle destRect = {x, y, width, height};
    srcRect.x = width * static_cast<float>(frame);
    srcRect.y = height * (static_cast<float>(row - 1));

    ///FIXME: FLIP wird noch ignoriert
    ///   Flip durch negative werte für w/h im srcRect
    DrawEx(id, srcRect, destRect, 0.0f);
    return true;
}

bool MM::TextureManager::DrawEx(const std::string& id, Rectangle src, Rectangle dest, float rotate, [[maybe_unused]] FLIP flip){
    if (m_textureMap.count(id) == 0){
        LOG_E ("Texture {} nicht vorhanden!", id);
        return false;
    }
    ///FIXME: FLIP wird noch ignoriert
    ///   Flip durch negative werte für w/h im srcRect
    DrawTexturePro(m_textureMap[id], src, dest, Vector2{3.0f,0.0f}, rotate,
WHITE);///FIXME Farbe selbst definieren
    return true;
}

Rectangle MM::TextureManager::GetRectangle(const std::string& id){
    if (m_textureMap.count(id) == 0){
        LOG_W ("Texture {} nicht vorhanden, gebe leere Fläche zurück", id);
        return {0.0f, 0.0f, 0.0f, 0.0f};
    }

    Rectangle rect;
    rect.x = rect.y = 0;
    rect.width = m_textureMap[id].width;
    rect.height = m_textureMap[id].height;
    return rect;
}

bool MM::TextureManager::FreeTexture(const std::string& id){
    if (m_textureMap.count(id) == 0){
        LOG_W ("Konnte Texture {} nicht löschen: nicht vorhanden!", id);
        return false;
    }
    LOG_D ("Lösche Texture {}", id);
    UnloadTexture(m_textureMap[id]);
    m_textureMap.erase(id);
    return true;
}

