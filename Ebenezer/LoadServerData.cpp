#include "StdAfx.h"
#include "resource.h"

#include "Map.h"
#include "GameEvent.h"

#include "EbenezerDlg.h"
#include "KnightsManager.h"
#include "User.h"
#include "DBAgent.h"

#include "../shared/database/OdbcRecordset.h"
#include "../shared/database/ItemTableSet.h"
#include "../shared/database/ItemExchangeSet.h"
#include "../shared/database/MagicTableSet.h"
#include "../shared/database/MagicType1Set.h"
#include "../shared/database/MagicType2Set.h"
#include "../shared/database/MagicType3Set.h"
#include "../shared/database/MagicType4Set.h"
#include "../shared/database/MagicType5Set.h"
#include "../shared/database/MagicType6Set.h"
#include "../shared/database/MagicType7Set.h"
#include "../shared/database/MagicType8Set.h"
#include "../shared/database/MagicType9Set.h"
#include "../shared/database/ZoneInfoSet.h"
#include "../shared/database/EventSet.h"
#include "../shared/database/CoefficientSet.h"
#include "../shared/database/LevelUpTableSet.h"
#include "../shared/database/ServerResourceSet.h"
#include "../shared/database/EventTriggerSet.h"
#include "../shared/database/QuestHelperSet.h"
#include "../shared/database/QuestMonsterSet.h"
#include "../shared/database/KnightsSet.h"
#include "../shared/database/KnightsUserSet.h"
#include "../shared/database/KnightsAllianceSet.h"
#include "../shared/database/KnightsRankSet.h"
#include "../shared/database/KnightsCapeSet.h"
#include "../shared/database/UserPersonalRankSet.h"
#include "../shared/database/UserKnightsRankSet.h"
#include "../shared/database/HomeSet.h"
#include "../shared/database/StartPositionSet.h"
#include "../shared/database/BattleSet.h"
#include "../shared/database/RentalItemSet.h"

bool CEbenezerDlg::LoadTables()
{
	return (LoadItemTable()
			&& LoadItemExchangeTable()
			&& LoadServerResourceTable()
			&& LoadEventTriggerTable()
			&& LoadQuestHelperTable()
			&& LoadQuestMonsterTable()
			&& LoadMagicTable()
			&& LoadMagicType1()
			&& LoadMagicType2()
			&& LoadMagicType3()
			&& LoadMagicType4()
			&& LoadMagicType5()
			&& LoadMagicType6()
			&& LoadMagicType7()
			&& LoadMagicType8()
			&& LoadMagicType9()
			&& LoadRentalList()
			&& LoadCoefficientTable()
			&& LoadLevelUpTable()
			&& LoadAllKnights()
			&& LoadAllKnightsUserData()
			&& LoadKnightsAllianceTable()
			&& LoadUserRankings()
			&& LoadKnightsCapeTable()
			&& LoadHomeTable()
			&& LoadStartPositionTable()
			&& LoadBattleTable());
}

bool CEbenezerDlg::LoadItemTable()
{
	LOAD_TABLE(CItemTableSet, g_DBAgent.m_GameDB, &m_ItemtableArray, false);
}

bool CEbenezerDlg::LoadItemExchangeTable()
{
	LOAD_TABLE(CItemExchangeSet, g_DBAgent.m_GameDB, &m_ItemExchangeArray, true);
}

bool CEbenezerDlg::LoadServerResourceTable()
{
	LOAD_TABLE(CServerResourceSet, g_DBAgent.m_GameDB, &m_ServerResourceArray, false);
}

bool CEbenezerDlg::LoadEventTriggerTable()
{
	LOAD_TABLE(CEventTriggerSet, g_DBAgent.m_GameDB, &m_EventTriggerArray, true);
}

bool CEbenezerDlg::LoadQuestHelperTable()
{
	m_QuestNpcList.clear();
	LOAD_TABLE(CQuestHelperSet, g_DBAgent.m_GameDB, &m_QuestHelperArray, true);
}

bool CEbenezerDlg::LoadQuestMonsterTable()
{
	LOAD_TABLE(CQuestMonsterSet, g_DBAgent.m_GameDB, &m_QuestMonsterArray, true);
}

