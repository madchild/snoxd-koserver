#pragma once

#include "../shared/types.h"
#include <hash_map>

#define LUA_SCRIPT_DIRECTORY	"./quests/"
#define LUA_SCRIPT_ENTRY_POINT	"Main"
#define LUA_SCRIPT_GLOBAL_USER	"pUser"
#define LUA_SCRIPT_GLOBAL_NPC	"pNpc"
#define LUA_SCRIPT_BUFFER_SIZE	10000

// If defined, scripts are not cached. This is for testing/development purposes only.
#ifdef _DEBUG
#define LUA_SCRIPT_CACHE_DISABLED
#endif

extern "C" {
#	include "../scripting/Lua/lualib.h"
#	include "../scripting/Lua/lauxlib.h"
}

#include "../scripting/lua_helpers.h"
#include "lua_bindings.h"

typedef std::vector<uint8> BytecodeBuffer;
typedef stdext::hash_map<std::string, BytecodeBuffer> ScriptBytecodeMap;
class CUser;
class CNpc;
class FastMutex;
class CLuaScript
{
public:
	CLuaScript();
	bool Initialise();

	// Compiles script to bytecode
	bool CompileScript(const char * filename, BytecodeBuffer & buffer);

	// Loads bytecode one chunk at a time.
	static int LoadBytecodeChunk(lua_State * L, uint8 * bytes, size_t len, BytecodeBuffer * buffer);

	// Executes script from bytecode
	bool ExecuteScript(CUser * pUser, CNpc * pNpc, int32 nEventID, const char * filename, BytecodeBuffer & bytecode);

	// Handles the retrieval of error messages (same error codes used in both the compilation & execution stages)
	void RetrieveLoadError(int err, const char * filename);
	~CLuaScript();

private:
	lua_State * m_luaState;
	FastMutex * m_lock;
};

class RWLock;
class CLuaEngine
{
public:
	CLuaEngine();
	bool Initialise();
	CLuaScript * SelectAvailableScript();
	bool ExecuteScript(CUser * pUser, CNpc * pNpc, int32 nEventID, const char * filename);
	~CLuaEngine();

private:
	// For now, we'll only use a single instance for such.
	// In the future, however, it would be wise to spread the load across 
	// multiple script instances (which have been completely thread-safe since Lua 5.1)
	CLuaScript m_luaScript;
	RWLock * m_lock;

	ScriptBytecodeMap m_scriptMap;
};