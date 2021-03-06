/*  EzGL/Collision.hpp
 *
 *  Copyright (c) 2018 Kirk Lange <github.com/kirklange>
 *
 *  This software is provided 'as-is', without any express or implied
 *  warranty. In no event will the authors be held liable for any damages
 *  arising from the use of this software.
 *
 *  Permission is granted to anyone to use this software for any purpose,
 *  including commercial applications, and to alter it and redistribute it
 *  freely, subject to the following restrictions:
 *
 *  1. The origin of this software must not be misrepresented; you must not
 *     claim that you wrote the original software. If you use this software
 *     in a product, an acknowledgment in the product documentation would be
 *     appreciated but is not required.
 *  2. Altered source versions must be plainly marked as such, and must not be
 *     misrepresented as being the original software.
 *  3. This notice may not be removed or altered from any source distribution.
 */

#ifndef EZGL_COLLISION_HPP
#define EZGL_COLLISION_HPP

/** @file       EzGL/Collision.hpp
 *  @brief      Collision component.
 *  @details    Enables collision between this object and all other objects
 *              with a collision component. An object's `data["collided"]` is
 *              set to `true` if it has collied with another object during
 *              the current frame. Additionally object's `Object *other`
 *              pointer is set to point to the object that it collided with.
 */

#include "EzGL/Component.hpp"

#include <string>
#include <vector>



namespace EzGL
{

class Object;

EZGL_COMPONENT_ENLIST(Collision);

class Collision final : public Component<Collision>
{
public:
    Collision() = default;
    ~Collision() = default;

    void init(Object &self, Object &main);
    void update(Object &self, Object &main);

private:
    bool isCollision(Object const &alpha, Object const &bravo);
    void undoTimestep(Object &alpha, Object &bravo, Object &main);
    void resolveImpact(std::string const &dim,
            Object &alpha, Object &bravo, Object &main);
    double getOverlap(Object &alpha, Object &bravo,
            std::string const &pos, std::string const &dim);

    static std::vector<Object*> Objects;
    static long long time;
};

}; /* namespace EzGL */



#endif /* EZGL_COLLISION_HPP */
