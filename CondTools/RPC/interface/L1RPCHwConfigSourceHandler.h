#ifndef L1RPCHWCONFIGSOURCEHANDLER
#define L1RPCHWCONFIGSOURCEHANDLER

#include <vector>
#include <string>
#include <iostream>
#include <typeinfo>

#include "OnlineDB/Oracle/interface/Oracle.h"
#include "FWCore/Framework/interface/MakerMacros.h"
#include "CondCore/PopCon/interface/PopConSourceHandler.h"
//#include "CondCore/PopCon/interface/LogReader.h"
#include "FWCore/Framework/interface/ESHandle.h"
#include "FWCore/Framework/interface/Event.h"
#include "DataFormats/Common/interface/Handle.h"
#include "FWCore/Framework/interface/EventSetup.h"
#include "FWCore/ParameterSet/interface/ParameterSetfwd.h"

#include "CondFormats/RPCObjects/interface/L1RPCHwConfig.h"
#include "CondFormats/DataRecord/interface/L1RPCHwConfigRcd.h"

#include "CondCore/DBCommon/interface/SessionConfiguration.h"
#include "CondCore/DBCommon/interface/ConnectionConfiguration.h"
#include "CondCore/DBCommon/interface/CoralTransaction.h"
#include "CondCore/DBCommon/interface/DBSession.h"
#include "CondCore/DBCommon/interface/Connection.h"
#include "RelationalAccess/ITable.h"
#include "RelationalAccess/ISchema.h"
#include "RelationalAccess/IQuery.h"
#include "RelationalAccess/ICursor.h"
#include "CoralBase/AttributeList.h"
#include "CoralBase/Attribute.h"
#include "CoralBase/AttributeSpecification.h"

using namespace std;
using namespace oracle::occi;

namespace popcon
{
        class L1RPCHwConfigSourceHandler : public popcon::PopConSourceHandler<L1RPCHwConfig>
        {

                public:
    L1RPCHwConfigSourceHandler(const edm::ParameterSet& ps);
    ~L1RPCHwConfigSourceHandler();
    void getNewObjects();
    std::string id() const {return m_name;}
    void ConnectOnlineDB(string connect, string authPath);
    void DisconnectOnlineDB();
    void readHwConfig1();
    int Compare2Configs(Ref set1, L1RPCHwConfig* set2);

                private:
    L1RPCHwConfig * disabledDevs;
    Environment* env;
    Connection* conn;
    cond::DBSession * session;
    cond::Connection * connection ;
    cond::CoralTransaction * coralTr;
    std::string m_name;
    int m_dummy;
    int m_validate;
    std::vector<int> m_disableCrates;
    std::vector<int> m_disableTowers;
    std::string m_connect;
    std::string m_authpath;

        };
}
#endif
