///Add
#if defined(BL_ARROW_COUNT)
PyObject* playerGetArrowStatus(PyObject* poSelf, PyObject* poArgs)
{
	const auto player = CPythonPlayer::InstancePtr();

	if (player && RaceToJob(CPythonPlayer::Instance().GetRace()) == NRaceData::JOB_ASSASSIN)
	{
		const auto Weapon = player->GetItemData(TItemPos(EQUIPMENT, c_Equipment_Weapon));
		if (Weapon && Weapon->vnum)
		{
			CItemData* pItemData = nullptr;
			if (CItemManager::Instance().GetItemDataPointer(Weapon->vnum, &pItemData))
			{
				if (pItemData->GetType() == CItemData::EItemType::ITEM_TYPE_WEAPON)
				{
					if (pItemData->GetSubType() == CItemData::EWeaponSubTypes::WEAPON_BOW)
					{
						// Count, Total(same vnum)
						// Same Vnum? : When the arrow ends, if there is the same arrow in inventory, it will be equipped automatically.
						const auto Arrow = player->GetItemData(TItemPos(EQUIPMENT, c_Equipment_Arrow));
						if (Arrow)
							return Py_BuildValue("ii", Arrow->count, Arrow->vnum ? player->GetItemCountByVnum(Arrow->vnum) : 0);
					}
#if defined(ENABLE_QUIVER_SYSTEM)
					else if (pItemData->GetSubType() == CItemData::EWeaponSubTypes::WEAPON_QUIVER)
						return Py_BuildValue("ii", -2, 0); // unlimited
#endif
				}
			}
		}
	}

	return Py_BuildValue("ii", -1, 0); // no bow: hide
}
#endif

//Find
		{ "SendDragonSoulRefine",		playerSendDragonSoulRefine,			METH_VARARGS },
		
///Add
#if defined(BL_ARROW_COUNT)
		{ "GetArrowStatus",				playerGetArrowStatus,				METH_VARARGS },
#endif