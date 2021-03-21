//Find
#ifdef ENABLE_COSTUME_SYSTEM
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	1);
#else
	PyModule_AddIntConstant(poModule, "ENABLE_COSTUME_SYSTEM",	0);
#endif

///Add
#if defined(BL_ARROW_COUNT)
	PyModule_AddIntConstant(poModule, "BL_ARROW_COUNT", true);
#else
	PyModule_AddIntConstant(poModule, "BL_ARROW_COUNT", false);
#endif