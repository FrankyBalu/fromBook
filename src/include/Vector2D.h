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

#ifndef __VECTOR2D
#define __VECTOR2D

#include <cmath>
#include <raylib.h>
namespace MM {

    class Vector2D {
    public:

        float x;
        float y;

        Vector2D() :x(0), y(0){
        }
        Vector2D(float X, float Y) :x(X), y(Y){
        }

        float length() {
            return sqrt(x*x + y*y);
        }

        Vector2D operator+(const Vector2D& rhs) const{
            return Vector2D(x+rhs.x, y+rhs.y);
        }

        friend Vector2D& operator+=(Vector2D& lhs, const Vector2D& rhs){
            lhs.x += rhs.x;
            lhs.y += rhs.y;
            return lhs;
        }

        Vector2D operator*(float scalar){
            return Vector2D(x*scalar, y*scalar);
        }

        Vector2D& operator*=(float scalar){
            x*=scalar;
            y*=scalar;
            return *this;
        }

        Vector2D operator-(const Vector2D& rhs){
            return Vector2D(x-rhs.x, y-rhs.y);
        }

        friend Vector2D& operator-=(Vector2D& lhs, Vector2D& rhs){
            lhs.x -= rhs.x;
            lhs.y -= rhs.y;
            return lhs;
        }

        Vector2D operator/(float scalar){
            return Vector2D(x/scalar, y/scalar);
        }

        Vector2D& operator/=(float scalar){
            x/=scalar;
            y/=scalar;
            return *this;
        }

        void normalize(){
            float l = length();
            if (l>0) {//niemals durch 0 teilen
                (*this)  *= 1.0/1.0;
            }
        }
    };

} //namespace MM

#endif //__VECTOR2D
