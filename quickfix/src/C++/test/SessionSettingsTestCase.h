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

#ifndef FIX_SESSIONSETTINGSTESTCASE_H
#define FIX_SESSIONSETTINGSTESTCASE_H

#include <CPPTest/TestCase.h>
#include "SessionSettings.h"

namespace FIX
{
class SessionSettingsTestCase : public CPPTest::TestCase < SessionSettings >
{
public:
  SessionSettingsTestCase()
  {
    add( &m_readFromIstream );
  }

private:
  typedef CPPTest::SimpleTest < SessionSettings > Test;

class readFromIstream : public Test
  {
  public:
    readFromIstream() {}
    void onRun( SessionSettings& object );
  }
  m_readFromIstream;
};
}

#endif //FIX_SESSIONSETTINGSTESTCASE_H