/* -*- C++ -*- */

/****************************************************************************
** Copyright (c) 2001-2004 quickfixengine.org  All rights reserved.
**
** This file is part of the QuickFIX FIX Engine
**
** This file may be distributed under the terms of the quickfixengine.org
** license as defined by quickfixengine.org and appearing in the file
** LICENSE included in the packaging of this file.
**
** This file is provided AS IS with NO WARRANTY OF ANY KIND, INCLUDING THE
** WARRANTY OF DESIGN, MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.
**
** See http://www.quickfixengine.org/LICENSE for licensing information.
**
** Contact ask@quickfixengine.org if any conditions of this licensing are
** not clear to you.
**
****************************************************************************/

#include <CPPTest/TestSuite.h>
#include <CPPTest/TestDisplay.h>
#include "C++/test/AcceptorTestCase.h"
#include "C++/test/FieldConvertorsTestCase.h"
#include "C++/test/MessagesTestCase.h"
#include "C++/test/SessionTestCase.h"
#include "C++/test/SessionSettingsTestCase.h"
#include "C++/test/ParserTestCase.h"
#include "C++/test/SettingsTestCase.h"
#include "C++/test/MemoryStoreTestCase.h"
#include "C++/test/FileStoreTestCase.h"
#include "C++/test/MySQLStoreTestCase.h"
#include "C++/test/FileStoreFactoryTestCase.h"
#include "C++/test/UtcTimeStampTestCase.h"
#include "C++/test/UtcTimeOnlyTestCase.h"
#include "C++/test/SocketUtilitiesTestCase.h"
#include "C++/test/FileUtilitiesTestCase.h"
#include "C++/test/StringUtilitiesTestCase.h"
#include "C++/test/SessionIDTestCase.h"
#include "C++/test/DictionaryTestCase.h"
#include "C++/test/DataDictionaryTestCase.h"
#include "C++/test/SocketConnectorTestCase.h"
#include "C++/test/SocketServerTestCase.h"
#include "C++/test/FieldBaseTestCase.h"

class TestSuite : public CPPTest::TestSuite
{
public:
  TestSuite( CPPTest::TestDisplay& display, short port )
: CPPTest::TestSuite( display ),
  m_parser( port ),
  m_socketUtilities( port ), m_socketConnector( port ), 
  m_socketServer( port )
  {
    FIX::socket_init();
    add( &m_acceptor );
    add( &m_fieldConvertors );
    add( &m_message );
    add( &m_logonParse );
    add( &m_testRequestParse );
    add( &m_resendRequestParse );
    add( &m_rejectParse );
    add( &m_sequenceResetParse );
    add( &m_logoutParse );
    add( &m_newOrderSingleParse );
    add( &m_executionReportParse );
    add( &m_dontKnowTradeParse );
    add( &m_orderCancelReplaceRequestParse );
    add( &m_orderCancelRequestParse );
    add( &m_orderCancelRejectParse );
    add( &m_orderStatusRequestParse );
    add( &m_newOrderListParse );
    add( &m_massQuoteParse );
    add( &m_session );
    add( &m_parser );
    add( &m_settings );
    add( &m_sessionSettings );
    add( &m_memoryStore );
    add( &m_fileStore );
#ifdef HAVE_MYSQL
    add( &m_mySQLStore );
#endif
    add( &m_fileStoreFactory );
    add( &m_utcTimeStamp );
    add( &m_utcTimeOnly );
    add( &m_socketUtilities );
    add( &m_fileUtilities );
    add( &m_stringUtilities );
    add( &m_sessionID );
    add( &m_dictionary );
    add( &m_dataDictionary );
    add( &m_socketConnector );
    add( &m_socketServer );
    add( &m_fieldBase );
  }

  ~TestSuite() { FIX::socket_term(); }

private:

  FIX::AcceptorTestCase m_acceptor;
  FIX::FieldConvertorsTestCase m_fieldConvertors;
  FIX::MessageTestCase m_message;
  FIX::LogonParseTestCase m_logonParse;
  FIX::TestRequestParseTestCase m_testRequestParse;
  FIX::ResendRequestParseTestCase m_resendRequestParse;
  FIX::RejectParseTestCase m_rejectParse;
  FIX::SequenceResetParseTestCase m_sequenceResetParse;
  FIX::LogoutParseTestCase m_logoutParse;
  FIX::NewOrderSingleParseTestCase m_newOrderSingleParse;
  FIX::ExecutionReportParseTestCase m_executionReportParse;
  FIX::DontKnowTradeParseTestCase m_dontKnowTradeParse;
  FIX::OrderCancelReplaceRequestParseTestCase m_orderCancelReplaceRequestParse;
  FIX::OrderCancelRequestParseTestCase m_orderCancelRequestParse;
  FIX::OrderCancelRejectParseTestCase m_orderCancelRejectParse;
  FIX::OrderStatusRequestParseTestCase m_orderStatusRequestParse;
  FIX::NewOrderListParseTestCase m_newOrderListParse;
  FIX::MassQuoteParseTestCase m_massQuoteParse;
  FIX::SessionTestCase m_session;
  FIX::ParserTestCase m_parser;
  FIX::SettingsTestCase m_settings;
  FIX::SessionSettingsTestCase m_sessionSettings;
  FIX::MemoryStoreTestCase m_memoryStore;
  FIX::FileStoreTestCase m_fileStore;
#ifdef HAVE_MYSQL
  FIX::MySQLStoreTestCase m_mySQLStore;
#endif
  FIX::FileStoreFactoryTestCase m_fileStoreFactory;
  FIX::UtcTimeStampTestCase m_utcTimeStamp;
  FIX::UtcTimeOnlyTestCase m_utcTimeOnly;
  FIX::SocketUtilitiesTestCase m_socketUtilities;
  FIX::FileUtilitiesTestCase m_fileUtilities;
  FIX::StringUtilitiesTestCase m_stringUtilities;
  FIX::SocketConnectorTestCase m_socketConnector;
  FIX::SocketServerTestCase m_socketServer;
  FIX::SessionIDTestCase m_sessionID;
  FIX::DictionaryTestCase m_dictionary;
  FIX::DataDictionaryTestCase m_dataDictionary;
  FIX::FieldBaseTestCase m_fieldBase;
};