bool CEbenezerDlg::LoadMagicTable()
{
	LOAD_TABLE(CMagicTableSet, g_DBAgent.m_GameDB, &m_MagictableArray, false);
}

bool CEbenezerDlg::LoadMagicType1()
{
	LOAD_TABLE(CMagicType1Set, g_DBAgent.m_GameDB, &m_Magictype1Array, false);
}

bool CEbenezerDlg::LoadMagicType2()
{
	LOAD_TABLE(CMagicType2Set, g_DBAgent.m_GameDB, &m_Magictype2Array, false);
}

bool CEbenezerDlg::LoadMagicType3()
{
	LOAD_TABLE(CMagicType3Set, g_DBAgent.m_GameDB, &m_Magictype3Array, false);
}

bool CEbenezerDlg::LoadMagicType4()
{
	LOAD_TABLE(CMagicType4Set, g_DBAgent.m_GameDB, &m_Magictype4Array, false);
}

bool CEbenezerDlg::LoadMagicType5()
{
	LOAD_TABLE(CMagicType5Set, g_DBAgent.m_GameDB, &m_Magictype5Array, false);
}

bool CEbenezerDlg::LoadMagicType6()
{
	LOAD_TABLE(CMagicType6Set, g_DBAgent.m_GameDB, &m_Magictype6Array, false);
}

bool CEbenezerDlg::LoadMagicType7()
{
	LOAD_TABLE(CMagicType7Set, g_DBAgent.m_GameDB, &m_Magictype7Array, false);
}

bool CEbenezerDlg::LoadMagicType8()
{
	LOAD_TABLE(CMagicType8Set, g_DBAgent.m_GameDB, &m_Magictype8Array, false);
}

bool CEbenezerDlg::LoadMagicType9()
{
	LOAD_TABLE(CMagicType9Set, g_DBAgent.m_GameDB, &m_Magictype9Array, false);
}

bool CEbenezerDlg::LoadRentalList()
{
	LOAD_TABLE(CRentalItemSet, g_DBAgent.m_GameDB, &m_RentalItemArray, true);
}

bool CEbenezerDlg::LoadCoefficientTable()
{
	LOAD_TABLE(CCoefficientSet, g_DBAgent.m_GameDB, &m_CoefficientArray, false);
}

bool CEbenezerDlg::LoadLevelUpTable()
{
	LOAD_TABLE(CLevelUpTableSet, g_DBAgent.m_GameDB, &m_LevelUpArray, false);
}

bool CEbenezerDlg::LoadAllKnights()
{
	FastGuard lock(m_KnightsArray.m_lock);
	LOAD_TABLE(CKnightsSet, g_DBAgent.m_GameDB, &m_KnightsArray, true);
}

bool CEbenezerDlg::LoadAllKnightsUserData()
{
	LOAD_TABLE(CKnightsUserSet, g_DBAgent.m_GameDB, NULL, true);
}

bool CEbenezerDlg::LoadKnightsAllianceTable()
{
	LOAD_TABLE(CKnightsAllianceSet, g_DBAgent.m_GameDB, &m_KnightsAllianceArray, true);
}

bool CEbenezerDlg::LoadUserRankings()
{
	CUserPersonalRankSet UserPersonalRankSet(g_DBAgent.m_GameDB, &m_UserPersonalRankMap);
	CUserKnightsRankSet  UserKnightsRankSet(g_DBAgent.m_GameDB, &m_UserKnightsRankMap);
	TCHAR * szError = NULL;

	// Cleanup first, in the event it's already loaded (we'll have this automatically reload in-game)
	CleanupUserRankings();

	// Acquire the lock for thread safety, and load both tables.
	FastGuard lock(m_userRankingsLock);

	szError = UserPersonalRankSet.Read(true);
	if (szError != NULL)
	{
		TRACE("Failed to load personal rankings, error: %s\n", szError);
		return false;
	}

	szError = UserKnightsRankSet.Read(true);
	if (szError != NULL)
	{
		TRACE("Failed to load user knights rankings, error: %s\n", szError);
		return false;
	}

	return true;
}

