﻿#include <iostream>
#include <time.h>
#include <string>
#include "gtest\gtest.h"
#include "ace/Log_Msg.h"
#include "ace/mytrace.h"
#include  "ace/Refcounted_Auto_Ptr.h"
#include "ace/Auto_Ptr.h"
#include "common/ace_object_pool.h"
#include "ace/ACE.h"
#define ACE_NTRACE 1

int main(int argc, char* argv[ ])
{
	/*
	std::ofstream os(( std::string(argv[0]) + ".log" ).c_str());
	My_Log_Msg_Callback lmc;
	ACE_Log_Msg_Callback *oldcallback = ACE_LOG_MSG->msg_callback(&lmc);
	lmc.oldcallback(oldcallback);
	My_Log_Msg_Backend lmb;     /// ACE_Log_Msg::CUSTOM
	ACE_Log_Msg_Backend *oldbackend = ACE_LOG_MSG->msg_backend(&lmb);
	lmb.oldbackend(oldbackend);
	ACE_LOG_MSG->open(prog_name,
	ACE_Log_Msg::STDERR | ACE_Log_Msg::OSTREAM
	| ACE_Log_Msg::MSG_CALLBACK | ACE_Log_Msg::CUSTOM,
	logger_key);
	*/

	std::ofstream os("kbe.log");
	ACE_LOG_MSG->msg_ostream(&os, 0);
	ACE_LOG_MSG->open("kbengine tests", ACE_Log_Msg::STDERR | ACE_Log_Msg::OSTREAM);
	TRACE("main");
	testing::InitGoogleTest(&argc, argv);
	TRACE_RETURN(RUN_ALL_TESTS());
}