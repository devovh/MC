/*
 * This file is part of the TrinityCore Project. See AUTHORS file for Copyright information
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License as published by the
 * Free Software Foundation; either version 2 of the License, or (at your
 * option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE. See the GNU General Public License for
 * more details.
 *
 * You should have received a copy of the GNU General Public License along
 * with this program. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TRINITY_OBJECTACCESSOR_H
#define TRINITY_OBJECTACCESSOR_H

#include "ObjectGuid.h"
#include <shared_mutex>
#include <unordered_map>
#include <mutex>
#include <set>
//#include <boost/thread/locks.hpp>
//#include <boost/thread/shared_mutex.hpp>
#include "Define.h"
#include "UpdateData.h"
#include "ObjectDefines.h"

class Corpse;
class Creature;
class DynamicObject;
class GameObject;
class Map;
class Object;
class Pet;
class Player;
class Transport;
class Unit;
class WorldObject;

template <class T>
class TC_GAME_API HashMapHolder
{
	//Non instanceable only static
    HashMapHolder() { }
	
public:

    typedef std::unordered_map<ObjectGuid, T*> MapType;

    static void Insert(T* o);

    static void Remove(T* o);

    static T* Find(ObjectGuid guid);

    static MapType& GetContainer();

    static std::shared_mutex* GetLock();
};

class ObjectAccessor
{
private:
    ObjectAccessor();
    ~ObjectAccessor();
    ObjectAccessor(const ObjectAccessor&);
    ObjectAccessor& operator=(const ObjectAccessor&);
public:
    /// @todo: Override these template functions for each holder type and add assertions

    TC_GAME_API static ObjectAccessor* instance()
    {
        static ObjectAccessor* instance = new ObjectAccessor();
        return instance;
    }

    template<class T> static T* GetObjectInOrOutOfWorld(ObjectGuid guid, T* /*typeSpecifier*/)
    {
        return HashMapHolder<T>::Find(guid);
    }
    
    TC_GAME_API static Unit* GetObjectInOrOutOfWorld(ObjectGuid guid, Unit* /*typeSpecifier*/)
    {
        if (IS_PLAYER_GUID(guid))
            return (Unit*)GetObjectInOrOutOfWorld(guid, (Player*)NULL);
        if (IS_PET_GUID(guid))
            return (Unit*)GetObjectInOrOutOfWorld(guid, (Pet*)NULL);
        return (Unit*)GetObjectInOrOutOfWorld(guid, (Creature*)NULL);
    }
    template<class T> static T* GetObjectInWorld(ObjectGuid guid, T* /*typeSpecifier*/)
    {
        return HashMapHolder<T>::Find(guid);
    }

    // Player may be not in world while in ObjectAccessor
    TC_GAME_API static Player* GetObjectInWorld(ObjectGuid guid, Player* /*typeSpecifier*/);

    //static Player* GetObjectInWorld(ObjectGuid guid, Pet* /*typeSpecifier*/);

    TC_GAME_API static Unit* GetObjectInWorld(ObjectGuid guid, Unit* /*typeSpecifier*/)
    {
        if (IS_PLAYER_GUID(guid))
            return (Unit*)GetObjectInWorld(guid, (Player*)NULL);
        if (IS_PET_GUID(guid))
            return (Unit*)GetObjectInWorld(guid, (Pet*)NULL);

        return (Unit*)GetObjectInWorld(guid, (Creature*)NULL);
    }
    // returns object if is in map
    template<class T> static T* GetObjectInMap(uint64 guid, Map* map, T* /*typeSpecifier*/)
    {
        ASSERT(map);
        if (T* obj = GetObjectInWorld(guid, (T*)NULL))
            if (obj->GetMap() == map)
                return obj;
        return NULL;
    }

    template<class T> static T* GetObjectInWorld(uint32 mapid, float x, float y, ObjectGuid guid, T* /*fake*/);
    // these functions return objects only if in map of specified object
    TC_GAME_API static WorldObject* GetWorldObject(WorldObject const&, ObjectGuid const&);
    TC_GAME_API static Object* GetObjectByTypeMask(WorldObject const&, ObjectGuid const&, uint32 typemask);
    TC_GAME_API static Corpse* GetCorpse(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API static GameObject* GetGameObject(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API static Transport* GetTransport(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API static DynamicObject* GetDynamicObject(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API static Unit* GetUnit(WorldObject const&, ObjectGuid const& guid);
    TC_GAME_API static Creature* GetCreature(WorldObject const& u, ObjectGuid const& guid);
    TC_GAME_API static Pet* GetPet(WorldObject const&, ObjectGuid const& guid);
    TC_GAME_API static Player* GetPlayer(Map const*, ObjectGuid const& guid);
    TC_GAME_API static Player* GetPlayer(WorldObject const&, ObjectGuid const& guid);
    TC_GAME_API static Creature* GetCreatureOrPetOrVehicle(WorldObject const&, ObjectGuid const&);

    // these functions return objects if found in whole world
    // ACCESS LIKE THAT IS NOT THREAD SAFE
    TC_GAME_API static Player* FindPlayer(ObjectGuid const&);
    TC_GAME_API static Player* FindPlayerByName(std::string_view name);
    TC_GAME_API static Player* FindPlayerByLowGUID(ObjectGuid::LowType lowguid);
    //static Player* FindPlayer2(ObjectGuid);
    //static Player* FindPlayerByName2(std::string const& name);
    //static Player* GetObjectInWorld(ObjectGuid guid, Pet* /*typeSpecifier*/);
    //static Player* GetObjectInWorld(ObjectGuid guid, Creature* /*typeSpecifier*/);
    //static Unit* GetObjectInWorld(ObjectGuid guid, Unit* /*typeSpecifier*/);

    // this returns Player even if he is not in world, for example teleporting
    TC_GAME_API static Player* FindConnectedPlayer(ObjectGuid const&);
    TC_GAME_API static Player* FindConnectedPlayerByName(std::string_view name);
    // these functions return objects if found in whole world
    // ACCESS LIKE THAT IS NOT THREAD SAFE
    TC_GAME_API static Pet* FindPet(ObjectGuid);
    //static Player* FindPlayer(uint64);
    TC_GAME_API static Creature* FindCreature(ObjectGuid);
    TC_GAME_API static Unit* FindUnit(ObjectGuid);
    // when using this, you must use the hashmapholder's lock
    TC_GAME_API static HashMapHolder<Player>::MapType const& GetPlayers();
    // when using this, you must use the hashmapholder's lock
    /*static HashMapHolder<Player>::MapType const& GetPlayers()
    {
        return HashMapHolder<Player>::GetContainer();
    }*/
    // when using this, you must use the hashmapholder's lock
    TC_GAME_API static HashMapHolder<Creature>::MapType const& GetCreatures()
    {
        return HashMapHolder<Creature>::GetContainer();
    }

    // when using this, you must use the hashmapholder's lock
    TC_GAME_API static HashMapHolder<GameObject>::MapType const& GetGameObjects()
    {
        return HashMapHolder<GameObject>::GetContainer();
    }
    template<class T>
    static void AddObject(T* object)
    {
        HashMapHolder<T>::Insert(object);
    }

    template<class T>
    static void RemoveObject(T* object)
    {
        HashMapHolder<T>::Remove(object);
    }

    template<>
    static void AddObject(Player* player);

    template<>
    static void RemoveObject(Player* player);
    
    TC_GAME_API static void SaveAllPlayers();
};

#define sObjectAccessor ObjectAccessor::instance()
#endif