void CEbenezerDlg::CleanupUserRankings()
{
	std::set<_USER_RANK *> deleteSet;
	FastGuard lock(m_userRankingsLock);

	// Go through the personal rank map, reset the character's rank and insert
	// the _USER_RANK struct instance into the deletion set for later.
	foreach (itr, m_UserPersonalRankMap)
	{
		CUser *pUser = GetUserPtr(itr->first, TYPE_CHARACTER);
		if (pUser != NULL)
			pUser->m_bPersonalRank = -1;

		deleteSet.insert(itr->second);
	}

	// Go through the knights rank map, reset the character's rank and insert
	// the _USER_RANK struct instance into the deletion set for later.
	foreach (itr, m_UserKnightsRankMap)
	{
		CUser *pUser = GetUserPtr(itr->first, TYPE_CHARACTER);
		if (pUser != NULL)
			pUser->m_bKnightsRank = -1;

		deleteSet.insert(itr->second);
	}

	// Clear out the maps
	m_UserPersonalRankMap.clear();
	m_UserKnightsRankMap.clear();

	// Free the memory used by the _USER_RANK structs
	foreach (itr, deleteSet)
		delete *itr;
}

bool CEbenezerDlg::LoadKnightsCapeTable()
{
	LOAD_TABLE(CKnightsCapeSet, g_DBAgent.m_GameDB, &m_KnightsCapeArray, false);
}

bool CEbenezerDlg::LoadKnightsRankTable()
{
	std::string strKarusCaptainNames, strElmoCaptainNames;
	LOAD_TABLE_ERROR_ONLY(CKnightsRankSet, g_DBAgent.m_GameDB, NULL, true);

	CKnightsRankSet & pSet = _CKnightsRankSet; // kind ugly generic naming

	if (pSet.nKarusCount > 0)
	{
		Packet result(WIZ_CHAT, uint8(WAR_SYSTEM_CHAT));
		GetServerResource(IDS_KARUS_CAPTAIN, &strKarusCaptainNames, 
			pSet.strKarusCaptain[0], pSet.strKarusCaptain[1], pSet.strKarusCaptain[2], 
			pSet.strKarusCaptain[3], pSet.strKarusCaptain[4]);

		result << int8(1) << int16(-1) << int8(0) << strKarusCaptainNames;
		Send_All(&result, NULL, KARUS);
	}

	if (pSet.nElmoCount > 0)
	{
		Packet result(WIZ_CHAT, uint8(WAR_SYSTEM_CHAT));
		GetServerResource(IDS_ELMO_CAPTAIN, &strElmoCaptainNames,
			pSet.strElmoCaptain[0], pSet.strElmoCaptain[1], pSet.strElmoCaptain[2], 
			pSet.strElmoCaptain[3], pSet.strElmoCaptain[4]);

		result << int8(1) << int16(-1) << int8(0) << strElmoCaptainNames;
		Send_All(&result, NULL, ELMORAD);
	}

	return true;
}

bool CEbenezerDlg::LoadHomeTable()
{
	LOAD_TABLE(CHomeSet, g_DBAgent.m_GameDB, &m_HomeArray, false);
}

bool CEbenezerDlg::LoadStartPositionTable()
{
	LOAD_TABLE(CStartPositionSet, g_DBAgent.m_GameDB, &m_StartPositionArray, false);
}

bool CEbenezerDlg::LoadBattleTable()
{
	LOAD_TABLE(CBattleSet, g_DBAgent.m_GameDB, &m_byOldVictory, true);
}

bool CEbenezerDlg::MapFileLoad()
{
	ZoneInfoMap zoneMap;
	LOAD_TABLE_ERROR_ONLY(CZoneInfoSet, g_DBAgent.m_GameDB, &zoneMap, false); 

	foreach (itr, zoneMap)
	{
		C3DMap *pMap = new C3DMap();
		_ZONE_INFO *pZone = itr->second;
		if (!pMap->Initialize(pZone))
		{
			printf("ERROR: Unable to load SMD - %s\n", pZone->m_MapName.c_str());
			delete pZone;
			delete pMap;
			m_ZoneArray.DeleteAllData();
			return false;
		}

		delete pZone;
		m_ZoneArray.PutData(pMap->m_nZoneNumber, pMap);
	}

	LOAD_TABLE_ERROR_ONLY(CEventSet, g_DBAgent.m_GameDB, &m_ZoneArray, true);
	return true;
}
